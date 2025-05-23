import React from 'react';
import { AppBar, Toolbar, Typography } from '@mui/material';
import { styled } from '@mui/material/styles';

const StyledAppBar = styled(AppBar)(({ theme }) => ({
  zIndex: theme.zIndex.drawer + 1,
}));

const Header: React.FC = () => {
  return (
    <StyledAppBar position="fixed">
      <Toolbar>
        <Typography variant="h6" noWrap component="div">
          图书馆数字孪生系统
        </Typography>
      </Toolbar>
    </StyledAppBar>
  );
};

export default Header; 