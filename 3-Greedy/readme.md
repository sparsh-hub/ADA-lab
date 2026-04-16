### 5. Convex Hull
* **Problem:** Find the smallest convex polygon that encloses a given set of points in a 2D plane (imagine stretching a rubber band around a set of pegs).
* **Algorithmic Approach:** Common methods include **Graham Scan** (sort points by polar angle and push/pop to a stack based on left/right turns) or **Jarvis March** (a gift-wrapping approach, finding the outermost points one by one).
* **Time Complexity:** $O(n \log n)$ for Graham Scan (dominated by sorting). $O(nh)$ for Jarvis March, where $h$ is the number of points on the hull.
* **Space Complexity:** $O(n)$ to store the points on the hull.
* **Practical Application:** Collision detection in game development and robotics, pattern recognition, and Geographic Information Systems (GIS).

### 6. Dijkstra's Algorithm
* **Problem:** Find the shortest path from a single starting node to all other nodes in a graph with non-negative edge weights.
* **Algorithmic Approach:** Greedy approach. Maintain a set of unvisited nodes and their tentative distances from the source (initially infinity). Continuously pick the unvisited node with the smallest distance, then "relax" its neighbors by calculating if the path through the current node is shorter than the known path.
* **Time Complexity:** $O((V + E) \log V)$ when implemented using a Min-Priority Queue (where $V$ is vertices, $E$ is edges).
* **Space Complexity:** $O(V)$ to store distances and the priority queue.
* **Practical Application:** GPS navigation systems finding the fastest driving route, and routing protocols (like OSPF) in computer networks.

### 7. Kruskal's Algorithm
* **Problem:** Find the Minimum Spanning Tree (MST) of a connected, undirected graph (connecting all vertices with the minimum total edge weight).
* **Algorithmic Approach:** Greedy approach. Sort all edges in ascending order of their weight. Iterate through the sorted edges and add them to the MST, provided that adding the edge does not form a cycle (checked efficiently using a Disjoint Set / Union-Find data structure).
* **Time Complexity:** $O(E \log E)$ or $O(E \log V)$ dominated by the time required to sort the edges.
* **Space Complexity:** $O(V)$ for the Disjoint Set data structure.
* **Practical Application:** Laying out telecommunication networks, electrical grids, or water supply pipelines with the minimum amount of material.

### 8. Prim's Algorithm
* **Problem:** Find the Minimum Spanning Tree (MST) of a connected, undirected graph.
* **Algorithmic Approach:** Greedy approach. Start with a single arbitrary node. At each step, find the edge with the minimum weight that connects a node *inside* the growing tree to a node *outside* the tree. Add that edge and node to the tree, often managed via a Min-Priority Queue.
* **Time Complexity:** $O((V + E) \log V)$ using a Min-Priority Queue.
* **Space Complexity:** $O(V + E)$ for the priority queue and adjacency list.
* **Practical Application:** Similar to Kruskal's, but Prim's is generally faster and preferred for **dense** graphs (graphs with many edges).

### 9. Fractional Knapsack
* **Problem:** Maximize the total value of items placed into a knapsack of capacity $W$, where items can be broken into fractional parts.
* **Algorithmic Approach:** Greedy approach. Calculate the value-to-weight ratio for each item. Sort items in descending order based on this ratio. Add whole items to the knapsack until full, then take a fraction of the next highest-ratio item to completely fill the capacity.
* **Time Complexity:** $O(n \log n)$ due to the sorting step.
* **Space Complexity:** $O(1)$ auxiliary space if sorting in-place.
* **Practical Application:** Resource allocation problems where materials are continuous (like liquids, grains, or computing power/bandwidth).