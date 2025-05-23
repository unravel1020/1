import React from 'react';
import { Box, Typography, Paper } from '@mui/material';
import { styled } from '@mui/material/styles';

const PlaceholderContainer = styled(Paper)(({ theme }) => ({
  height: '400px',
  display: 'flex',
  alignItems: 'center',
  justifyContent: 'center',
  backgroundColor: theme.palette.grey[100],
  position: 'relative',
  overflow: 'hidden',
}));

const PlaceholderText = styled(Typography)(({ theme }) => ({
  color: theme.palette.text.secondary,
  textAlign: 'center',
  padding: theme.spacing(2),
}));

const Library3D: React.FC = () => {
  return (
    <PlaceholderContainer elevation={3}>
      <PlaceholderText variant="h6">
        3D Model View
        <Box component="p" sx={{ typography: 'body2', mt: 1 }}>
          Coming soon...
        </Box>
      </PlaceholderText>
    </PlaceholderContainer>
  );
};

export default Library3D; 