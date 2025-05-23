export interface ModelConfig {
  websocketUrl: string;
}

export const modelConfig: ModelConfig = {
  websocketUrl: 'ws://localhost:8080/websocket'
};

export default modelConfig; 