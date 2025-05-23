import React, { useEffect, useRef, useState } from 'react';
import { Box, Typography, Paper, Button, Stack } from '@mui/material';
import { styled } from '@mui/material/styles';
import JMuxer from 'jmuxer';

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

const Library3DView: React.FC = () => {
  const videoRef = useRef<HTMLVideoElement>(null);
  const [wsControl, setWsControl] = useState<WebSocket | null>(null);
  const [isConnected, setIsConnected] = useState(false);
  const [error, setError] = useState<string | null>(null);
  const jmuxerRef = useRef<JMuxer | null>(null);
  const wsRef = useRef<WebSocket | null>(null);
  const wsControlRef = useRef<WebSocket | null>(null);
  const reconnectTimeoutRef = useRef<NodeJS.Timeout | null>(null);
  const controlReconnectTimeoutRef = useRef<NodeJS.Timeout | null>(null);
  const isComponentMounted = useRef(true);
  const isControlConnecting = useRef(false);
  const controlConnectionAttempts = useRef(0);
  const initialConnectionTimeoutRef = useRef<NodeJS.Timeout | null>(null);

  const connectWebSocket = () => {
    if (wsRef.current?.readyState === WebSocket.OPEN) {
      return;
    }

    console.log('Attempting to connect to video WebSocket...');
    try {
      const ws = new WebSocket('ws://127.0.0.1:8882/');
      ws.binaryType = 'arraybuffer';
      wsRef.current = ws;

      ws.onopen = () => {
        if (!isComponentMounted.current) {
          ws.close();
          return;
        }
        console.log('Video WebSocket connected successfully');
        setIsConnected(true);
        setError(null);
        // Setup JMuxer
        if (!jmuxerRef.current && videoRef.current) {
          console.log('Initializing JMuxer...');
          jmuxerRef.current = new JMuxer({
            node: videoRef.current,
            mode: 'video',
            flushingTime: 0,
            fps: 60,
            debug: true,
            onReady: () => {
              console.log('JMuxer is ready');
            },
            onError: function (data: any) {
              console.error('JMuxer error:', data);
              if (/Safari/.test(navigator.userAgent) && /Apple Computer/.test(navigator.vendor)) {
                console.log('Reinitializing JMuxer for Safari...');
                jmuxerRef.current?.destroy();
                jmuxerRef.current = new JMuxer({
                  node: videoRef.current!,
                  mode: 'video',
                  flushingTime: 0,
                  fps: 60,
                  debug: true
                });
              }
            }
          });
        }
      };

      ws.onerror = (evt) => {
        console.error('Video WebSocket error:', evt);
        if (isComponentMounted.current) {
          setError('视频WebSocket连接发生错误');
          setIsConnected(false);
        }
      };

      ws.onclose = (event) => {
        console.log('Video WebSocket closed with code:', event.code, 'reason:', event.reason);
        if (isComponentMounted.current) {
          setIsConnected(false);
          // Attempt to reconnect after 2 seconds
          if (reconnectTimeoutRef.current) {
            clearTimeout(reconnectTimeoutRef.current);
          }
          reconnectTimeoutRef.current = setTimeout(connectWebSocket, 2000);
        }
      };

      ws.onmessage = (event) => {
        if (jmuxerRef.current && isComponentMounted.current) {
          jmuxerRef.current.feed({ video: new Uint8Array(event.data) });
        }
      };
    } catch (error) {
      console.error('Error creating video WebSocket:', error);
      if (isComponentMounted.current) {
        reconnectTimeoutRef.current = setTimeout(connectWebSocket, 2000);
      }
    }
  };

  const connectControlWebSocket = () => {
    if (wsControlRef.current?.readyState === WebSocket.OPEN || isControlConnecting.current) {
      return;
    }

    // Limit reconnection attempts
    if (controlConnectionAttempts.current >= 5) {
      console.log('Maximum control WebSocket connection attempts reached');
      return;
    }

    console.log('Attempting to connect to control WebSocket...');
    try {
      isControlConnecting.current = true;
      controlConnectionAttempts.current++;
      
      const ws2 = new WebSocket('ws://127.0.0.1:9658/');
      wsControlRef.current = ws2;
      setWsControl(ws2);

      ws2.onopen = () => {
        if (isComponentMounted.current) {
          console.log('Control WebSocket connected successfully');
          isControlConnecting.current = false;
          controlConnectionAttempts.current = 0; // Reset attempts on successful connection
        } else {
          ws2.close();
        }
      };

      ws2.onerror = (evt) => {
        console.error('Control WebSocket error:', evt);
        if (isComponentMounted.current) {
          setError('控制WebSocket连接发生错误');
          isControlConnecting.current = false;
        }
      };

      ws2.onclose = (event) => {
        console.log('Control WebSocket closed with code:', event.code, 'reason:', event.reason);
        if (isComponentMounted.current) {
          isControlConnecting.current = false;
          if (controlReconnectTimeoutRef.current) {
            clearTimeout(controlReconnectTimeoutRef.current);
          }
          // Only attempt to reconnect if we haven't exceeded the maximum attempts
          if (controlConnectionAttempts.current < 5) {
            controlReconnectTimeoutRef.current = setTimeout(connectControlWebSocket, 2000);
          }
        }
      };

      // Add message handler to keep connection alive
      ws2.onmessage = (event) => {
        console.log('Control WebSocket message received:', event.data);
      };
    } catch (error) {
      console.error('Error creating control WebSocket:', error);
      if (isComponentMounted.current) {
        isControlConnecting.current = false;
        if (controlReconnectTimeoutRef.current) {
          clearTimeout(controlReconnectTimeoutRef.current);
        }
        if (controlConnectionAttempts.current < 5) {
          controlReconnectTimeoutRef.current = setTimeout(connectControlWebSocket, 2000);
        }
      }
    }
  };

  useEffect(() => {
    isComponentMounted.current = true;
    
    // Add a delay before initial connection to handle React Strict Mode
    initialConnectionTimeoutRef.current = setTimeout(() => {
      if (isComponentMounted.current) {
        connectWebSocket();
        connectControlWebSocket();
      }
    }, 1000);

    return () => {
      console.log('Cleaning up WebSocket connections...');
      isComponentMounted.current = false;
      
      if (initialConnectionTimeoutRef.current) {
        clearTimeout(initialConnectionTimeoutRef.current);
      }
      if (reconnectTimeoutRef.current) {
        clearTimeout(reconnectTimeoutRef.current);
      }
      if (controlReconnectTimeoutRef.current) {
        clearTimeout(controlReconnectTimeoutRef.current);
      }
      if (wsRef.current) {
        wsRef.current.close();
      }
      if (wsControlRef.current) {
        wsControlRef.current.close();
      }
      if (jmuxerRef.current) {
        jmuxerRef.current.destroy();
        jmuxerRef.current = null;
      }
    };
  }, []);

  // Example control commands
  const sendLibraryCommand = (library: string) => {
    if (wsControl && wsControl.readyState === WebSocket.OPEN) {
      let json = { key: library, value: library === 'reset' ? 'reset' : (library === '图书馆1' ? '115415' : library === '图书馆2' ? '2025' : library === '图书馆3' ? '8848' : '') };
      console.log('Sending control command:', json);
      wsControl.send(JSON.stringify(json));
    } else {
      console.warn('Control WebSocket is not connected');
    }
  };

  const sendReset = () => sendLibraryCommand('reset');

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
        <Button variant="outlined" color="secondary" onClick={sendReset}>重置</Button>
      </Stack>
      <ModelContainer>
        {error ? (
          <Typography color="error">{error}</Typography>
        ) : !isConnected ? (
          <Typography>正在连接3D模型视频流服务...</Typography>
        ) : (
          <Video ref={videoRef} autoPlay muted playsInline />
        )}
      </ModelContainer>
    </Container>
  );
};

export default Library3DView; 