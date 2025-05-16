# GridPathFinder

A C++ project implementing efficient shortest pathfinding algorithms on a 2D grid.

## Overview

GridPathFinder is a utility class designed to find the shortest path between two points in a grid-based environment. The grid consists of cells, where `0` represents a free cell and `1` represents a blocked cell. The class provides two BFS-based methods for pathfinding:

- `get_shortestDistance`: A straightforward BFS approach that stores the entire path during exploration.
- `get_shortestDistanceOpti`: An optimized BFS approach that uses parent tracking to reconstruct the path efficiently.

## Features

- Validates moves within the grid bounds avoiding blocked or visited cells.
- Finds shortest paths using BFS, ensuring optimal solutions in unweighted grids.
- Efficient path reconstruction with `parentTracker` to minimize memory usage.
- Clear separation between class declaration (header) and implementation (source).

## 📁 Folder Structure

```text
src/
├── headers/
│   └── GridPathFinder.h      # Class declaration for pathfinding logic
|   └── NECESSARY_HEADERS.h
└── source/
    └── GridPathFinder.cpp    # Method implementations for the GridPathFinder class
    └── main.cpp              # For testing Code
