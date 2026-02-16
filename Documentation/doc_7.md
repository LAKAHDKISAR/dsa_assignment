# Implementation of Dijkstra's Algorithm for Shortest Path

## Explanation of Data Structures Defined

The program represents a weighted graph using an adjacency matrix.

```c
int graph[MAX][MAX];
```

- `graph[i][j]` represents the weight of the edge between vertex `i` and vertex `j`.
- If there is no edge, the value is `0`.

Two additional arrays are used:

### 1. `dist[]`

- Stores shortest distance from source to each vertex.

### 2. `visited[]`

- Keeps track of vertices whose shortest distance is finalized.

## Functions Implemented

### 1. minDistance()

**Purpose:** Finds the vertex with the smallest distance value that has not yet been visited.

**Working:**

- Iterates through all vertices.
- Selects the minimum distance vertex not yet processed.

### 2. dijkstra()

**Purpose:** Implements Dijkstra's shortest path algorithm.

**Working:**

1. **Initialize:**
   - All distances to infinity (`INT_MAX`)
   - All vertices as unvisited
   - Distance of source = 0

2. **Repeat for all vertices:**
   - Select vertex with minimum distance
   - Mark it visited
   - Update distances of adjacent vertices

**Time Complexity:** O(V²) (since adjacency matrix is used)

## main() Function

The `main()` function:

1. Defines a weighted graph using adjacency matrix.
2. Sets the number of vertices (`V = 5`).
3. Chooses source vertex (`0`).
4. Calls `dijkstra()` function.
5. Prints shortest distances from source to all other vertices.

## Output

![](assets/Program_7_output.png)
