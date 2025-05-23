import React from 'react';
import { Box, Typography, Paper } from '@mui/material';
import { styled } from '@mui/material/styles';
import SeatMonitoring from './SeatMonitoring';
import EquipmentMonitoring from './EquipmentMonitoring';

const Container = styled(Box)(({ theme }) => ({
  display: 'flex',
  flexDirection: 'column',
  gap: theme.spacing(2),
  padding: theme.spacing(2),
  height: 'calc(100vh - 100px)', // Account for header and padding
  overflow: 'auto',
}));

const Dashboard: React.FC = () => {
  return (
    <Container>
      <Typography variant="h4" gutterBottom>
        图书馆数字孪生系统
      </Typography>
      <Box sx={{ 
        display: 'grid', 
        gap: 2, 
        gridTemplateColumns: 'repeat(auto-fit, minmax(400px, 1fr))',
        height: '100%',
        '& > *': {
          height: '100%',
          overflow: 'auto',
        }
      }}>
        <Paper elevation={3} sx={{ p: 2 }}>
          <Typography variant="h6" gutterBottom>
            座位监控
          </Typography>
          <SeatMonitoring />
        </Paper>
        <Paper elevation={3} sx={{ p: 2 }}>
          <Typography variant="h6" gutterBottom>
            设备监控
          </Typography>
          <EquipmentMonitoring />
        </Paper>
      </Box>
    </Container>
  );
};

export default Dashboard;