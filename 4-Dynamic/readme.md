# Practical-24: Matrix Chain Multiplication 

### Aim
To determine the most efficient way to multiply a chain of matrices using Dynamic Programming and minimize the number of scalar multiplications.

---

### Theory
Matrix Chain Multiplication (MCM) is an optimization problem that determines the best way to multiply a sequence of matrices.

Key idea:
- Matrix multiplication is **associative**, meaning the order of multiplication can be changed
- However, different orders result in **different computational costs**

Steps involved:
- Break the problem into smaller subproblems
- Compute minimum multiplication cost for each subchain
- Store results in a table to avoid recomputation (Dynamic Programming)
- Reconstruct the optimal parenthesization


---

### Algorithm
1. Start  
2. Input array p[] of matrix dimensions  
3. Let n = number of matrices  
4. Create table m[n][n] and initialize m[i][i] = 0  
5. For chain length L = 2 to n:  
   - For i = 1 to n-L+1:  
     - j = i + L - 1  
     - m[i][j] = ∞  
     - For k = i to j-1:  
       - Compute cost = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]  
       - If cost < m[i][j], update m[i][j]  
6. Output m[1][n]  
7. Stop  

---

## Graph
![alt text](MCM.png)

### Time Complexity

 Case          Complexity 
 Best Case   :   O(n³)     
 Average Case : O(n³)     
 Worst Case  :  O(n³)     

---

### Space Complexity
- O(n²) (for cost and split tables)

---

### Code
```
void printParenthesis(int i,int j,int s[10][10])
{
    if (i==j)
    {
        cout<<"A"<<i;
    }
    else
    {
        cout<<"(";
        printParenthesis(i,s[i][j],s);
        printParenthesis(s[i][j]+1,j,s);
        cout<<")";
    }
    
}
void MCM(int n, int p[])
{
    int m[10][10];
    int s[10][10];
    int i,j;

    for (int i = 0; i < n; i++)
    {
        m[i][i]=0;
    }
    
    for (int l = 2; l < n; l++)
    {
        for ( i = 1; i < n - l + 1; i++)
        {
             j = i + l - 1;
            m[i][j] = INF;
            for (int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout<<"Minimum number of multiplications: "<<m[1][n-1];   

    cout<<"\nparenthesis: ";
    printParenthesis(1,n-1,s);
    cout<<endl;
}
```

---

### What the Code Does

- The program defines an array `p[]` representing matrix dimensions
  - If there are `n` matrices, the array size is `n+1`
- The `MCM()` function:
  - Uses Dynamic Programming to compute minimum multiplication cost
  - Stores results in matrix `m[][]`
  - Stores optimal split positions in matrix `s[][]`
- The `printParenthesis()` function:
  - Recursively prints the optimal parenthesization of matrices
- The program outputs:
  - Minimum number of scalar multiplications
  - Optimal order of multiplication

---

### Conclusion
Matrix Chain Multiplication efficiently determines the optimal order of matrix multiplication using Dynamic Programming.  
It reduces redundant computations and ensures the minimum number of operations with a time complexity of **O(n³)**.  
This approach is widely used in compiler optimization and mathematical computations.

## Practical-25: Multistage Graph 

### Aim
To find the minimum cost path in a multistage graph using forward and backward dynamic programming approaches.

---

### Theory
A Multistage Graph is a directed acyclic graph (DAG) divided into multiple stages, where:
- Each node belongs to a specific stage
- Edges exist only from one stage to the next

The goal is to find the **minimum cost path** from the source (first stage) to the destination (last stage).

Two approaches are used:

#### Forward Approach
- Start from the destination node
- Move backward stage by stage
- Compute minimum cost to reach the destination

#### Backward Approach
- Start from the source node
- Move forward stage by stage
- Compute minimum cost to reach each node

Both approaches use **Dynamic Programming** to store intermediate results and avoid recomputation.

---

### Algorithm
1. Start  
2. Input graph with stages  
3. Initialize cost[n] = 0  
4. For i = n-1 to 1 do:  
   - cost[i] = min(cost[j] + weight(i,j))  
5. Output cost[1]  
6. Stop  

---

## Graph
![alt text](multistage.png)

### Time Complexity

 Case         Complexity 
 Best Case   :   O(n²)     
 Average Case : O(n²)     
 Worst Case  :  O(n²)     

---

### Space Complexity
- O(n²) (cost matrix)
- O(n) (cost and decision arrays)

---

### Code
```
int findStages(int c[][MAX], int n)
{
    int stage[MAX];

    stage[n] = 1;

    for (int i = n - 1; i >= 1; i--)
    {
        int maxStage = 0;

        for (int j = i + 1; j <= n; j++)
        {
            if (c[i][j] != 0)
            {
                if (stage[j] > maxStage)
                    maxStage = stage[j];
            }
        }

        stage[i] = maxStage + 1;
    }

    return stage[1];
}
void forwardGraph(int c[][10], int n, int k)
{
    int cost[10], d[10];

    cost[n] = 0;

    for (int j = n - 1; j >= 1; j--)
    {
        cost[j] = INT_MAX;

        for (int r = j + 1; r <= n; r++)
        {
            if (c[j][r] != 0)
            {
                if (cost[r]!= INT_MAX && c[j][r] + cost[r] < cost[j])
                {
                    cost[j] = c[j][r] + cost[r];
                    d[j] = r;
                }
            }
        }
    }
    cout << "Minimum Cost: " << cost[1] << endl;
}

void backwardGraph(int c[][10], int n, int k)
{
    int cost[10], d[10];

    cost[1] = 0;
    for (int j = 2; j <= n; j++)
    {
        cost[j] = INT_MAX;

        for (int r = 1; r < j; r++)
        {
            if ( c[r][j] != 0)
            {
                if (cost[r]!= INT_MAX && c[r][j] + cost[r] < cost[j])
                {
                    cost[j] = c[r][j] + cost[r];
                    d[j] = r;
                }
            }
        }
    }
    cout << "Minimum Cost for Bgraph: " << cost[n] << endl;
}
```

---

### What the Code Does

- The program takes the number of vertices as input.
- A random cost adjacency matrix is generated:
  - Only forward edges are allowed (upper triangular matrix)
  - Some edges are assigned zero (no connection)
- The `findStages()` function:
  - Determines the number of stages in the graph
- The `forwardGraph()` function:
  - Computes minimum cost from source to destination using backward traversal
- The `backwardGraph()` function:
  - Computes minimum cost from source using forward traversal
- The program outputs:
  - Generated cost matrix
  - Minimum cost using forward approach
  - Minimum cost using backward approach

---

### Conclusion
The Multistage Graph approach efficiently solves shortest path problems in staged graphs using Dynamic Programming.  
Both forward and backward methods provide optimal solutions while reducing redundant calculations.  
This technique is widely used in scheduling, resource allocation, and decision-making problems.


## Practical-26: All-Pairs Shortest Path

### Aim
To implement the Floyd–Warshall algorithm to find the shortest paths between all pairs of vertices in a graph.

---

### Theory
The All-Pairs Shortest Path problem finds the shortest distance between every pair of vertices in a graph.

The Floyd–Warshall algorithm is a dynamic programming approach that:
- Considers each vertex as an intermediate node
- Updates shortest paths by checking if a shorter path exists via that node

Steps involved:
- Initialize the distance matrix
- For each vertex k:
  - Update all pairs (i, j)
  - Check if path i → k → j is shorter than i → j
- Repeat for all vertices

---

### Algorithm
1. Start  
2. Initialize distance matrix d[][]  
3. For k = 1 to n:  
   - For i = 1 to n:  
     - For j = 1 to n:  
       - d[i][j] = min(d[i][j], d[i][k] + d[k][j])  
4. Output matrix  
5. Stop  

---

## Graph
![alt text](floyd-warshall.png)

### Time Complexity

| Case         | Complexity |
|-------------|-----------|
| Best Case    | O(n³) |
| Average Case | O(n³) |
| Worst Case   | O(n³) |

---

### Space Complexity
- O(n²) for distance matrix

---

### Code
```
void allpairShort(vector<vector<int>>& dist, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}
```

---

### What the Code Does

- The program initializes a graph using an adjacency matrix.
- `INF` represents no direct path between nodes.
- The `allpairShort()` function:
  - Uses three nested loops
  - Updates shortest distances using intermediate nodes
- The algorithm gradually improves all shortest paths.
- The final matrix shows shortest distances between every pair of vertices.

---

### Key Formula
- d[i][j] = min(d[i][j], d[i][k] + d[k][j])

### Conclusion
The Floyd–Warshall algorithm successfully computes the shortest paths between all pairs of vertices in a graph using a dynamic programming approach.  
It systematically improves the distance matrix by considering each vertex as an intermediate node.  
Although its time complexity is O(n³), it is simple to implement and effective for dense graphs.

## Practical-27: Longest Common Subsequence (LCS)

### Aim
To implement the Longest Common Subsequence (LCS) algorithm using Dynamic Programming and print the subsequence.

---

### Theory
The Longest Common Subsequence (LCS) problem is to find the longest subsequence common to two sequences.

A subsequence:
- Maintains the order of elements
- Does not require elements to be contiguous

Dynamic Programming is used to:
- Break the problem into smaller subproblems
- Store results in a table to avoid recomputation

The algorithm builds a table that stores lengths of LCS for substrings and then reconstructs the sequence.

---

### Algorithm

1. Start
2. Input two strings X and Y
3. Let m = length of X, n = length of Y
4. Create two tables:
   - c[m+1][n+1] for lengths
   - p[m+1][n+1] for path tracking
5. Initialize first row and column with 0
6. For i from 1 to m:
   - For j from 1 to n:
     - If X[i-1] == Y[j-1]:
       c[i][j] = 1 + c[i-1][j-1]
       p[i][j] = 'D'
     - Else if c[i-1][j] >= c[i][j-1]:
       c[i][j] = c[i-1][j]
       p[i][j] = 'U'
     - Else:
       c[i][j] = c[i][j-1]
       p[i][j] = 'L'
7. LCS length = c[m][n]
8. Use recursive function to print LCS using table p
9. Stop

---

## Graph
![alt text](LCS.png)

### Time Complexity

| Case         | Complexity |
|-------------|-----------|
| Best Case    | O(m × n) |
| Average Case | O(m × n) |
| Worst Case   | O(m × n) |

---

### Space Complexity
- O(m × n) for DP tables

---

### Code
```
void LCS(string X, string Y)
{
    int m = X.size();
    int n = Y.size();

    c.resize(m + 1, vector<int>(n + 1));
    p.resize(m + 1, vector<char>(n + 1));
    c[0][0]=0;

    for (int i = 1; i <= m; i++)
    {
        c[i][0] = 0;
    }
    for (int j = 1; j <= n; j++)
    {
        c[0][j] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i-1] == Y[j-1])
            {
                c[i][j] = 1 + c[i - 1][j - 1];
                p[i][j] = 'D';
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
                p[i][j]='U';
            }
            else{
                c[i][j]=c[i][j-1];
                p[i][j]='L';
            }
        }
    }
}
void write(string X, int i, int j)
{
     if (i == 0 || j == 0)
        return;

    if (p[i][j] == 'D')
    {
        write(X, i - 1, j - 1);
        cout << X[i - 1] << " ";
    }
    else if (p[i][j] == 'U')
    {
        write(X, i - 1, j);
    }
    else
    {
        write(X, i, j - 1);
    }  
}

```

---

### What the Code Does

- The program takes two input strings.
- It builds a DP table to store lengths of common subsequences.
- A direction table is maintained to reconstruct the sequence.
- The LCS length is printed from the table.
- The actual LCS is printed using recursion.

---

### Key Formula
c[i][j] = 1 + c[i-1][j-1]   (if characters match)  
c[i][j] = max(c[i-1][j], c[i][j-1])   (otherwise)

---

### Conclusion
The Longest Common Subsequence problem is efficiently solved using Dynamic Programming.
The algorithm computes the length of the longest subsequence and reconstructs it using a direction table.
Although the time complexity is O(m × n), it is practical and widely used in applications like DNA sequence analysis and text comparison.

## Practical-28: 0/1 Knapsack using Dynamic Programming

### Aim
To implement the 0/1 Knapsack problem using Dynamic Programming and analyze its execution time.

---

### Theory
The 0/1 Knapsack problem is a classic optimization problem where we are given:
- A set of items, each with a weight and value
- A knapsack with a fixed capacity

The objective is to maximize the total value such that the total weight does not exceed the capacity.

In 0/1 Knapsack:
- Each item can either be included (1) or excluded (0)
- Fractional selection is not allowed

Dynamic Programming is used to:
- Break the problem into smaller subproblems
- Store intermediate results to avoid recomputation

---
### Graph 
![Graph Description](lab9\KnapSackDP.png)

---
### Algorithm

1. Start
2. Input number of items n and capacity W
3. Initialize DP table dp[n+1][W+1] with 0
4. For each item i from 1 to n:
   - For each capacity w from 1 to W:
     - If wt[i-1] <= w:
       dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w])
     - Else:
       dp[i][w] = dp[i-1][w]
5. Store result in dp[n][W]
6. Repeat for multiple runs to calculate average execution time
7. Print average time for each input size
8. Stop

---

## Graph
![alt text](0-1Knapsack.png)

### Time Complexity

| Case         | Complexity |
|-------------|-----------|
| Best Case    | O(n × W) |
| Average Case | O(n × W) |
| Worst Case   | O(n × W) |

---

### Space Complexity
- O(n × W) for DP table

---

### Code
```
int knapsack(int W, vector<int>& wt, vector<int>& val, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (wt[i - 1] <= w)
            {
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

void generateItems(int n, vector<int>& wt, vector<int>& val)
{
    wt.clear();
    val.clear();

    for (int i = 0; i < n; i++)
    {
        wt.push_back(rand() % 50 + 1);
        val.push_back(rand() % 100 + 1);
    }
}
```

---

### What the Code Does

- The program generates random weights and values for items.
- It uses a DP table to compute the maximum achievable value.
- The knapsack() function uses a bottom-up dynamic programming approach.
- The algorithm is executed multiple times for each input size.
- Execution time is measured using the chrono library.
- The average time for each input size is printed.

---

### Key Formula
dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w])

---

### Conclusion
The 0/1 Knapsack problem is efficiently solved using Dynamic Programming by storing intermediate results in a table.
The algorithm guarantees an optimal solution but has pseudo-polynomial time complexity O(n × W), as it depends on both number of items and capacity.
The experimental results show that execution time increases as input size and capacity increase.




# Practical-32: Travelling Salesman Problem (TSP)

## Aim
To find the minimum cost tour that visits all cities exactly once and returns to the starting city.

---

## Theory
The Travelling Salesman Problem (TSP) is a classic optimization problem where:

- A salesman must visit all cities exactly once  
- Return to the starting city  
- Minimize the total travel cost  
 

###  Dynamic Programming (Bitmasking)
- Use bitmask to represent visited cities  
- Store intermediate results to avoid recomputation  
- Build solution iteratively  

---


## Algorithm (Dynamic Programming - Bitmasking)

1. Start  
2. Input number of cities `n`  
3. Input cost matrix `cost[n][n]`  
4. Define `VISITED_ALL = 2ⁿ`  
5. Create DP table `dp[mask][i]`:
   - `mask` represents visited cities  
   - `i` represents current city  
6. Initialize:
   - `dp[1][0] = 0`  
7. For each `mask` from `1` to `VISITED_ALL - 1`:
   - For each city `j`:
     - If `j` is included in `mask`:
       - For each city `k` not in `mask`:
         - Update:
           - `dp[mask | (1 << k)][k] = min(dp[mask | (1 << k)][k], dp[mask][j] + cost[j][k])`  

8. Compute answer:
   - `min(dp[VISITED_ALL - 1][i] + cost[i][0])`  

9. Stop  

---

## Graph
![alt text](TSP.png)

## Time Complexity

---

### Dynamic Programming
| Case          | Complexity |
|--------------|-----------|
| Best Case    | O(n² · 2ⁿ) |
| Average Case | O(n² · 2ⁿ) |
| Worst Case   | O(n² · 2ⁿ) |

---

## Space Complexity
 
- Dynamic Programming: O(n · 2ⁿ)  

---

### Code
```
int tsp_dp(int n, vector<vector<int>>& cost) {
    int VISITED_ALL = 1 << n;
    vector<vector<int>> dp(VISITED_ALL, vector<int>(n, INT_MAX));

    dp[1][0] = 0;

    for (int i = 1; i < VISITED_ALL; i++) {
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) == 0) continue;
            for (int k = 0; k < n; k++) {
                if ((i & (1 << k)) != 0) continue;
                int newMask = i | (1 << k);
                dp[newMask][k] = min(dp[newMask][k], dp[i][j] + cost[j][k]);
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[VISITED_ALL - 1][i] + cost[i][0]);
    }
    return ans;
}
```

---

## What the Code Does

- Defines a cost matrix representing distances between cities  
- Uses Dynamic Programming with bitmasking  
- Tracks visited cities using binary representation  
- Computes minimum cost tour efficiently  
- Returns minimum travel cost  

---

## Conclusion
- The Travelling Salesman Problem is a fundamental optimization problem.
- Backtracking guarantees optimal solution but is inefficient (O(n!))
- Dynamic Programming significantly improves performance to O(n²·2ⁿ)
- It is widely used in logistics, routing, and network optimization problems.


