import React from 'react';
import { Routes, Route } from 'react-router-dom';
import { Box } from '@mui/material';
import Header from './components/Header';
import Sidebar from './components/Sidebar';
import Dashboard from './components/Dashboard';
import Demo3DView from './pages/Demo3DView';
import SeatManagement from './pages/SeatManagement';
import EquipmentManagement from './pages/EquipmentManagement';

const App: React.FC = () => {
  return (
    <Box sx={{ display: 'flex', minHeight: '100vh' }}>
      <Header />
      <Sidebar />
      <Box
        component="main"
        sx={{
          flexGrow: 1,
          p: 2,
          mt: 8,
          ml: '200px', // Reduced from 240px
          backgroundColor: (theme) => theme.palette.background.default,
          minHeight: 'calc(100vh - 64px)',
          maxWidth: 'calc(100vw - 200px)', // Added maxWidth
        }}
      >
        <Routes>
          <Route path="/" element={<Dashboard />} />
          <Route path="/3d-view" element={<Demo3DView />} />
          <Route path="/seats" element={<SeatManagement />} />
          <Route path="/equipment" element={<EquipmentManagement />} />
        </Routes>
      </Box>
    </Box>
  );
};

export default App;
