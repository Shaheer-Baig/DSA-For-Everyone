# Graph in Data Structure

A **graph** is a non-linear data structure that consists of **nodes (vertices)** and **edges (connections)**. It is used to represent relationships between objects, such as networks, maps, and social connections.

## Definition of a Graph
A graph **G** is defined as:

\[ G = (V, E) \]

Where:
- **V** is the set of vertices (nodes).
- **E** is the set of edges (connections) between vertices.

## Types of Graphs

### 1. Based on Direction of Edges
- **Undirected Graph**: Edges have no direction (e.g., social network friendships).
- **Directed Graph (Digraph)**: Edges have a specific direction (e.g., following someone on Twitter).

### 2. Based on Weight of Edges
- **Unweighted Graph**: All edges have the same weight (distance is ignored).
- **Weighted Graph**: Each edge has a weight or cost (e.g., road distances on a map).

### 3. Based on Connectivity
- **Connected Graph**: There is a path between any two vertices.
- **Disconnected Graph**: Some vertices are isolated (not reachable).

### 4. Based on Cycles
- **Cyclic Graph**: The graph contains at least one cycle.
- **Acyclic Graph**: The graph has no cycles.
- **DAG (Directed Acyclic Graph)**: A directed graph without cycles (used in topological sorting).

### 5. Based on Bipartiteness
- **Bipartite Graph**: The graph can be divided into two sets, with no edges within the same set.
- **Complete Graph**: Every pair of vertices is connected.

## Graph Representation
A graph can be represented using:

### 1. Adjacency Matrix
An **Adjacency Matrix** is a 2D array where:
- If there is an edge between vertex `i` and `j`, `matrix[i][j] = 1`.
- If there is no edge, `matrix[i][j] = 0`.
- For weighted graphs, `matrix[i][j] = weight` instead of `1`.

#### Example: Adjacency Matrix for an Undirected Graph

Graph Representation:
```
  (0) -- (1)
   |      |
  (2) -- (3)
```

Adjacency Matrix:
```
   0  1  2  3
0  0  1  1  0
1  1  0  0  1
2  1  0  0  1
3  0  1  1  0
```

#### Advantages of Adjacency Matrix:
- Fast Edge Lookup **O(1)**.
- Good for dense graphs (many edges).

#### Disadvantages of Adjacency Matrix:
- High Space Complexity **O(V^2)** for sparse graphs.
- Inefficient for large graphs with fewer edges.

### 2. Adjacency List
An **Adjacency List** represents a graph as an array of lists, where each index stores a list of connected vertices.

#### Example: Adjacency List for the Same Graph
```
0 → 1 → 2  
1 → 0 → 3  
2 → 0 → 3  
3 → 1 → 2  
```

#### Advantages of Adjacency List:
- Efficient for Sparse Graphs **O(V + E)** storage.
- Faster Traversal for large graphs.

#### Disadvantages of Adjacency List:
- Slower Edge Lookup **O(V)** compared to adjacency matrix.

## Graph Traversal Algorithms
Graph traversal means visiting all vertices in a structured manner.

### 1. Breadth-First Search (BFS) - **O(V + E)**
BFS explores nodes level by level (like a queue). It is useful for shortest path problems in unweighted graphs.

#### Steps:
1. Start from a vertex.
2. Visit all immediate neighbors first.
3. Use a queue (FIFO) to process nodes.

**Example BFS Order (from node 0):** 0 → 1 → 2 → 3

### 2. Depth-First Search (DFS) - **O(V + E)**
DFS explores as deep as possible before backtracking (like recursion).

#### Steps:
1. Start from a vertex.
2. Visit the next unvisited neighbor.
3. Use a stack (LIFO) or recursion.

**Example DFS Order (from node 0):** 0 → 1 → 3 → 2

## Shortest Path Algorithms

### 1. Dijkstra’s Algorithm - **O((V + E) logV)**
- Finds the shortest path in a weighted graph (no negative edges).
- Uses a priority queue (min-heap).
- Used in Google Maps, GPS Navigation.

### 2. Floyd-Warshall Algorithm - **O(V^3)**
- Finds the shortest path between all pairs of vertices.
- Uses Dynamic Programming.
- Used in network routing, all-pairs shortest path problems.

## Cycle Detection in Graphs

### Undirected Graphs
- Use DFS to check if a visited node is revisited (not the parent).

### Directed Graphs
- Use DFS and recursion stack to detect cycles.
- Used in deadlock detection, dependency resolution.

## Topological Sorting (DAG Only) - **O(V + E)**
- Orders nodes in a dependency-first sequence.
- Only works for Directed Acyclic Graphs (DAGs).
- Used in task scheduling, build systems, resolving dependencies.

## Graph Coloring - **O(V + E)**
- Assigns colors to nodes so that no two adjacent nodes have the same color.
- **Chromatic Number**: The minimum number of colors needed.
- Used in register allocation, map coloring, scheduling problems.

## Graph Connectivity & Strongly Connected Components (SCCs)
- A graph is connected if there is a path between every pair of vertices.
- **Strongly Connected Component (SCC)**: A subset of vertices where every node is reachable from every other node.
- **Kosaraju’s Algorithm** (**O(V + E)**) is used to find SCCs.
- Used in social network analysis, power grid analysis.

## Time Complexity of Graph Algorithms

| Algorithm             | Time Complexity |
|----------------------|----------------|
| BFS, DFS            | O(V + E)        |
| Dijkstra            | O((V + E) log V) |
| Floyd-Warshall      | O(V^3)          |
| Topological Sort    | O(V + E)        |
| Cycle Detection     | O(V + E)        |
| SCC (Kosaraju’s)    | O(V + E)        |

## Applications of Graphs
- **Social Networks**: Facebook, Twitter graphs.
- **Google Maps**: Shortest path, navigation.
- **Web Crawlers**: Link analysis, search engines.
- **AI & Games**: Pathfinding in game development.
- **Networking**: Routing algorithms (OSPF, BGP).
- **Scheduling & Dependencies**: Task scheduling, compiler design.

## Conclusion
Graphs are one of the most versatile data structures used in real-world applications. Understanding graph representations, traversal techniques, and shortest path algorithms is essential for problem-solving in computer science and competitive programming.

