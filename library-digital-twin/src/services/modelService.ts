import { modelConfig } from '../config/modelConfig';

export interface ModelState {
  connected: boolean;
  position: {
    x: number;
    y: number;
    z: number;
  };
  rotation: {
    x: number;
    y: number;
    z: number;
  };
  scale: {
    x: number;
    y: number;
    z: number;
  };
}

export interface ModelCommand {
  type: string;
  data: any;
}

export class ModelService {
  private socket: WebSocket | null = null;
  private modelState: ModelState = {
    connected: false,
    position: { x: 0, y: 0, z: 0 },
    rotation: { x: 0, y: 0, z: 0 },
    scale: { x: 1, y: 1, z: 1 }
  };
  private reconnectAttempts = 0;
  private readonly maxReconnectAttempts = 5;
  private readonly onStateUpdate: (state: ModelState) => void;

  constructor(onStateUpdate: (state: ModelState) => void) {
    this.onStateUpdate = onStateUpdate;
  }

  async connect(): Promise<void> {
    if (this.socket?.readyState === WebSocket.OPEN) {
      return;
    }

    return new Promise((resolve, reject) => {
      try {
        this.socket = new WebSocket(modelConfig.websocketUrl);

        this.socket.onopen = () => {
          console.log('Connected to WebSocket server');
          this.reconnectAttempts = 0;
          this.modelState.connected = true;
          this.onStateUpdate(this.modelState);
          resolve();
        };

        this.socket.onerror = (error) => {
          console.error('WebSocket error:', error);
          this.handleConnectionError(error);
          reject(error);
        };

        this.socket.onclose = () => {
          console.log('WebSocket connection closed');
          this.modelState.connected = false;
          this.onStateUpdate(this.modelState);
        };

        this.socket.onmessage = this.handleMessage.bind(this);
      } catch (error) {
        console.error('Error creating WebSocket connection:', error);
        reject(error);
      }
    });
  }

  private handleConnectionError(error: Event): void {
    console.error('Connection error:', error);
    this.reconnectAttempts++;
    
    if (this.reconnectAttempts >= this.maxReconnectAttempts) {
      console.error('Max reconnection attempts reached');
      this.disconnect();
    }
  }

  private handleMessage(event: MessageEvent): void {
    try {
      const data = JSON.parse(event.data);
      console.log('Received message:', data);

      if (data.type === 'state') {
        this.updateModelState(data.data);
      }
    } catch (error) {
      console.error('Error handling message:', error);
    }
  }

  private updateModelState(state: Partial<ModelState>): void {
    this.modelState = { ...this.modelState, ...state };
    this.onStateUpdate(this.modelState);
  }

  async sendCommand(command: ModelCommand): Promise<void> {
    if (!this.socket || this.socket.readyState !== WebSocket.OPEN) {
      throw new Error('Not connected to WebSocket server');
    }

    return new Promise((resolve, reject) => {
      try {
        this.socket?.send(JSON.stringify(command));
        console.log('Command sent successfully:', command);
        resolve();
      } catch (error) {
        console.error('Error sending command:', error);
        reject(error);
      }
    });
  }

  disconnect(): void {
    if (this.socket) {
      this.socket.close();
      this.socket = null;
    }
    this.modelState.connected = false;
    this.onStateUpdate(this.modelState);
  }
} 