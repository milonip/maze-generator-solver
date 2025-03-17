# Maze Generator and Solver

A C++ implementation of a random maze generator and solver using Depth-First Search (DFS) algorithm.

## Features

- Random maze generation using DFS algorithm
- Maze solving using DFS
- Visual representation of the maze and solution path
- Customizable maze dimensions

## Requirements

- C++ compiler with C++11 support
- Standard Template Library (STL)

## Build Instructions

To compile the program:

```bash
g++ -std=c++11 maze.cpp -o maze
```

To run the program:

```bash
./maze
 ```

## Usage
The program will:

1. Generate a random maze with walls (#), paths ( ), start point (S), and end point (E)
2. Display the generated maze
3. Solve the maze using DFS
4. Display the solution path marked with dots (.)

## Example Output
```plaintext
Generated Maze:
# # # # # # # # # # # # # # #
# S     #       #           #
# # #   #   #   #   # # #   #
#   #   #   #       #   #   #
#   #       # # #   #   #   #
#   # # #   #   #       #   #
#           #   # # #   #   #
# # # # #   #           #   #
#       #   # # # # #   #   #
#   #   #               #   #
#   #   # # # # # # #   #   #
#   #                   #   #
#   # # # # # # # # #   #   #
#                       E   #
# # # # # # # # # # # # # # #

Solution found:
# # # # # # # # # # # # # # #
# S . . #       #           #
# # # . #   #   #   # # #   #
#   # . #   #       #   #   #
#   # . . . # # #   #   #   #
#   # # # . #   #       #   #
#         . #   # # #   #   #
# # # # # . #           #   #
#       # . # # # # #   #   #
#   #   # . . . . . .   #   #
#   #   # # # # # # # . #   #
#   #               . . #   #
#   # # # # # # # # # . #   #
#                     . E   #
# # # # # # # # # # # # # # #
 ```

## How It Works
1. Maze Generation :
   
   - Uses a randomized DFS algorithm
   - Creates perfect mazes (exactly one path between any two points)
   - Ensures all paths are connected

2. Maze Solving :
   
   - Implements DFS to find a path from start (S) to end (E)
   - Marks the solution path with dots (.)
   - Guarantees finding a solution if one exists

## Author
Miloni Patel