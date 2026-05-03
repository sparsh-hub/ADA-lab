# Practical-17: Convex Hull 

### Aim
To implement the Convex Hull algorithm  and analyze its execution.

---

### Theory
The Convex Hull of a set of points is the smallest convex polygon that encloses all given points.

The Monotonic Chain algorithm (Andrew’s Algorithm) is an efficient method to compute the convex hull in O(n log n) time.

Steps involved:
- Sort all points based on x-coordinate (and y if tie)
- Build the lower hull by traversing left to right
- Build the upper hull by traversing right to left
- Remove duplicate points
- Combine both hulls to form the final convex hull

---
### Algorithm
ConvexHull(P)
Input: Set of points P
Output: Convex hull points

1. Sort points in increasing order of x-coordinate
2. Initialize empty list L (lower hull)

3. for each point p in P do
4.     while size(L) ≥ 2 and orientation(last2, last1, p) ≤ 0 do
5.         remove last point from L
6.     end while
7.     append p to L
8. end for

9. Initialize empty list U (upper hull)

10. for each point p in reverse order do
11.     while size(U) ≥ 2 and orientation(last2, last1, p) ≤ 0 do
12.         remove last point from U
13.     end while
14.     append p to U
15. end for

16. Remove last element of L and U
17. return concatenation of L and U

---

## Graph
![alt text](convex-hull.png)

### Time Complexity

 Case     :     Complexity 
 Best Case   :   O(n log n) 
 Average Case : O(n log n) 
 Worst Case  :  O(n log n) 

---

### Space Complexity
- O(n) for storing hull points

---

### Code
```

struct Point {
    int x, y;
};

int orientation(Point p, Point q, Point r) {
    return (q.y - p.y) * (r.x - q.x) -
           (q.x - p.x) * (r.y - q.y);
}

vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n <= 1) return points;

    sort(points.begin(), points.end(), [](Point a, Point b) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });

    vector<Point> lower, upper;

    for (Point p : points) {
        while (lower.size() >= 2 &&
               orientation(lower[lower.size()-2],
                           lower[lower.size()-1], p) >= 0) {
            lower.pop_back();
        }
        lower.push_back(p);
    }

    for (int i = n - 1; i >= 0; i--) {
        Point p = points[i];
        while (upper.size() >= 2 &&
               orientation(upper[upper.size()-2],
                           upper[upper.size()-1], p) >= 0) {
            upper.pop_back();
        }
        upper.push_back(p);
    }

    lower.pop_back();
    upper.pop_back();

    lower.insert(lower.end(), upper.begin(), upper.end());

    return lower;
}
```

---

### What the Code Does

- The program takes a set of 2D points as input.
- Points are sorted based on their coordinates.
- The `orientation()` function determines the turn direction of three points.
- The `convexHull()` function:
  - Builds the lower hull
  - Builds the upper hull
  - Removes unnecessary points that do not form a convex boundary
- Both hulls are merged to produce the final convex hull.
- The program outputs the points forming the convex boundary.

### Conclusion
The Monotonic Chain algorithm efficiently computes the convex hull with O(n log n) time complexity.  
It is simple to implement and works well for large datasets.  
It avoids unnecessary computations by constructing the hull using geometric properties.


## Practical-18: Fractional Knapsack 

### Aim
To implement the Fractional Knapsack algorithm using a greedy approach and analyze its execution time.

---

### Theory
The Fractional Knapsack problem is an optimization problem where the goal is to maximize total value within a given capacity.

Unlike the 0/1 Knapsack:
- Items **can be broken into fractions**
- You can take a portion of an item instead of the whole

Greedy strategy:
- Compute **value-to-weight ratio (value/weight)** for each item
- Sort items in **descending order of ratio**
- Pick items greedily:
  - Take full item if capacity allows
  - Otherwise, take fractional part


---
### Graph 
![Graph Description](fractional-knapsack.png)

---

### Algorithm
FractionalKnapsack(W, items)
Input: Capacity W, list of items (value, weight)
Output: Maximum value

1. for each item i do
2.     compute ratio[i] ← value[i] / weight[i]
3. sort items in decreasing order of ratio

4. totalValue ← 0

5. for each item i do
6.     if weight[i] ≤ W then
7.         W ← W - weight[i]
8.         totalValue ← totalValue + value[i]
9.     else
10.        totalValue ← totalValue + ratio[i] * W
11.        break
12. return totalValue

---
### Time Complexity

 Case         Complexity  
 Best Case  :  O(n log n)  
 Average Case : O(n log n)  
 Worst Case  :  O(n log n)  

---

### Space Complexity
- O(n) (for storing items)

---

### Code
```
void bubbleS(vector<pair<float,float>> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size()-i-1; j++)
        {
            float r1=a[j].first/a[j].second;
            float r2=a[j+1].first/a[j+1].second;

            if (r1<r2)
            {
                swap(a[j],a[j+1]);
            }
            
        }
    }
    
}
float knapSack(vector<pair<float,float>> &a,int capacity)
{
    bubbleS(a);
    float totalValue=0;
    //float r[5];
    for (int j = 0; j< a.size(); j++)
    {
        int value=a[j].first;
        int weight=a[j].second;

        if(capacity>=weight)
        {
            capacity-=weight;
            totalValue+=value;
        }
        else
        {
            totalValue+=((float)value/weight)*capacity;
        }
    }
    return totalValue;
}

```

---

### What the Code Does

- The program generates random items:
  - Each item has a **value** and a **weight**
- The `generateItems()` function:
  - Creates `n` items with random values and weights
- The `bubbleS()` function:
  - Sorts items based on **value-to-weight ratio** in descending order
- The `knapSack()` function:
  - Iterates through sorted items
  - Adds full item if capacity allows
  - Otherwise adds fractional value of remaining capacity
- The process is repeated **50 times** for each input size to calculate average execution time
- Execution time is measured using the `chrono` library
- The program outputs the **average time (in milliseconds)** for each input size

---

### Conclusion
The Fractional Knapsack algorithm efficiently maximizes value using a greedy approach.  
It performs well due to sorting based on value-to-weight ratio and allows partial selection of items.  
This makes it significantly more efficient than the 0/1 Knapsack for large datasets.


## Practical-21: Dijkstra’s Algorithm 

### Aim
To implement Dijkstra’s algorithm to find the shortest path from a source vertex to all other vertices in a graph and analyze its execution time.

---

### Theory
Dijkstra’s Algorithm is a **greedy algorithm** used to find the shortest path in a graph with **non-negative edge weights**.

Steps involved:
- Initialize distances from the source to all vertices as infinity
- Set distance of source vertex to 0
- Select the unvisited vertex with the smallest distance
- Update distances of its neighboring vertices
- Mark the vertex as visited
- Repeat until all vertices are processed

This implementation uses an **adjacency matrix** and a simple linear search to find the minimum distance vertex.


---

### Algorithm
Dijkstra(G, n, source)

1. for each vertex v do
2.     dist[v] ← ∞
3. dist[source] ← 0
4. while there exists unvisited vertex do
5.     u ← vertex with minimum dist
6.     mark u visited
7.     for each neighbor v of u do
8.         if dist[v] > dist[u] + weight(u,v) then
9.             dist[v] ← dist[u] + weight(u,v)

---

## Graph
![alt text](djikstra.png)

### Time Complexity

 Case          Complexity 
 Best Case   :  O(n²)     
 Average Case : O(n²)     
 Worst Case  :  O(n²)     

---

### Space Complexity
- O(n²) (adjacency matrix)
- O(n) (distance and visited arrays)

---

### Code
```
int minDist(vector<int> &vis, vector<int> &dist, int n)
{
    int minIndex = -1;
    int minValue = INF;

    for (int i = 0; i < n; i++)
    {
        //checking ki visited nhi h or dis[i] < minvlaue se
        if (!vis[i] && dist[i] < minValue)
        {
            minValue = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkastra(int v, vector<vector<int>> &cost, vector<int> &dist, int n)
{
    vector<int> vis(n,0);

   
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        dist[i] = cost[v][i];
    }

    dist[v] = 0;
    vis[v] = 1;

  
    for (int j = 0; j < n - 1; j++)
    {
        int u = minDist(vis, dist, n);
        if(u == -1) break;
        vis[u] = true;

        for (int num = 0; num < n; num++)
        {
            if (!vis[num] && cost[u][num] != INF)
            {
                if (dist[num] > dist[u] + cost[u][num])
                {
                    dist[num] = dist[u] + cost[u][num];
                }
            }
        }
    }
}

```

---

### What the Code Does

- The program generates graphs of different sizes using an adjacency matrix.
- The `generateMatrix()` function:
  - Creates a random weighted graph
  - Assigns random weights or `INF` (no edge) between vertices
- The `dijkastra()` function:
  - Initializes distance and visited arrays
  - Repeatedly selects the vertex with minimum distance
  - Updates distances of adjacent vertices
- The `minDist()` function:
  - Finds the unvisited vertex with the smallest distance
- The process is repeated **20 times** for each input size to compute average execution time.
- Execution time is measured using the `chrono` library.
- The program outputs the **average time (in milliseconds)** for each input size.

---

### Conclusion
Dijkstra’s Algorithm efficiently computes shortest paths from a source node in graphs with non-negative weights.  
Although this implementation has **O(n²)** complexity due to the adjacency matrix and linear search, it is simple and effective for dense graphs.  
Using advanced data structures like **priority queues (min-heaps)** can further optimize the performance to **O((V + E) log V)**.

## Practical-22: Prim’s Algorithm 

### Aim
To implement Prim’s algorithm to find the Minimum Spanning Tree (MST) of a graph and analyze its execution time.

---

### Theory
Prim’s Algorithm is a **greedy algorithm** used to find the Minimum Spanning Tree of a connected, weighted, undirected graph.

A Minimum Spanning Tree is a subset of edges that:
- Connects all vertices
- Has no cycles
- Has the minimum possible total edge weight

Steps involved:
- Start from any vertex (source)
- Select the minimum weight edge connecting a visited vertex to an unvisited vertex
- Add the selected edge to the MST
- Repeat until all vertices are included

This implementation uses a **priority queue (min-heap)** to efficiently select the next minimum edge.

---

### Graph
![Graph for Prim’s Algorithm](prim.png)

---

### Algorithm
### Algorithm
1. Start  
2. Input graph G(V, E) using adjacency list  
3. Initialize:  
   - Create a priority queue (min-heap) `pq`  
   - Create array `key[]` and initialize all values to ∞  
   - Create array `mstSet[]` and initialize all to false  
   - Set `key[source] = 0`  
4. Insert source vertex into priority queue  
5. While priority queue is not empty do:  
   - Extract vertex `u` with minimum key value  
   - Mark `u` as visited in `mstSet`  
   - For each adjacent vertex `v` of `u`:  
     - If `v` is not in MST and weight(u, v) < key[v]:  
       - Update `key[v] = weight(u, v)`  
       - Insert `v` into priority queue  
6. Repeat until all vertices are included in MST  
7. Stop  


---

### Time Complexity

 Case          Complexity           
 Best Case   :   O(E log V)           
 Average Case : O(E log V)           
 Worst Case  :  O(E log V)           

---

### Space Complexity
- O(V + E) (adjacency list)
- O(V) (MST set and priority queue)

---

### Code
```
void primAlgo(int V, vector<vector<pair<int,int>> >adj)
{
    vector<bool> mstSet(V, false);
   
    priority_queue< pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> >pq;
    int mstCost=0;

    pq.push({0,0}); 

    while(pq.size()>0)
    {
        auto p = pq.top();
        int wt=p.first;
        int u=p.second;
        pq.pop();

        if(!mstSet[u]){
            mstSet[u]=true;
            mstCost+=wt;

            for(int i=0; i<adj[u].size();i++){
                int v = adj[u][i].first;
                int w = adj[u][i].second;

                if(!mstSet[v])
                pq.push({w,v});
            }
        }
    }
    
}
```

---

### What the Code Does

- The program generates graphs of different sizes using adjacency lists.
- The `generateGraph()` function:
  - Creates a random undirected weighted graph
  - Assigns random weights between vertices
- The `primAlgo()` function:
  - Uses a priority queue (min-heap) to pick the smallest edge
  - Maintains a visited array (`mstSet`)
  - Adds edges to the MST while avoiding cycles
- The process is repeated **50 times** for each graph size to compute average execution time.
- Execution time is measured using the `chrono` library.
- The program outputs the **average time (in milliseconds)** for each input size.

---

### Conclusion
Prim’s Algorithm efficiently constructs a Minimum Spanning Tree using a greedy approach.  
With the use of a priority queue, it achieves a time complexity of **O(E log V)**, making it suitable for large and sparse graphs.  
It is widely used in network design, routing, and optimization problems.

## Practical-23: Kruskal’s Algorithm

### Aim
To implement Kruskal’s Algorithm to find the Minimum Spanning Tree (MST) of a graph.

---

### Theory
A Minimum Spanning Tree (MST) is a subset of edges in a weighted graph that:
- Connects all vertices
- Has no cycles
- Has the minimum possible total edge weight

Kruskal’s Algorithm is a greedy algorithm that:
- Selects edges in increasing order of weight
- Adds an edge only if it does not form a cycle

Steps involved:
- Sort all edges in increasing order of weight
- Pick the smallest edge
- Check if it forms a cycle
- If no cycle → include it in MST
- Repeat until (V - 1) edges are selected

---
### Graph 
![Graph of Kruskal](kruskal.png)

---

### Algorithm
1. Start  
2. Input graph G(V, E)  
3. Sort all edges in non-decreasing order of weight  
4. Initialize MST as empty  
5. For each edge (u, v) in sorted order do:  
   - Check if including edge forms a cycle  
   - If no cycle:  
     - Add edge (u, v) to MST  
6. Repeat until MST contains (V - 1) edges  
7. Stop  

---

### Time Complexity

 Case          Complexity 
 Best Case   :   O(E log E) 
 Average Case : O(E log E) 
 Worst Case  :  O(E log E) 

---

### Space Complexity
- O(V + E)

---

### Code
```
struct edge
{
    int u, v, weight;

    bool operator>(const edge &second) const
    {
        return weight > second.weight;
    }
};

bool isCycle(int curr, int end, vector<bool> &visit, const vector<vector<int>> &adj)
{
    if (curr == end)
    {
        return true;
    }

    visit[curr] = true;

    for (int neighbour : adj[curr])
    {
        if (!visit[neighbour])
        {
            if (isCycle(neighbour, end, visit, adj))
            {
                return true;
            }
        }
    }
    return false;
}

void kruskal(int v, const vector<edge> &edges)
{
    priority_queue<edge, vector<edge>, greater<edge>> minHeap;

    for (auto e : edges)
    {
        minHeap.push(e);
    }
    vector<vector<int>> adj(v);
    vector<edge> mst;
    int minCost = 0;

    while (!minHeap.empty() && mst.size() < v - 1)
    {
        edge currEdge = minHeap.top();
        minHeap.pop();

        vector<bool> visit(v, false);

        if (!isCycle(currEdge.u, currEdge.v, visit, adj))
        {
            mst.push_back(currEdge);
            minCost += currEdge.weight;

            adj[currEdge.u].push_back(currEdge.v);
            adj[currEdge.v].push_back(currEdge.u);
        }
    }
}
```

---

### What the Code Does

- The program defines an `edge` structure with source, destination, and weight.
- A min-heap (priority queue) is used to always pick the smallest edge.
- The `isCycle()` function:
  - Uses DFS to detect if adding an edge creates a cycle
- The `kruskal()` function:
  - Extracts edges from the min-heap
  - Checks for cycles
  - Adds valid edges to MST
  - Keeps track of total cost
- The algorithm stops when (V - 1) edges are added.

---

### Key Concept

Cycle detection using DFS:
- Before adding an edge (u, v), check if a path already exists between u and v.
- If yes → adding edge creates cycle → reject it.

---

### Output

- Prints edges included in MST
- Displays total minimum cost


---

### Conclusion
Kruskal’s Algorithm efficiently finds the Minimum Spanning Tree using a greedy approach.  
It ensures minimum total cost while avoiding cycles.  
However, cycle detection using DFS is less efficient compared to Union-Find, which is preferred for large graphs.

---
