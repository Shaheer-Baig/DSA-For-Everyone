# Minimum Spanning Tree (MST)

A **Minimum Spanning Tree (MST)** is a subset of edges in a connected, weighted, undirected graph that connects all vertices without cycles and with the minimum possible total edge weight.

## Key Properties of MST
- **Spanning**: The tree must include all vertices of the original graph.
- **Acyclic**: There should be no cycles in the tree.
- **Minimum Weight**: The sum of edge weights in the MST should be as small as possible.
- **Connected**: MST ensures that all nodes are reachable from any other node.

## Example of MST

Consider the following weighted graph:

```
    (1)
   /   \
  4     2
 /       \
(0)---3---(2)
     |
     1
     |
    (3)
```

### Graph Edges:

| Edge  | Weight |
|-------|--------|
| 0 - 1 | 4      |
| 0 - 2 | 3      |
| 1 - 2 | 2      |
| 1 - 3 | 1      |

### Possible Spanning Trees:
A graph with **V** vertices has multiple possible spanning trees, but only one MST with the minimum weight.

For the above graph, the MST could be:
- **Edges**: (1-3, 1), (1-2, 2), (0-2, 3)
- **Total weight**: 1 + 2 + 3 = **6**

## Algorithms to Find MST

### 1. Prim’s Algorithm (Greedy)
- Starts with a random node.
- Grows the MST by adding the minimum-weight edge that connects an included node to an excluded node.
- Uses a priority queue (min-heap) to select edges efficiently.
- **Time Complexity**: **O(E log V)** (Using min-heap for selection).

### 2. Kruskal’s Algorithm (Greedy, Disjoint Set)
- Sorts all edges by weight.
- Selects the smallest edge that does not form a cycle.
- Uses the **Union-Find** (Disjoint Set Union - DSU) data structure.
- **Time Complexity**: **O(E log E)** (Sorting edges and using DSU).

## Limitations of MST
- Only applicable to **connected graphs** (Disconnected graphs don't have an MST).
- Does not work for **directed graphs**.
- Unique MST only exists if **all edge weights are distinct**.

# Kruskal’s Algorithm - Minimum Spanning Tree (MST)

Kruskal’s Algorithm is a **greedy algorithm** used to find the MST of a **connected, undirected, weighted graph**. It works by sorting edges and adding the smallest possible edge to the MST while ensuring no cycles are formed.

## How Kruskal’s Algorithm Works
1. Sort all edges in ascending order of their weight.
2. Initialize an empty MST and use a **Disjoint Set Union (DSU)** to track connected components.
3. Iterate through edges:
   - If adding an edge does not form a cycle, add it to the MST.
   - Otherwise, ignore the edge.
4. Repeat until the MST contains **V-1** edges, where **V** is the number of vertices.

### Example Walkthrough

#### Graph Representation
```
     2      3
 (A)---(B)---(C)
  |       |   |
  6       8   7
  |       |   |
 (D)------(E)--(F)
      9       5
```

### Graph Edges:

| Edge  | Weight |
|-------|--------|
| A - B | 2      |
| A - D | 6      |
| B - C | 3      |
| B - E | 8      |
| C - F | 7      |
| D - E | 9      |
| E - F | 5      |

### Step-by-Step Execution

1. **Sort all edges by weight:**
   - (A-B, 2), (B-C, 3), (E-F, 5), (A-D, 6), (C-F, 7), (B-E, 8), (D-E, 9)
2. **Initialize Disjoint Set Union (DSU):**
   - Each node is its own parent initially.
3. **Start adding edges without forming cycles:**
   - (A-B, 2) → Add
   - (B-C, 3) → Add
   - (E-F, 5) → Add
   - (A-D, 6) → Add
   - (C-F, 7) → Add
4. **Ignore edges that form cycles:**
   - (B-E, 8) (Ignored)
   - (D-E, 9) (Ignored)

### Final MST Edges:
- (A-B, 2), (B-C, 3), (E-F, 5), (A-D, 6), (C-F, 7)

**Total MST Cost** = 2 + 3 + 5 + 6 + 7 = **23**

### Time Complexity
- **Sorting edges**: **O(E log E)**
- **DSU operations**: **O(E log V)**
- **Overall Complexity**: **O(E log E)**, since E log E dominates.

## Limitations of Kruskal’s Algorithm
- Requires a **connected graph**.
- Sorting takes extra time for very large graphs.
- Not optimal for **dense graphs** (works best for sparse graphs).

# Prim’s Algorithm - Minimum Spanning Tree (MST)

Prim’s Algorithm is a **greedy algorithm** used to find the MST of a **connected, weighted, undirected graph**. Unlike Kruskal’s Algorithm, which works by sorting edges, Prim’s Algorithm builds the MST by growing a single tree edge by edge.

## How Prim’s Algorithm Works
1. Start with any node in the graph.
2. Maintain a **visited** set to track included nodes.
3. Use a **priority queue (min-heap)** to select the smallest edge that connects an included node to an excluded node.
4. Add the selected edge to the MST and include the new node.
5. Repeat until all nodes are in the MST.

### Example Walkthrough

#### Graph Representation
```
      2      3
   (A)---(B)---(C)
    |       |   |
    6       8   7
    |       |   |
   (D)------(E)--(F)
         9       5
```

### Step-by-Step Execution
1. **Start from an arbitrary node (A)**
   - Include A in MST.
   - Choose the smallest edge: (A-B, 2)
2. **Find the smallest edge from {A, B}**
   - (B-C, 3) is the smallest edge
3. **Find the smallest edge from {A, B, C}**
   - (C-F, 7) is the smallest edge
4. **Find the smallest edge from {A, B, C, F}**
   - (E-F, 5) is the smallest edge
5. **Find the smallest edge from {A, B, C, F, E}**
   - (A-D, 6) is the smallest edge

### Final MST
- (A-B, 2), (B-C, 3), (C-F, 7), (E-F, 5), (A-D, 6)
- **Total MST Weight** = **23**

### Time Complexity

| Approach | Time Complexity |
|----------|----------------|
| Adjacency Matrix + Simple Search | O(V²) |
| Adjacency List + Min-Heap | O(E log V) |

### Limitations of Prim’s Algorithm
- Only works for **connected graphs**.
- More complex when using **priority queues**.
- Slow for **sparse graphs**, where Kruskal’s is better.


