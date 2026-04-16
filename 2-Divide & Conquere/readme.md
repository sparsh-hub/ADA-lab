### 1. Insertion Sort
* **Problem:** Sort an array by building a sorted section one element at a time, moving unsorted elements into their correct position.
* **Algorithmic Approach:** Iterate through the array starting from the second element. Compare the current element to its predecessors. Shift all larger predecessors one position to the right and insert the current element into the newly opened space.
* **Time Complexity:** $O(n^2)$ worst and average case. $O(n)$ best case (if the array is already sorted).
* **Space Complexity:** $O(1)$ — sorting is done in-place.
* **Practical Application:** Highly efficient for very small datasets or arrays that are nearly sorted. It is used in hybrid sorting algorithms like Timsort (the default sorting algorithm in Python and Java).

### 2. Binary Search
* **Problem:** Find the exact index of a target element within a **sorted** array.
* **Algorithmic Approach:** Divide and conquer. Compare the target to the middle element of the array. If the target is smaller, repeat the search on the left half; if larger, search the right half. Continue halving the search space until the target is found or the space is exhausted.
* **Time Complexity:** $O(\log n)$ — the search space is halved at every step.
* **Space Complexity:** $O(1)$ iteratively, or $O(\log n)$ recursively due to the call stack.
* **Practical Application:** The foundation of database indexing, binary search trees, and searching massive datasets where $O(n)$ linear search is too slow.

### 3. Quick Sort
* **Problem:** Sort an array efficiently using a divide-and-conquer strategy.
* **Algorithmic Approach:** Choose a "pivot" element. Partition the array so that all elements smaller than the pivot are on its left, and all larger elements are on its right. Recursively apply the same process to the left and right subarrays.
* **Time Complexity:** $O(n \log n)$ average case. $O(n^2)$ worst case (usually if the array is already sorted and the pivot is poorly chosen).
* **Space Complexity:** $O(\log n)$ for the recursive call stack.
* **Practical Application:** The default sorting algorithm in many programming languages (often modified as Introsort in C++) due to its excellent cache locality and average-case speed.

### 4. Merge Sort
* **Problem:** Sort an array reliably and stably using a divide-and-conquer strategy.
* **Algorithmic Approach:** Recursively divide the array into halves until each sub-array contains only one element. Then, repeatedly "merge" the sorted sub-arrays back together by comparing their first elements, building up a final sorted array.
* **Time Complexity:** $O(n \log n)$ in all cases (best, average, worst).
* **Space Complexity:** $O(n)$ — requires auxiliary arrays to hold the divided halves during the merge phase.
* **Practical Application:** Sorting linked lists (where it requires $O(1)$ extra space) and external sorting (sorting massive files that are too large to fit entirely into RAM).

### 10. Matrix Multiplication
* **Problem:** Multiply two matrices $A$ (size $m \times n$) and $B$ (size $n \times p$) to produce matrix $C$ (size $m \times p$).
* **Algorithmic Approach:** * *Standard:* Iterate through rows of $A$ and columns of $B$, computing the dot product for each cell.
  * *Strassen’s Algorithm:* A divide-and-conquer approach that reduces the number of recursive matrix multiplications from 8 to 7.
* **Time Complexity:** $O(n^3)$ for standard implementation. $O(n^{2.81})$ for Strassen's.
* **Space Complexity:** $O(n^2)$ to store the resulting matrix.
* **Practical Application:** The absolute core calculation in 3D graphics transformations (scaling, rotation) and Deep Learning / Neural Network training.

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