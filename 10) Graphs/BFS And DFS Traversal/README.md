# BFS Through Queue and Vector

## Breadth-First Search (BFS)

Breadth-First Search (BFS) is an algorithm for traversing or searching a graph or tree data structure. It starts at a specified node (often called the "source" or "root") and explores all of its neighbors before moving to the next level of neighbors. In other words, BFS explores a graph layer by layer, ensuring that all nodes at the current level are processed before moving on to the next level.

---

## How BFS Works (Steps)

### Initialization:
1. Create a queue to keep track of nodes to be processed.
2. Mark the starting node as visited and enqueue it.

### Traversal:
1. While the queue is not empty:
   - Dequeue a node.
   - Process it (e.g., print it or add it to a result list).
   - Enqueue all its unvisited neighbors.
   - Mark each neighbor as visited to prevent revisiting it.

### Termination:
- The algorithm ends when the queue becomes empty, meaning all reachable nodes have been processed.

---

## Where BFS is Used

BFS is widely used in various applications due to its ability to explore all nodes at a particular depth before moving deeper. Common use cases include:

### 1. Shortest Path in an Unweighted Graph
- BFS is ideal for finding the shortest path in an unweighted graph because it explores all nodes at a given depth before moving to the next level.
- As soon as it reaches the target node, it guarantees the shortest path has been found.
- **Example**: Finding the shortest path in a maze or road network where all edges have the same weight.

### 2. Connected Components in an Undirected Graph
- BFS can be used to find all connected components in an undirected graph.
- By running BFS from an unvisited node, it will traverse the entire connected component containing that node.

### 3. Cycle Detection
- BFS can be used to detect cycles in an undirected graph by keeping track of visited nodes and checking for back edges.

### 4. Level-Order Traversal in a Tree
- In trees, BFS is known as level-order traversal because it processes nodes level by level.

### 5. Web Crawlers
- Web crawlers use BFS to traverse the web.
- Starting from a seed webpage, BFS explores all links on the current page before moving to linked pages.

### 6. Social Network Analysis
- BFS can be used to determine the degrees of separation between individuals in a social network, such as finding friends-of-friends at a given distance.

### 7. Broadcasting in Networks
- BFS is used in broadcasting information (e.g., routing protocols) where a message must be sent to all nodes in a network starting from a source.

---

## Time Complexity of BFS

The time complexity of BFS depends on how the graph is represented:

### **Adjacency List Representation:**
- The time complexity is **O(V + E)**, where:
  - **V** is the number of vertices (nodes) in the graph.
  - **E** is the number of edges.
- This is because:
  - Each vertex is processed once.
  - Each edge is explored once (when processing its starting vertex).

### **Adjacency Matrix Representation:**
- The time complexity is **O(V²)** because:
  - For each vertex, you check all possible vertices (even if there’s no edge between them).
- This results in a quadratic time complexity, which is less efficient for sparse graphs (graphs with fewer edges).

---

## Space Complexity of BFS

The space complexity of BFS is **O(V)** because it uses:
- A queue to store nodes to be processed.
- A visited list or array of size **V** to keep track of visited nodes.
- If the graph is dense (has many edges), additional space is used to store the adjacency list or matrix.

