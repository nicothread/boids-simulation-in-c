# Boids Simulation in C

A classic **Boids** (Artificial Life) simulation implemented in C with SDL2 rendering. This project demonstrates flocking behavior where simple agents follow three basic rules to create complex emergent patterns.

## Overview

This implementation brings the famous boids algorithm to life through a visual simulation. Watch as artificial birds (agents) navigate their environment, following flocking rules that create realistic group movement patterns.

### Features

- **Flocking Algorithm**: Implements separation, alignment, and cohesion rules
- **Real-time Visualization**: Uses SDL2 for dynamic rendering
- **Efficient Rendering**: Optimized bird/entity rendering system
- **Configurable Parameters**: Easily adjustable simulation constants
- **Clean Architecture**: Modular design with clear separation of concerns

## Project Structure
<code>
boids/ 
├── include/ # Header files
├── boids_agent.h # Agent simulation logic
├── boids_agent_helper.h # Agent helper utilities
├── boids_consts.h # Simulation constants
├── boids_structs.h # Data structures
├── entity_renderer.h # Generic entity rendering
└── sdl_renderer.h # SDL2 renderer backend 
├── src/ # Source files
├── main.c # Entry point and simulation loop
├── boids_agent.c # Agent implementation
├── bird_renderer.c # Bird visualization
├── sdl_renderer.c # SDL2 backend implementation 
├── CMakeLists.txt # Build configuration 
├── LICENSE # MIT License 
└── README.md # This file
</code>


## Requirements

- **C17** or later
- **SDL2** library
- **CMake 3.16+** for building
- A C compiler (GCC, Clang, MSVC, or AppleClang)

### Installing Dependencies

#### Ubuntu/Debian
```bash
sudo apt-get install libsdl2-dev cmake
```

#### macOS (with Homebrew)``` bash
brew install sdl2 cmake
```

Windows (with vcpkg)``` bash
vcpkg install sdl2:x64-windows cmake
```

### Building

#### Using CMake

```bash
# Create build directory
mkdir build
cd build

# Configure and build
cmake ..
cmake --build .

# Run the simulation
./boids
```

## Usage

Simply run the executable:
```
./boids
```

The simulation will open a window displaying the boids flying around. The agents follow three fundamental rules:

 - __Separation__ 
   - Avoid crowding neighbors
 - __Alignment__
   - Steer towards the average heading of neighbors
 - __Cohesion__
   - Steer towards the average location of neighbors

## Configuration

Simulation parameters can be adjusted in include/boids_consts.h:

 - __Agent count__ 
   - Number of boids in the simulation
 - __Simulation bounds__ 
   - Window dimensions
 - __Behavior thresholds__
   - Distances for rules application
 Movement parameters: Speed and acceleration limits
 Visual parameters: Colors and rendering options