import React from 'react';
import { useNavigate, useLocation } from 'react-router-dom';
import {
  Drawer,
  List,
  ListItem,
  ListItemButton,
  ListItemIcon,
  ListItemText,
  styled,
} from '@mui/material';
import {
  Dashboard as DashboardIcon,
  ViewInAr as View3DIcon,
  EventSeat as SeatIcon,
  Computer as EquipmentIcon,
} from '@mui/icons-material';

const drawerWidth = 200;

const StyledDrawer = styled(Drawer)(({ theme }) => ({
  width: drawerWidth,
  flexShrink: 0,
  '& .MuiDrawer-paper': {
    width: drawerWidth,
    boxSizing: 'border-box',
    marginTop: 64, // Height of the header
    backgroundColor: theme.palette.background.paper,
  },
}));

const menuItems = [
  { text: '总览', icon: <DashboardIcon />, path: '/' },
  { text: '3D模型', icon: <View3DIcon />, path: '/3d-view' },
  { text: '座位管理', icon: <SeatIcon />, path: '/seats' },
  { text: '设备管理', icon: <EquipmentIcon />, path: '/equipment' },
];

const Sidebar: React.FC = () => {
  const navigate = useNavigate();
  const location = useLocation();

  return (
    <StyledDrawer variant="permanent">
      <List>
        {menuItems.map((item) => (
          <ListItem key={item.text} disablePadding>
            <ListItemButton
              onClick={() => navigate(item.path)}
              selected={location.pathname === item.path}
            >
              <ListItemIcon>{item.icon}</ListItemIcon>
              <ListItemText primary={item.text} />
            </ListItemButton>
          </ListItem>
        ))}
      </List>
    </StyledDrawer>
  );
};

export default Sidebar; 