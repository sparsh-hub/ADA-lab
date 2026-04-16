### 11. Multistage Graph (Shortest Path)
* **Problem:** Find the shortest path from a source to a destination in a directed graph where nodes are divided into strict sequential "stages," and edges only flow from stage $i$ to stage $i+1$.
* **Algorithmic Approach:** Dynamic Programming. Work backward from the destination to the source (or forward). The shortest path to any node in stage $i$ is the minimum of the edge weight to a node in stage $i+1$ plus the already computed shortest path from that node to the destination.
* **Time Complexity:** $O(V + E)$ because each node and edge is evaluated exactly once.
* **Space Complexity:** $O(V)$ to store the shortest distance to the destination for each node.
* **Practical Application:** Resource allocation planning, tournament matching, and supply chain logistics where distinct phases occur sequentially.

### 12. Matrix Chain Multiplication
* **Problem:** Find the most efficient way to parenthesize a sequence of matrices to minimize the total number of scalar multiplications required.
* **Algorithmic Approach:** Dynamic Programming. Trying all possible parenthesizations is computationally explosive ($O(2^n)$). Instead, use a table to store the minimum cost of multiplying subsets of matrices. Try every possible split point $k$ between matrix $i$ and matrix $j$, and find the minimum cost.
* **Time Complexity:** $O(n^3)$ where $n$ is the number of matrices.
* **Space Complexity:** $O(n^2)$ to store the 2D DP table of minimum costs.
* **Practical Application:** Optimizing compilers, optimizing complex relational database queries (join orders), and large-scale scientific computing.

### 13. Find Number of Stages (in a Graph)
* **Problem:** Determine the number of hierarchical levels or stages in a Directed Acyclic Graph (DAG) or a specific multistage graph.
* **Algorithmic Approach:** Perform a Breadth-First Search (BFS) starting from the source node(s) with in-degree $0$, tracking the depth of each traversal. Alternatively, use Topological Sorting or a Depth-First Search (DFS) tracking the longest path.
* **Time Complexity:** $O(V + E)$ where $V$ is vertices and $E$ is edges.
* **Space Complexity:** $O(V)$ for the queue (BFS) or call stack (DFS).
* **Practical Application:** Analyzing project dependencies (like PERT or CPM charts) to find the "critical path" and total duration of a project.

### 14. Cycle Detection
* **Problem:** Determine if a graph contains at least one cycle (a path that starts and ends at the same vertex).
* **Algorithmic Approach:** * *Directed Graphs:* Use DFS. Keep track of nodes in the current recursive stack. If you visit a node already in the current stack, a cycle exists (a "back edge").
  * *Undirected Graphs:* Use a Disjoint Set (Union-Find). If two connected nodes already belong to the same set, a cycle is detected.
* **Time Complexity:** $O(V + E)$ for DFS.
* **Space Complexity:** $O(V)$ for the recursion stack or disjoint set arrays.
* **Practical Application:** Deadlock detection in Operating Systems, verifying that package dependencies are valid (preventing infinite loops in build tools like npm), and detecting infinite loops in routing protocols.