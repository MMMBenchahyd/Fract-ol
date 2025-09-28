# Fract-ol

A 42 School project that generates and displays beautiful fractals using the MiniLibX graphics library.

## 📖 About

Fract-ol is a fractal explorer that renders mathematical fractals in real-time. This project introduces fundamental concepts of complex numbers, mathematical optimization, and event-driven programming while creating visually stunning fractal patterns.

## ✨ Features

### Mandatory Part
- **Mandelbrot Set**: Classic fractal with infinite complexity at its boundary
- **Julia Set**: Beautiful fractal patterns with customizable parameters
- **Real-time Rendering**: Smooth fractal generation and display
- **Interactive Controls**: Mouse and keyboard navigation
- **Zoom Functionality**: Mouse wheel zooming in and out infinitely
- **Color Gradients**: Multiple color schemes to visualize fractal depth
- **Window Management**: Proper window handling with ESC key exit

### Bonus Features
- **Additional Fractals**: Extended fractal types beyond Mandelbrot and Julia
- **Enhanced Interactions**: Advanced mouse and keyboard controls
- **Optimized Rendering**: Improved performance for smoother experience
- **Custom Color Palettes**: Multiple color schemes and transitions

## 🚀 Getting Started

### Prerequisites
- GCC compiler
- Make
- MiniLibX library (included in 42 environment)
- X11 development libraries (Linux)

### Installation

1. Clone the repository:
```bash
git clone https://github.com/MMMBenchahyd/Fract-ol.git
cd Fract-ol
```

2. Compile the project:


```shellscript
make
```

3. For bonus features:


```shellscript
make bonus
```

## Usage

### Basic Usage

```shellscript
# Display Mandelbrot set
./fractol mandelbrot

# Display Julia set with custom parameters
./fractol julia <real_part> <imaginary_part>
```

### Examples

```shellscript
# Classic Julia set
./fractol julia -0.7 0.27015

# Another beautiful Julia set
./fractol julia 0.285 0.01

# Mandelbrot set
./fractol mandelbrot
```

## Controls

| Key/Mouse | Action
|-----|-----
| **Mouse Wheel** | Zoom in/out
| **Arrow Keys** | Move around the fractal
| **ESC** | Exit the program
| **Mouse Click** | Center view on clicked point
| **Space** | Reset view to default
| **C** | Cycle through color schemes
| **+/-** | Increase/decrease iterations


## Technical Details

### Fractal Mathematics

- **Mandelbrot Set**: z_n+1 = z_n^2 + c
- **Julia Set**: z_n+1 = z_n^2 + c (where c is constant)


### Key Concepts

- **Complex Number Arithmetic**: Mathematical operations in the complex plane
- **Iteration Limits**: Determining convergence/divergence
- **Color Mapping**: Converting iteration counts to visual colors
- **Coordinate Transformation**: Mapping screen pixels to complex plane
- **Optimization**: Efficient algorithms for real-time rendering


## Project Structure

```plaintext
Fract-ol/
├── Mandatory/          # Core implementation
│   ├── main.c          # Source files
│   └── ...
├── Bonus/             # Extended features
│   ├── main_bonus.c   # Bonus source files
│   └── ...
├── Makefile           # Build configuration
└── README.md          # This file
```

## Fractal Gallery

The program generates stunning visual patterns including:

- **Mandelbrot Set**: The iconic "bug" shape with infinite detail
- **Julia Sets**: Circular, connected, or dust-like patterns depending on parameters
- **Custom Fractals**: Additional mathematical sets (bonus)


## ️ Compilation Flags

```makefile
# Standard flags used
NAME = fractol
NAME_BONUS = fractol_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

```

## Learning Objectives

This project teaches:

- **Mathematical Concepts**: Complex numbers and fractal geometry
- **Graphics Programming**: Pixel manipulation and real-time rendering
- **Event Handling**: Mouse and keyboard input processing
- **Memory Management**: Efficient resource allocation
- **Algorithm Optimization**: Performance improvements for mathematical computations


## Error Handling

The program handles various error cases:

- Invalid command-line arguments
- Memory allocation failures
- Graphics initialization errors
- Invalid fractal parameters


## 42 School Standards

This project follows 42 School coding standards:

- **Norm Compliant**: Adheres to 42 coding style
- **Memory Safe**: No memory leaks or undefined behavior
- **Error Resistant**: Proper error handling throughout
- **Modular Design**: Clean, readable, and maintainable code


## Contributing

This is a 42 School project, but suggestions and improvements are welcome:

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Submit a pull request


## License

This project is part of the 42 School curriculum. Feel free to use it for educational purposes.

## Acknowledgments

- **42 School** for the project specifications
- **Benoit Mandelbrot** for fractal mathematics
- **Gaston Julia** for Julia set theory
- **MiniLibX** graphics library developers


---
