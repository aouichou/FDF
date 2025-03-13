<h1 align="center">FDF</h1>
<h3 align="center">42Paris School Project</h3>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" alt="Language">
  <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

## About the Project

`FDF` (Fil de Fer) is a wireframe modeling program that renders 3D landscapes from topographic maps. Developed as part of the 42Paris curriculum, this project introduces computer graphics concepts using the MiniLibX library. It parses `.fdf` files containing elevation data and creates interactive 3D projections with rotation, zoom, and color customization.

![Wireframe Example](https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fstatic.vecteezy.com%2Fsystem%2Fresources%2Fpreviews%2F029%2F128%2F083%2Foriginal%2Fperspective-grids-retro-futuristic-wireframes-cyberpunk-net-space-perspective-lines-vanishing-point-rectangular-space-seamless-checkered-isometric-grid-pattern-isolated-set-vector.jpg&f=1&nofb=1&ipt=1f407b97bf3175d55cb4288dc5153fa99ce37cc799e73b00c72c56758fe20d4e&ipo=images)  
*Example: Rendered landscape with altitude-based coloring*

## Features

- **3D Projections**:
  - Isometric (mandatory)
  - Perspective (bonus)
  - Top-down view (bonus)
- **Interactive Controls**:
  - Rotate models on X/Y/Z axes
  - Zoom in/out with mouse wheel
  - Pan with arrow keys
  - Altitude scaling
- **Color Schemes**:
  - Default segment coloring
  - Gradient-based altitude colors
  - Topographic palette (land/water)
- **Multi-Map Support**: Switch between multiple maps at runtime
- **Smooth Rendering**: 60+ FPS performance for complex maps

## Technical Details

- **Language**: C
- **Libraries**:
  - MiniLibX (42's graphics library)
  - Custom `libft` for utilities
- **Math**: Matrix transformations for rotations/projections
- **Algorithms**: Bresenham's line drawing, color interpolation
- **Optimizations**: Image buffering for flicker-free rendering

## Getting Started

### Prerequisites

- X11/Wayland graphics environment
- `gcc` & `make`
- `libxext-dev` and `libx11-dev` (X11 libraries)

### Installation

1. Clone the repository:
   ```sh
   git clone https://github.com/<your-username>/fdf.git
   cd fdf
   ```

2. Compile with:
   ```sh
   make
   ```

### Usage

Run with a map file:
```sh
./fdf test_maps/42.fdf
```

**Controls**:
- `Arrows` : Pan view  
- `Mouse Wheel` : Zoom  
- `7/9` : Rotate X-axis  
- `1/3` : Rotate Y-axis  
- `4/6` : Rotate Z-axis  
- `I/P/O` : Switch projections  
- `R` : Reset view  
- `ESC` : Quit  

## Project Structure

```
.
├── includes/           # Headers
├── libs/               # Dependencies
│   ├── libft/          # Custom C library
│   └── mlx/            # MiniLibX graphics library
├── srcs/               # Core logic
│   ├── parsing.c       # Map file parser
│   ├── projections.c   # 3D projection systems
│   ├── rotations.c     # Axis rotations
│   └── draw.c          # Bresenham's line algorithm
└── test_maps/          # Sample topographic maps
```

## Key Components

- **Map Parsing**: Reads `.fdf` files with elevation/color data
- **Isometric Projection**: Converts 3D coordinates to 2D display
- **Color Gradients**: Interpolates colors based on Z-value
- **Event Handling**: Keyboard/mouse input via MiniLibX hooks

## Bonus Features

- Multiple projection modes
- Dynamic altitude scaling (`Z/X` keys)
- Real-time rotations
- Color palette switching (`Q`/`SPACE`)
- Multi-map navigation (`+/-` keys)

## Acknowledgements

Developed as part of the 42Paris curriculum. Special thanks to:
- 42 Network for MiniLibX documentation
- Community algorithms for Bresenham's line optimization

---

<p align="left">
  <a href="https://www.linkedin.com/in/your-profile" target="blank">
    <img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="Your Name" height="30" width="40" />
  </a>
</p>
