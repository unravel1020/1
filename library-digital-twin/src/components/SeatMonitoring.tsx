import React from 'react';
import { Box, Grid, Paper, Typography } from '@mui/material';
import { styled } from '@mui/material/styles';

const SeatGrid = styled(Grid)(({ theme }) => ({
  display: 'grid',
  gridTemplateColumns: 'repeat(auto-fill, minmax(120px, 1fr))',
  gap: theme.spacing(1.5),
  padding: theme.spacing(1.5),
}));

const Seat = styled(Paper)<{ status: 'available' | 'occupied' | 'reserved' }>(
  ({ theme, status }) => ({
    padding: theme.spacing(1.5),
    textAlign: 'center',
    cursor: 'pointer',
    transition: 'all 0.3s ease',
    background: status === 'available'
      ? 'linear-gradient(145deg, rgba(102, 187, 106, 0.15) 0%, rgba(102, 187, 106, 0.08) 100%)'
      : status === 'occupied'
      ? 'linear-gradient(145deg, rgba(244, 67, 54, 0.15) 0%, rgba(244, 67, 54, 0.08) 100%)'
      : 'linear-gradient(145deg, rgba(255, 167, 38, 0.15) 0%, rgba(255, 167, 38, 0.08) 100%)',
    border: `1px solid ${
      status === 'available'
        ? 'rgba(102, 187, 106, 0.3)'
        : status === 'occupied'
        ? 'rgba(244, 67, 54, 0.3)'
        : 'rgba(255, 167, 38, 0.3)'
    }`,
    '&:hover': {
      transform: 'translateY(-2px)',
      boxShadow: theme.shadows[8],
      background: status === 'available'
        ? 'linear-gradient(145deg, rgba(102, 187, 106, 0.25) 0%, rgba(102, 187, 106, 0.15) 100%)'
        : status === 'occupied'
        ? 'linear-gradient(145deg, rgba(244, 67, 54, 0.25) 0%, rgba(244, 67, 54, 0.15) 100%)'
        : 'linear-gradient(145deg, rgba(255, 167, 38, 0.25) 0%, rgba(255, 167, 38, 0.15) 100%)',
    },
  })
);

const StatCard = styled(Paper)(({ theme }) => ({
  padding: theme.spacing(2),
  textAlign: 'center',
  background: 'linear-gradient(145deg, rgba(255, 255, 255, 0.08) 0%, rgba(255, 255, 255, 0.04) 100%)',
  backdropFilter: 'blur(10px)',
  border: '1px solid rgba(255, 255, 255, 0.08)',
  transition: 'all 0.3s ease',
  '&:hover': {
    transform: 'translateY(-2px)',
    boxShadow: theme.shadows[8],
    background: 'linear-gradient(145deg, rgba(255, 255, 255, 0.12) 0%, rgba(255, 255, 255, 0.06) 100%)',
  },
}));

const SeatMonitoring: React.FC = () => {
  // Mock data for seats
  const seats = Array.from({ length: 50 }, (_, i) => ({
    id: i + 1,
    status: ['available', 'occupied', 'reserved'][Math.floor(Math.random() * 3)] as
      | 'available'
      | 'occupied'
      | 'reserved',
  }));

  const availableCount = seats.filter((seat) => seat.status === 'available').length;
  const occupiedCount = seats.filter((seat) => seat.status === 'occupied').length;
  const reservedCount = seats.filter((seat) => seat.status === 'reserved').length;

  return (
    <Box sx={{ height: '100%', display: 'flex', flexDirection: 'column' }}>
      <Box sx={{ mb: 3, display: 'flex', gap: 2 }}>
        <StatCard sx={{ flex: 1, borderColor: 'success.main' }}>
          <Typography variant="body2" color="success.main" gutterBottom>
            可用座位
          </Typography>
          <Typography variant="h4" color="success.main">
            {availableCount}
          </Typography>
        </StatCard>
        <StatCard sx={{ flex: 1, borderColor: 'error.main' }}>
          <Typography variant="body2" color="error.main" gutterBottom>
            已占用
          </Typography>
          <Typography variant="h4" color="error.main">
            {occupiedCount}
          </Typography>
        </StatCard>
        <StatCard sx={{ flex: 1, borderColor: 'warning.main' }}>
          <Typography variant="body2" color="warning.main" gutterBottom>
            已预约
          </Typography>
          <Typography variant="h4" color="warning.main">
            {reservedCount}
          </Typography>
        </StatCard>
      </Box>
      <SeatGrid>
        {seats.map((seat) => (
          <Seat key={seat.id} status={seat.status} elevation={0}>
            <Typography variant="body2" sx={{ fontWeight: 500 }}>
              座位 {seat.id}
            </Typography>
            <Typography
              variant="caption"
              sx={{
                display: 'block',
                mt: 0.5,
                color:
                  seat.status === 'available'
                    ? 'success.main'
                    : seat.status === 'occupied'
                    ? 'error.main'
                    : 'warning.main',
              }}
            >
              {seat.status === 'available'
                ? '可用'
                : seat.status === 'occupied'
                ? '已占用'
                : '已预约'}
            </Typography>
          </Seat>
        ))}
      </SeatGrid>
    </Box>
  );
};

export default SeatMonitoring; 