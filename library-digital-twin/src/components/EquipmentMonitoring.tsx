import React from 'react';
import { Box, Typography, Paper } from '@mui/material';
import { styled } from '@mui/material/styles';
import ComputerIcon from '@mui/icons-material/Computer';
import PrintIcon from '@mui/icons-material/Print';
import ScannerIcon from '@mui/icons-material/Scanner';

const defaultEquipmentData = [
  { id: 1, name: '电脑', type: 'computer', status: 'available', usage: 65 },
  { id: 2, name: '打印机', type: 'printer', status: 'in_use', usage: 80 },
  { id: 3, name: '扫描仪', type: 'scanner', status: 'maintenance', usage: 0 },
];

const EquipmentCard = styled(Paper)(({ theme }) => ({
  padding: theme.spacing(2),
  display: 'flex',
  alignItems: 'center',
  gap: theme.spacing(2),
}));

const ContentContainer = styled(Box)({
  flex: 1,
});

const IconContainer = styled(Box)(({ theme }) => ({
  display: 'flex',
  alignItems: 'center',
  justifyContent: 'center',
  width: 48,
  height: 48,
  borderRadius: '50%',
  backgroundColor: theme.palette.primary.main,
  color: theme.palette.primary.contrastText,
}));

const StatsContainer = styled(Box)({
  display: 'flex',
  justifyContent: 'space-between',
  alignItems: 'center',
  marginTop: 8,
});

const StatusText = styled(Typography)<{ status: string }>(({ theme, status }) => ({
  color: status === 'available' 
    ? theme.palette.success.main 
    : status === 'in_use' 
    ? theme.palette.warning.main 
    : theme.palette.error.main,
}));

const UsageContainer = styled(Box)(({ theme }) => ({
  width: '100%',
  height: 4,
  backgroundColor: theme.palette.grey[200],
  borderRadius: 2,
  marginTop: 8,
  overflow: 'hidden',
  '&::after': {
    content: '""',
    display: 'block',
    height: '100%',
    backgroundColor: theme.palette.primary.main,
    width: 'var(--usage)',
  },
}));

const getEquipmentIcon = (type: string) => {
  switch (type) {
    case 'computer':
      return <ComputerIcon />;
    case 'printer':
      return <PrintIcon />;
    case 'scanner':
      return <ScannerIcon />;
    default:
      return <ComputerIcon />;
  }
};

const EquipmentMonitoring: React.FC = () => {
  return (
    <Box sx={{ display: 'grid', gap: 2, gridTemplateColumns: 'repeat(auto-fit, minmax(300px, 1fr))' }}>
      {defaultEquipmentData.map((equipment) => (
        <EquipmentCard key={equipment.id}>
          <IconContainer>
            {getEquipmentIcon(equipment.type)}
          </IconContainer>
          <ContentContainer>
            <Typography variant="h6">{equipment.name}</Typography>
            <StatsContainer>
              <StatusText variant="body2" status={equipment.status}>
                {equipment.status === 'available' 
                  ? '可用' 
                  : equipment.status === 'in_use' 
                  ? '使用中' 
                  : '维护中'}
              </StatusText>
              <Typography variant="body2" color="text.secondary">
                使用率: {equipment.usage}%
              </Typography>
            </StatsContainer>
            <UsageContainer style={{ '--usage': `${equipment.usage}%` } as React.CSSProperties} />
          </ContentContainer>
        </EquipmentCard>
      ))}
    </Box>
  );
};

export default EquipmentMonitoring; 