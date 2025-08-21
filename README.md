```
███████╗██████╗ ███████╗
██╔════╝██╔══██╗██╔════╝
█████╗  ██║  ██║█████╗  
██╔══╝  ██║  ██║██╔══╝  
██║     ██████╔╝██║     
╚═╝     ╚═════╝ ╚═╝     
```

## 🗺️  Overview 

This project is aimed at exploring the basics of computer graphics. The objective is to create a 3D wireframe representation of a landscape based on a 2D map of altitudes, rendered using a minimal graphics library - MiniLibX.

## 🎯 Features

- Isometric projection rendering of 3D terrain
- Keyboard controls for zoom, rotation, and panning
- Mouse control for zoom and panning
- Supports custom elevation map files with per-point colour
- Minimal, responsive UI supported by MiniLibX graphics library

## 📁 Project Structure

## 🚀 Getting Started

### Dependencies

### Build Instructions

### 🕹️  Controls

### 📄 Map Input Format

FDF accepts `.fdf` files as its input - each file is a grid of elevation values, optionally with colour.

### Usage

`./fdf maps/42.fdf`

## 🔧 Technical Highlights

- Bresenham's Line Drawing Algorithm
- 3D to 2D projection: Supports isometric and orthogonal projections
- Colour interpolation: Gradient colouring based on Z-axis values
