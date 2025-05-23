import React from 'react';
import { Box, Typography } from '@mui/material';
import { styled } from '@mui/material/styles';
import SeatMonitoring from '../components/SeatMonitoring';

const Container = styled(Box)(({ theme }) => ({
  display: 'flex',
  flexDirection: 'column',
  gap: theme.spacing(3),
}));

const SeatManagement: React.FC = () => {
  return (
    <Container>
      <Typography variant="h4" gutterBottom>
        座位管理
      </Typography>
      <SeatMonitoring />
    </Container>
  );
};

export default SeatManagement; 