# Practical-30: N-Queens Problem

### Aim
To solve the N-Queens problem using Backtracking and print all possible solutions.

---

### Theory
The N-Queens problem is a classic problem in computer science where the goal is to place **N queens on an N×N chessboard** such that:

- No two queens attack each other  
- No two queens are in the same row  
- No two queens are in the same column  
- No two queens are on the same diagonal  

Backtracking is used to solve this problem:
- Place queens one row at a time  
- Check if the current position is safe  
- If safe → place queen and move to next row  
- If not safe → try next column  
- If no column works → backtrack  

---

### Algorithm
1. Start  
2. Input number of queens `n`  
3. Initialize array `x[n]` to store queen positions  
4. Define function `place(k, i)`:
   - For each previous queen `j = 0 to k-1`:
     - If `x[j] == i` OR `abs(x[j] - i) == abs(j - k)`:
       - Return false  
   - Return true  
5. Define recursive function `NQueen(k, n)`:
   - For column `i = 0 to n-1`:
     - If `place(k, i)` is true:
       - Set `x[k] = i`  
       - If `k == n-1`:
         - Print solution  
       - Else:
         - Call `NQueen(k + 1, n)`  
6. Call `NQueen(0, n)`  
7. Stop  

---

## Graph
![alt text](n-queens.png)

### Time Complexity

| Case          | Complexity |
|--------------|-----------|
| Best Case    | O(n!) |
| Average Case | O(n!) |
| Worst Case   | O(n!) |

---

### Space Complexity
- O(n) (for storing positions of queens)
- O(n) (recursion stack)

---

### Code
```
bool place(int k, int i, vector<int> &x)
{
    for (int j = 0; j < k; j++)
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
        {
            return false;
        }
    }
    return true;
}

void NQueen(int k, int n, vector<int> &x)
{
    for (int i = 0; i < n; i++)
    {
        if (place(k, i, x))
        {
            x[k] = i;
            if (k == n - 1)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << x[j] << " ";
                }
                cout << endl;
            }
            else
                NQueen(k + 1, n, x);
        }
    }
}
```

---

### What the Code Does

- The program takes input `n` (number of queens).  
- Uses a vector `x[]` to store column positions of queens.  
- The `place()` function:
  - Checks if a queen can be placed safely  
  - Ensures no conflicts in column or diagonal  
- The `NQueen()` function:
  - Recursively places queens row by row  
  - Uses backtracking when a conflict occurs  
- When a valid arrangement is found:
  - The positions of queens are printed  

---

### Conclusion
The N-Queens problem is efficiently solved using Backtracking.  
It systematically explores all possible configurations and eliminates invalid ones early.  
Although the time complexity is high, it demonstrates the power of recursion and constraint-based problem solving.

## Practical-31: Sum of Subsets

### Aim
To find all subsets of a given set of weights whose sum is equal to a given target using Backtracking.

---

### Theory
The Sum of Subsets problem is a classic backtracking problem where the goal is to find all subsets whose sum equals a given value.

Given:
- A set of weights  
- A target sum `m`  

We need to:
- Find all possible subsets whose total sum equals `m`  

Backtracking approach:
- Include or exclude each element  
- Explore all possible combinations  
- Prune branches that cannot lead to a valid solution  

Bounding conditions are used to improve efficiency:
- If current sum exceeds target → stop exploring  
- If remaining elements cannot reach target → prune  

---

### Algorithm
1. Start  
2. Input number of elements `n`  
3. Input weights array `w[]`  
4. Input target sum `m`  
5. Compute total sum `r` of all elements  
6. Initialize solution array `x[]`  
7. Define function `sumofSubset(s, k, r)`:
   - Set `x[k] = 1` (include element)  
   - If `s + w[k] == m`:
     - Print current subset  
   - Else if `k+1 < n` AND `s + w[k] + w[k+1] <= m`:
     - Call `sumofSubset(s + w[k], k+1, r - w[k])`  
   - If `k+1 < n` AND `s + r - w[k] >= m` AND `s + w[k] <= m`:
     - Set `x[k] = 0` (exclude element)  
     - Call `sumofSubset(s, k+1, r - w[k])`  
8. Call `sumofSubset(0, 0, totalSum)`  
9. Stop  

---
## Graph
![alt text](sumofsubsets.png)

### Time Complexity

| Case          | Complexity |
|--------------|-----------|
| Best Case    | O(2ⁿ) |
| Average Case | O(2ⁿ) |
| Worst Case   | O(2ⁿ) |

---

### Space Complexity
- O(n) (solution vector)
- O(n) (recursion stack)

---

### Code
```
void sumofSubset(int s, int k, int r)
{
    x[k] = 1;

    if (s + w[k] == m)
    {
        for (int i = 0; i <= k; i++)
        {
            if (x[i] == 1)
            {
                cout << w[i] << " ";
            }
        }
        cout << endl;
    }
    else if (k + 1 < n && s + w[k] + w[k + 1] <= m)
    {
        sumofSubset(s + w[k], k + 1, r - w[k]);
    }

    if (k+1<n && s + r - w[k] >= m && s + w[k] <= m)
    {
        x[k] = 0;
        sumofSubset(s, k + 1, r - w[k]);
    }
}
```

---

### What the Code Does

- The program takes:
  - Number of elements `n`  
  - Weights array `w[]`  
  - Target sum `m`  
- Computes total sum of elements  
- Uses array `x[]` to track inclusion/exclusion  
- The `sumofSubset()` function:
  - Recursively explores subsets  
  - Includes/excludes elements  
  - Uses bounding conditions to prune search space  
- When a valid subset is found:
  - It prints the subset elements  

---


### Conclusion
The Sum of Subsets problem is efficiently solved using Backtracking with pruning.  
Although the worst-case time complexity is exponential, bounding conditions significantly reduce unnecessary computations.  
It demonstrates the power of recursive problem solving and constraint satisfaction.

# Practical-32: M-Coloring Problem

## Aim
To implement the M-Coloring problem using Backtracking and print all possible valid colorings of a graph.

---

## Theory
The M-Coloring problem is a graph coloring problem where we assign colors to vertices such that:

- No two adjacent vertices have the same color  
- At most `m` colors are used  

This problem is solved using **Backtracking**:
- Assign colors one by one to vertices  
- Check if the assignment is valid  
- If not valid, try another color (backtrack)  

---

## Algorithm 

1. Start  
2. Input number of vertices `n`  
3. Input number of colors `m`  
4. Input adjacency matrix `adj[1..n][1..n]`  
5. Initialize color array `x[1..n] = 0`  

6. Define function `NextValue(k)`:
   - Repeat:
     - Set `x[k] = (x[k] + 1) mod (m + 1)`  
     - If `x[k] == 0`, return  
     - For `j = 1 to n`:
       - If `adj[k][j] == 1` AND `x[k] == x[j]`, break  
     - If `j == n + 1`, return  
   - Until valid color is found  

7. Define function `mColoring(k)`:
   - Repeat:
     - Call `NextValue(k)`  
     - If `x[k] == 0`, return  
     - If `k == n`, print solution  
     - Else call `mColoring(k + 1)`  
   - Until all possibilities are explored  

8. Call `mColoring(1)`  
9. Stop  

---

## Time Complexity

| Case          | Complexity |
|--------------|-----------|
| Best Case    | O(mⁿ) |
| Average Case | O(mⁿ) |
| Worst Case   | O(mⁿ) |

---

## Graph
![alt text](graph-color.png)

## Space Complexity
- O(n) (color array)  
- O(n) (recursion stack)  

---

### Code
```
void NextValue(int k)
{
    do
    {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
        {
            return;
        }
        int j;
        for (j = 1; j <= n; j++)
        {
            if (adj[k][j] == 1 && x[k] == x[j])
            {
                break;
            }
        }
        if (j == n+1)
            return;

    } while (1);
}

void mColoring(int k)
{
    do
    {
        NextValue(k);

        if (x[k] == 0)
        {
            return;
        }
        if (k == n)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << x[i] << " ";
            }
            cout << endl;
        }
        else
            mColoring(k + 1);

    } while (1);
}
```

---

## What the Code Does

- Takes number of vertices and colors as input  
- Accepts adjacency matrix of the graph  
- Uses backtracking to assign colors to vertices  
- Ensures adjacent vertices do not share the same color  
- Prints all valid color combinations  

---

## Conclusion
- The M-Coloring problem is efficiently solved using Backtracking.
- It explores all possible color assignments while ensuring constraints are satisfied.
- Although the time complexity is high (O(mⁿ)), it guarantees all valid solutions.

# Practical-33: Hamiltonian Cycle

## Aim
To find all Hamiltonian cycles in a given graph using Backtracking.

---

## Theory
A Hamiltonian Cycle is a cycle in a graph that:

- Visits each vertex exactly once  
- Returns to the starting vertex  

The problem is to determine all such possible cycles in a given graph.

Backtracking approach:
- Start from a fixed vertex  
- Add vertices one by one  
- Ensure:
  - No vertex is repeated  
  - There exists an edge between consecutive vertices  
- Check if last vertex connects back to the first  

If constraints fail → backtrack  

---

## Algorithm 

1. Start  
2. Input number of vertices `n`  
3. Input adjacency matrix `adj[1..n][1..n]`  
4. Initialize array `x[1..n] = 0`  
5. Set starting vertex `x[1] = 1`  

6. Define function `NextValue(k)`:
   - Repeat:
     - Set `x[k] = (x[k] + 1) mod (n + 1)`  
     - If `x[k] == 0`, return  
     - If there is an edge between `x[k-1]` and `x[k]`:
       - Check for repetition:
         - For `j = 1 to k-1`:
           - If `x[j] == x[k]`, break  
       - If no repetition:
         - If `(k < n)` OR `(k == n AND edge exists between x[n] and x[1])`:
           - Return  

   - Until valid vertex is found  

7. Define function `Hamiltonian(k)`:
   - Repeat:
     - Call `NextValue(k)`  
     - If `x[k] == 0`, return  
     - If `k == n`:
       - Print Hamiltonian cycle  
     - Else:
       - Call `Hamiltonian(k + 1)`  
   - Until all possibilities are explored  

8. Call `Hamiltonian(2)`  
9. Stop  

---

## Graph
![alt text](hamiltonian.png)

## Time Complexity

| Case          | Complexity |
|--------------|-----------|
| Best Case    | O(n!) |
| Average Case | O(n!) |
| Worst Case   | O(n!) |

---

## Space Complexity
- O(n) (solution array)  
- O(n) (recursion stack)  

---

### Code
```
void NextValue(int k)
{
    do
    {
        x[k] = (x[k] + 1) % (n + 1);
        if (x[k] == 0)
        {
            return;
        }
        if (adj[x[k - 1]][x[k]] != 0)
        {
            int j;
            for (j = 1; j <= k-1; j++)
            {
                if (x[j] == x[k])
                {
                    break;
                }
            }
            if (j == k)
            {
                if (k < n || (k == n && adj[x[n]][x[1]] != 0))
                {
                    return;
                }
            }
        }

    } while (1);
}

void Hamiltonian(int k)
{
    do
    {
        NextValue(k);

        if (x[k] == 0)
        {
            return;
        }
        if (k == n)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << x[i] << " ";
            }
            cout<<x[1];
            cout << endl;
        }
        else
            Hamiltonian(k + 1);

    } while (1);
}
```

---

## What the Code Does

- Takes number of vertices and adjacency matrix as input  
- Fixes starting vertex to avoid duplicate cycles  
- Uses backtracking to generate permutations of vertices  
- Ensures:
  - No vertex is repeated  
  - Consecutive vertices are connected  
  - Last vertex connects back to first  
- Prints all Hamiltonian cycles  

---

## Conclusion 
- The Hamiltonian Cycle problem is solved using Backtracking by exploring all possible vertex permutations.
- Although the time complexity is high (O(n!)), it guarantees finding all valid cycles.
- It is a classic example of constraint-based combinatorial problems.