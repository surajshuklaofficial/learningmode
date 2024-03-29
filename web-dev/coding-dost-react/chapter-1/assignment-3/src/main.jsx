import React from 'react'
import ReactDOM from 'react-dom/client'
import App from './App.jsx'
import App2 from './App2.jsx'
import './index.css'

ReactDOM.createRoot(document.getElementById('root-1')).render(
  <React.StrictMode>
    <App />
  </React.StrictMode>,
)
ReactDOM.createRoot(document.getElementById('root-2')).render(
  <React.StrictMode>
    <App2 />
  </React.StrictMode>,
)
