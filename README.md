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

<img width="1007" height="834" alt="image" src="https://github.com/user-attachments/assets/cdd021b5-1345-480b-9f5f-0f6d706f6ca7" />

<img width="1007" height="834" alt="image" src="https://github.com/user-attachments/assets/06eeeccb-4fd6-4768-bc21-4ce09b4411a8" />

## 🎯 Features

- Isometric projection rendering of 3D terrain
- Keyboard controls for zoom, rotation, and panning
- Mouse control for zoom and panning
- Supports custom elevation map files with per-point colour
- Minimal, responsive UI supported by MiniLibX graphics library

## 📁 Project Structure

```
ft_fdf
├─ Makefile
├─ README.md
├─ fdf
├─ include
│  ├─ enum.h
│  ├─ fdf.h
│  ├─ macros.h
│  ├─ struct.h
│  └─ utils.h
├─ lib
│  ├─ libft
│  └─ minilibx-linux
├─ maps
│  ├─ 10-2.fdf
│  ├─ 10-70.fdf
│  ├─ 100-6.fdf
│  ├─ 20-60.fdf
│  ├─ 42.fdf
│  ├─ 50-4.fdf
│  ├─ bad-noperm.fdf
│  ├─ basictest.fdf
│  ├─ elem-col.fdf
│  ├─ elem-fract.fdf
│  ├─ elem.fdf
│  ├─ elem2.fdf
│  ├─ julia.fdf
│  ├─ mars.fdf
│  ├─ pentenegpos.fdf
│  ├─ plat.fdf
│  ├─ pnp_flat.fdf
│  ├─ pylone.fdf
│  ├─ pyra.fdf
│  ├─ pyramide.fdf
│  ├─ t1.fdf
│  └─ t2.fdf
└─ src
   ├─ bsh.c
   ├─ cinterp.c
   ├─ cparser.c
   ├─ errors.c
   ├─ hooks.c
   ├─ init.c
   ├─ log.c
   ├─ main.c
   ├─ mem_utils.c
   ├─ mlx_utils.c
   ├─ mparser.c
   ├─ mparser_utils.c
   ├─ pan.c
   ├─ project.c
   ├─ render.c
   ├─ rotate.c
   ├─ sentinels.c
   └─ zoom.c
```

## 🚀 Getting Started

### 🕹️  Controls

- Toggle default view: `0` for isometric view, `1` for orthogonal view
- Toggle projection (isometric/orthogonal): `TAB` key
- Toggle altitude scaling: `CAPSLOCK` key
- Zoom: `-`/`+` keys, or mouse scroll
- Pan Left/Right/Up/Down: WASD keys
- Rotate along x-axis: `ARROWUP`/`ARROWDOWN` keys
- Rotate along y-axis: `ARROWLEFT`/`ARROWRIGHT` keys
- Rotate along z-axis: `<`/`>` keys
- Free panning: Click + hold and drag around in the window
- Close window: Click `X` button or `ESC` key

### 📄 Map Input Format

FDF accepts `.fdf` files as its input - each file is a grid of elevation values, optionally with colour.

### Usage

1. Run Make: `make all`
2. `./fdf maps/42.fdf`

Alternatively, to make and execute at the same time, run `make <map name>`. For instance, `make 42` to make `42.fdf` from the `maps` folder.

## 🔧 Technical Highlights

- Bresenham's Line Drawing Algorithm
- 3D to 2D projection: Supports isometric and orthogonal projections
- Colour interpolation: Gradient colouring based on Z-axis values

## 🔭 Future Enhancements / Fixes

- [ ] Control panel UI for user-friendliness
- [ ] Allowing free-form rotation via quarternions
- [ ] Improving colour interpolation logic so it is more informative rather than decorative
- [ ] More accurate centering of map upon inital load
- [ ] Fix corruption in line rendering of julia map during left/right rotation


