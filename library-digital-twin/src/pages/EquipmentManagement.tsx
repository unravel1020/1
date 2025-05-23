import React from 'react';
import { Box, Typography } from '@mui/material';
import { styled } from '@mui/material/styles';
import EquipmentMonitoring from '../components/EquipmentMonitoring';

const Container = styled(Box)(({ theme }) => ({
  display: 'flex',
  flexDirection: 'column',
  gap: theme.spacing(3),
}));

const EquipmentManagement: React.FC = () => {
  return (
    <Container>
      <Typography variant="h4" gutterBottom>
        设备管理
      </Typography>
      <EquipmentMonitoring />
    </Container>
  );
};

export default EquipmentManagement; 