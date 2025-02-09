
# Shortest Path

## What is the Shortest Path?

The shortest path between two vertices in a graph is the path with the minimum total weight (in weighted graphs) or the minimum number of edges (in unweighted graphs). The goal is to find the most efficient route from a starting vertex to a target vertex.

### Key Concepts:

- **Source and Destination:**
  - The source is the starting vertex.
  - The destination is the target vertex.
- **Path Weight:**
  - In a weighted graph, the weight of a path is the sum of the weights of its edges.
  - In an unweighted graph, the weight of a path is simply the number of edges.
- **Optimality:**
  - The shortest path is the one with the smallest total weight (or fewest edges).

### Algorithms for Finding the Shortest Path:

1. **Breadth-First Search (BFS)** (for unweighted graphs).
2. **Dijkstra's Algorithm** (for weighted graphs with non-negative weights).
3. **Bellman-Ford Algorithm** (for weighted graphs with negative weights, detecting negative cycles).

### Applications of Shortest Path:

- GPS navigation systems.
- Network routing.
- Social network analysis.
- Logistics and transportation.

**Example:**
A → B (weight 2), A → C (weight 4), B → C (weight 1). Shortest path from A to C is A → B → C (weight 3).

