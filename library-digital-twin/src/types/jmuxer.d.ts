declare class JMuxer {
  constructor(options: {
    node: string | HTMLElement;
    mode?: string;
    debug?: boolean;
    flushingTime?: number;
    clearBuffer?: boolean;
    fps?: number;
    onReady?: () => void;
    onError?: (data: any) => void;
  });

  feed(data: {
    video?: Uint8Array;
    audio?: Uint8Array;
    duration?: number;
  }): void;

  destroy(): void;
}

declare module 'jmuxer' {
  export = JMuxer;
} 