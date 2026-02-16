# Implementation of Undirected Graph Using Adjacency Matrix with BFS and DFS

## Objective

To implement an undirected graph using an adjacency matrix and perform graph traversal using:

- Breadth-First Search (BFS)
- Depth-First Search (DFS)

The program also demonstrates the traversal using an example graph.

## Graph Representation

An undirected graph can be represented using an adjacency matrix.

In an adjacency matrix:

- Rows and columns represent vertices.
- If there is an edge between vertex `i` and `j`, then:

```c
adjMatrix[i][j] = 1
adjMatrix[j][i] = 1
```

- If no edge exists, the value is `0`.

Since the graph is undirected, the matrix is symmetric.

## Structure Used

```c
struct Graph {
    int vertices;
    int adjMatrix[MAX][MAX];
};
```

- `vertices` → number of vertices in graph
- `adjMatrix` → 2D array storing connections

## Functions Used

### 1. initGraph()

Initializes the graph by:

- Setting number of vertices
- Filling adjacency matrix with 0

### 2. addEdge()

Adds an edge between two vertices.

For undirected graph:

```c
adjMatrix[u][v] = 1
adjMatrix[v][u] = 1
```

### 3. DFS (Depth-First Search)

DFS explores the graph deeply before backtracking.

**Working:**

1. Mark starting vertex as visited.
2. Print the vertex.
3. Recursively visit all unvisited adjacent vertices.

DFS uses recursion.

### 4. BFS (Breadth-First Search)

BFS explores the graph level by level.

**Working:**

1. Mark starting vertex as visited.
2. Insert it into a queue.
3. Remove vertex from queue.
4. Visit all unvisited adjacent vertices and insert them into queue.
5. Repeat until queue becomes empty.

BFS uses a queue data structure.

## Output

![](assets/Program_5_output.png)
