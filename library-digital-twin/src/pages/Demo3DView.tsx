import React, { useEffect, useRef, useState } from 'react';
import { Box, Typography, Paper, Button, Stack } from '@mui/material';
import { styled } from '@mui/material/styles';

const Container = styled(Box)(({ theme }) => ({
  display: 'flex',
  flexDirection: 'column',
  gap: theme.spacing(2),
  padding: theme.spacing(2),
  height: 'calc(100vh - 100px)',
  overflow: 'auto',
}));

const ModelContainer = styled(Paper)(({ theme }) => ({
  flex: 1,
  display: 'flex',
  alignItems: 'center',
  justifyContent: 'center',
  background: 'linear-gradient(145deg, rgba(255, 255, 255, 0.08) 0%, rgba(255, 255, 255, 0.04) 100%)',
  border: '1px solid rgba(255, 255, 255, 0.08)',
  borderRadius: theme.shape.borderRadius,
  position: 'relative',
}));

const Video = styled('video')({
  width: '100%',
  height: '100%',
  background: '#000',
});

const Demo3DView: React.FC = () => {
  const videoRef = useRef<HTMLVideoElement>(null);
  const wsRef = useRef<WebSocket | null>(null);
  const wsControlRef = useRef<WebSocket | null>(null);
  const jmuxerRef = useRef<any>(null);
  const [error, setError] = useState<string | null>(null);
  const reconnectTimeoutRef = useRef<NodeJS.Timeout | null>(null);
  const heartbeatIntervalRef = useRef<NodeJS.Timeout | null>(null);
  const isComponentMounted = useRef(true);

  const connectControlWebSocket = () => {
    if (wsControlRef.current?.readyState === WebSocket.OPEN) {
      return;
    }

    try {
      wsControlRef.current = new WebSocket("ws://127.0.0.1:9658/");
      
      wsControlRef.current.onopen = function () {
        console.log("Control WebSocket连接成功!");
        setError(null);
        
        // Start heartbeat
        if (heartbeatIntervalRef.current) {
          clearInterval(heartbeatIntervalRef.current);
        }
        heartbeatIntervalRef.current = setInterval(() => {
          if (wsControlRef.current?.readyState === WebSocket.OPEN) {
            wsControlRef.current.send(JSON.stringify({ type: 'heartbeat' }));
          }
        }, 30000); // Send heartbeat every 30 seconds
      };

      wsControlRef.current.onerror = function (evt) {
        console.error('Control WebSocket连接发生错误: ', evt);
        if (isComponentMounted.current) {
          setError('控制WebSocket连接发生错误');
        }
      };

      wsControlRef.current.onclose = function (event) {
        console.log("Control WebSocket已关闭!", event.code, event.reason);
        if (heartbeatIntervalRef.current) {
          clearInterval(heartbeatIntervalRef.current);
        }
        
        // Attempt to reconnect after 2 seconds
        if (isComponentMounted.current) {
          if (reconnectTimeoutRef.current) {
            clearTimeout(reconnectTimeoutRef.current);
          }
          reconnectTimeoutRef.current = setTimeout(connectControlWebSocket, 2000);
        }
      };

      wsControlRef.current.onmessage = (event) => {
        console.log('Control WebSocket message received:', event.data);
      };
    } catch (error) {
      console.error('Error creating control WebSocket:', error);
      if (isComponentMounted.current) {
        setError('创建控制WebSocket连接失败');
        // Attempt to reconnect after 2 seconds
        if (reconnectTimeoutRef.current) {
          clearTimeout(reconnectTimeoutRef.current);
        }
        reconnectTimeoutRef.current = setTimeout(connectControlWebSocket, 2000);
      }
    }
  };

  useEffect(() => {
    isComponentMounted.current = true;

    const loadScript = (src: string): Promise<void> => {
      return new Promise((resolve, reject) => {
        if (document.querySelector(`script[src="${src}"]`)) {
          resolve();
          return;
        }

        const script = document.createElement('script');
        script.src = src;
        script.async = true;
        script.onload = () => resolve();
        script.onerror = (e) => reject(new Error(`Failed to load script: ${src}`));
        document.body.appendChild(script);
      });
    };

    const initializeDemo = async () => {
      try {
        await loadScript('/js/jquery-3.6.1.min.js');
        console.log('jQuery loaded successfully');

        await loadScript('/js/conver.min.js');
        console.log('JMuxer loaded successfully');

        if (!isComponentMounted.current) return;

        if (videoRef.current && window.JMuxer) {
          jmuxerRef.current = new window.JMuxer({
            node: videoRef.current,
            mode: 'video',
            flushingTime: 0,
            fps: 60,
            debug: false,
            onError: function (data: any) {
              console.error('JMuxer error:', data);
              if (/Safari/.test(navigator.userAgent) && /Apple Computer/.test(navigator.vendor)) {
                jmuxerRef.current?.reset();
              }
            }
          });
          console.log('JMuxer initialized successfully');
        }

        // Connect to video WebSocket
        wsRef.current = new WebSocket('ws://127.0.0.1:8882/');
        wsRef.current.binaryType = 'arraybuffer';

        wsRef.current.onopen = () => {
          console.log('Video WebSocket 连接已建立');
        };

        wsRef.current.onmessage = (event) => {
          if (jmuxerRef.current) {
            jmuxerRef.current.feed({
              video: new Uint8Array(event.data)
            });
          }
        };

        wsRef.current.onerror = (event) => {
          console.error('Video WebSocket连接发生错误', event);
          if (isComponentMounted.current) {
            setError('视频WebSocket连接发生错误');
          }
        };

        wsRef.current.onclose = (event) => {
          console.log('Video WebSocket连接已经关闭', event);
        };

        // Connect to control WebSocket
        connectControlWebSocket();

      } catch (error) {
        console.error('Error initializing demo:', error);
        if (isComponentMounted.current) {
          setError(`初始化失败: ${error instanceof Error ? error.message : String(error)}`);
        }
      }
    };

    initializeDemo();

    return () => {
      isComponentMounted.current = false;
      
      if (reconnectTimeoutRef.current) {
        clearTimeout(reconnectTimeoutRef.current);
      }
      
      if (heartbeatIntervalRef.current) {
        clearInterval(heartbeatIntervalRef.current);
      }
      
      if (wsRef.current) {
        wsRef.current.close();
      }
      
      if (wsControlRef.current) {
        wsControlRef.current.close();
      }
      
      if (jmuxerRef.current) {
        jmuxerRef.current.destroy();
      }
    };
  }, []);

  const sendLibraryCommand = (library: string) => {
    if (wsControlRef.current?.readyState === WebSocket.OPEN) {
      let json = { 
        key: library, 
        value: library === 'reset' ? 'reset' : 
               library === '图书馆1' ? '115415' : 
               library === '图书馆2' ? '2025' : 
               library === '图书馆3' ? '8848' : '' 
      };
      console.log('Sending control command:', json);
      wsControlRef.current.send(JSON.stringify(json));
    } else {
      console.warn('Control WebSocket is not connected');
      setError('控制WebSocket未连接，正在尝试重新连接...');
      connectControlWebSocket();
    }
  };

  return (
    <Container>
      <Typography variant="h4" gutterBottom>
        图书馆3D模型
      </Typography>
      <Stack direction="row" spacing={2} mb={2}>
        <Button variant="contained" onClick={() => sendLibraryCommand('图书馆1')}>临潼图书馆</Button>
        <Button variant="contained" onClick={() => sendLibraryCommand('图书馆2')}>金花图书馆</Button>
        <Button variant="contained" onClick={() => sendLibraryCommand('图书馆3')}>教学楼1</Button>
        <Button variant="contained" onClick={() => sendLibraryCommand('教学楼2')}>教学楼2</Button>
        <Button variant="outlined" color="secondary" onClick={() => sendLibraryCommand('reset')}>重置</Button>
      </Stack>
      <ModelContainer>
        {error ? (
          <Typography color="error">{error}</Typography>
        ) : (
          <Video ref={videoRef} autoPlay muted playsInline />
        )}
      </ModelContainer>
    </Container>
  );
};

// Add TypeScript declarations for the global functions
declare global {
  interface Window {
    JMuxer: any;
  }
}

export default Demo3DView; 