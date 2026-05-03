# Practical-10: Insertion Sort
## Aim

To implement the Insertion Sort algorithm and analyze its execution time.

## Theory

Insertion Sort is a simple sorting algorithm that works by inserting elements into their correct position in a sorted part of the array.
The array is divided into sorted and unsorted parts.
Elements from the unsorted part are picked one by one and placed at the correct position in the sorted part.
It is similar to sorting playing cards in hand.
Insertion Sort is easy to understand but inefficient for large inputs.

## Graph
![alt text](insertion-sort.png)

## Algorithm
InsertionSort(A, n)

1. for i ← 2 to n do
2.     key ← A[i]
3.     j ← i-1
4.     while j ≥ 1 and A[j] > key do
5.         A[j+1] ← A[j]
6.         j ← j-1
7.     end while
8.     A[j+1] ← key

## Time Complexity

Best Case: O(n) (already sorted array)
Average Case: O(n²)
Worst Case: O(n²) (reverse sorted array)

## Space Complexity

O(1) (in-place sorting)

## Code 
```
void insertionS(vector<int> &a,int n)
{
    for(int j=2;j<n;j++)
    {
        int key=a[j];
        int i=j-1;
        while (i>0 && a[i]>key)
        {
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=key;
    }
}
```

## What the Code Does

The program generates random elements and stores them in a vector.
The function insertionS() sorts the array:
It selects a key element.
Shifts all larger elements one position to the right.
Inserts the key at its correct position.
The execution time is measured using the chrono library.
The array size and execution time are written into insertionS.txt.

## Conclusion

Insertion Sort correctly sorts the array using a simple approach.
Although it is inefficient for large datasets, it is useful for small inputs and nearly sorted arrays.

# Practical-11: Merge Sort

### Aim
To implement the Merge Sort algorithm and analyze its execution time.

### Theory
Merge Sort is a **divide-and-conquer** sorting algorithm.  
It works by recursively dividing the array into smaller subarrays, sorting them, and then merging them back together.

The process involves:
- Dividing the array into two halves
- Recursively sorting each half
- Merging the sorted halves into a single sorted array

Unlike simple sorting algorithms, Merge Sort is efficient for large datasets due to its logarithmic division strategy.

### Algorithm
MergeSort(A, low, high)

1. if low < high then
2.     mid ← (low + high)/2
3.     MergeSort(A, low, mid)
4.     MergeSort(A, mid+1, high)
5.     Merge(A, low, mid, high)

## Graph
![alt text](merge-sort.png)

### Time Complexity

| Case        | Complexity   |
|------------|-------------|
| Best Case   | O(n log n)  |
| Average Case| O(n log n)  |
| Worst Case  | O(n log n)  |


### Space Complexity
- O(n) (requires additional space for merging)

## Code
```
void merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= end)
        temp.push_back(arr[j++]);

    for (int idx = 0; idx < temp.size(); idx++)
        arr[st + idx] = temp[idx];
}

void mergeSort(vector<int> &arr, int st, int end)
{
    if (st >= end)
        return;

    int mid = st + (end - st) / 2;
    mergeSort(arr, st, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, st, mid, end);
}
```

### What the Code Does

- The program generates arrays of different sizes.
- Each array is filled with sequential values and then shuffled randomly.
- The `mergeSort()` function:
  - Recursively divides the array into halves
  - Calls `merge()` to combine sorted subarrays
- The `merge()` function:
  - Compares elements from two halves
  - Merges them into a temporary vector in sorted order
- The sorting process is repeated **1000 times** for each input size to calculate average execution time.
- Execution time is measured using the `chrono` library.
- The program outputs the **average time (in milliseconds)** for each input size.

---

### Conclusion
Merge Sort efficiently sorts large datasets with a guaranteed time complexity of **O(n log n)**.  
Although it requires extra memory, it is significantly faster and more stable compared to algorithms like Insertion Sort for large inputs.

# Practical-14: Quick Sort

### Aim
To implement the Quick Sort algorithm and analyze its execution time.

---

### Theory
Quick Sort is a **divide-and-conquer** sorting algorithm.  
It works by selecting a **pivot element** and partitioning the array such that:
- Elements smaller than the pivot are placed on the left
- Elements greater than the pivot are placed on the right

The process is then recursively applied to the left and right subarrays.

In this implementation, the pivot is chosen as the **middle element**, and elements are rearranged around it using a custom partitioning approach.

---

### Graph
![Graph for Quick Sort](lab3/QuickSort.png)

---

### Algorithm 

---
QuickSort(A, low, high)

1. if low < high then
2.     p ← Partition(A, low, high)
3.     QuickSort(A, low, p-1)
4.     QuickSort(A, p+1, high)

---   

## Graph
![alt text](quick-sort.png)

### Time Complexity

 Case          Complexity   
 Best Case :    O(n log n)  
 Average Case : O(n log n)  
 Worst Case  :  O(n²)       

---

### Space Complexity
- O(log n) (due to recursion stack)

---

### Code
```
int partitionFunc(vector<int> &arr, int s, int e)
{
    int m = s + (e - s) / 2;
    int index = s;

    for (int i = s; i <= e; i++)
    {
        if (arr[i] < arr[m])
            index++;
    }

    swap(arr[m], arr[index]);

    int l = s;
    int h = e;

    while (l < index && h > index)
    {
        while (arr[l] < arr[index])
            l++;
        while (arr[h] > arr[index])
            h--;
        if (l < h)
        {
            swap(arr[l], arr[h]);
            l++;
            h--;
        }
    }
    return index;
}

void quickSort(vector<int> &arr, int s, int e)
{
    if (s < e)
    {
        int j = partitionFunc(arr, s, e);
        quickSort(arr, s, j - 1);
        quickSort(arr, j + 1, e);
    }
}
```

---

### What the Code Does

- The program generates arrays of different sizes.
- Each array is filled with sequential values and then shuffled randomly.
- The `quickSort()` function:
  - Selects a pivot using the `partitionFunc()`
  - Recursively sorts elements before and after the pivot
- The `partitionFunc()`:
  - Chooses the middle element as pivot
  - Places the pivot at its correct position
  - Rearranges elements such that smaller elements are on the left and larger on the right
- The sorting process is repeated **1000 times** for each input size to compute average execution time.
- Execution time is measured using the `chrono` library.
- The program outputs the **average time (in milliseconds)** for each input size.

---

### Conclusion
Quick Sort is one of the fastest sorting algorithms in practice due to its efficient partitioning strategy.  
However, its worst-case complexity is **O(n²)**, which can occur when poor pivot choices are made.  
Despite this, it performs exceptionally well on average and is widely used in real-world applications.

# Practical-15: Binary Search

### Aim
To implement the Binary Search algorithm and analyze its execution time.

---

### Theory
Binary Search is an efficient searching algorithm that works on **sorted arrays**.  
It repeatedly divides the search space into smaller parts by comparing the target element with the middle element.

Steps involved:
- Find the middle element of the array
- If the target matches the middle element, return the index
- If the target is smaller, search in the left half
- If the target is larger, search in the right half

This process continues until the element is found or the search space becomes empty.

---

### Algorithm
---
BinarySearch(A, low, high, x)
Input: Sorted array A, indices low & high, target x
Output: Index of x or -1

1. if low > high then
2.     return -1
3. mid ← (low + high) / 2
4. if A[mid] = x then
5.     return mid
6. if x < A[mid] then
7.     return BinarySearch(A, low, mid-1, x)
8. else
9.     return BinarySearch(A, mid+1, high, x)


## Graph
![alt text](bin-search.png)
---
### Time Complexity

 Case          Complexity 
 Best Case  :   O(1)      
 Average Case : O(log n)  
 Worst Case  :  O(log n)  

---

### Space Complexity
- O(log n) (due to recursion stack)

---

### Code
```
int binaryS(vector<int> &a, int s, int e, int target)
{
    while (s < e)
    {
        int m = s+(e-s)/3;

        if (a[m] == target)
            return m;
        else if (a[m] < target)
            return binaryS(a, m + 1, e, target);
        else
            return binaryS(a, s, m - 1, target);
    }
}
```

---

### What the Code Does

- The program generates arrays of different sizes.
- Each array is initially filled with sequential values.
- The array is then shuffled randomly.
- A target element is selected from the array.
- The `binaryS()` function:
  - Recursively searches for the target element
  - Divides the array into smaller parts based on comparison
- The searching process is repeated **1000 times** for each input size to calculate average execution time.
- Execution time is measured using the `chrono` library.
- The program outputs the **average time (in milliseconds)** for each input size.

---

### Conclusion
Binary Search is a highly efficient searching algorithm with **O(log n)** time complexity.  
It significantly reduces the number of comparisons compared to linear search.  
However, it requires the data to be **sorted**, which is a key limitation.

# Practical: Matrix Multiplication

### Aim
To multiply two matrices and produce a resultant matrix by performing the standard row-by-column dot product operation.

---

### Theory
Matrix Multiplication is a fundamental operation in linear algebra and computer science.

Key idea:
- Two matrices **A (m×n)** and **B (n×p)** can be multiplied only if the **number of columns of A equals the number of rows of B**
- The result is a matrix **C (m×p)**
- Each element `C[i][j]` is computed as the dot product of the i-th row of A and j-th column of B

Formula:
```
C[i][j] = Σ (A[i][k] * B[k][j])   for k = 0 to n-1
```

Properties:
- Matrix multiplication is **associative**: (AB)C = A(BC)
- Matrix multiplication is **not commutative**: AB ≠ BA in general
- It is **distributive** over addition: A(B + C) = AB + AC

---

### Algorithm
1. Start
2. Input matrix A of size m×n and matrix B of size n×p
3. Check compatibility: columns of A must equal rows of B
4. Initialize result matrix C of size m×p with all zeros
5. For i = 0 to m-1:
   - For j = 0 to p-1:
     - For k = 0 to n-1:
       - C[i][j] += A[i][k] * B[k][j]
6. Output matrix C
7. Stop

---
## Graph
![alt text](matrix-mult.png)

### Time Complexity

| Case         | Complexity |
|--------------|------------|
| Best Case    | O(n³)      |
| Average Case | O(n³)      |
| Worst Case   | O(n³)      |

> For square matrices of size n×n. General case is O(m × n × p).

---

### Space Complexity
- O(m × p) — for storing the resultant matrix C

---

### Code
```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> multiplyMatrices(vector<vector<int>>& A,
                                      vector<vector<int>>& B,
                                      int m, int n, int p) {
    // Initialize result matrix with zeros
    vector<vector<int>> C(m, vector<int>(p, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

void printMatrix(vector<vector<int>>& mat) {
    for (auto& row : mat) {
        for (int val : row)
            cout << val << "\t";
        cout << endl;
    }
}

int main() {
    
    vector<vector<int>> A = {
        {1, 2},
        {3, 4},
        {5, 6}
    };

   
    vector<vector<int>> B = {
        {7, 8, 9},
        {10, 11, 12}
    };

    int m = 3, n = 2, p = 3;

    cout << "Matrix A:" << endl;
    printMatrix(A);

    cout << "\nMatrix B:" << endl;
    printMatrix(B);

    vector<vector<int>> C = multiplyMatrices(A, B, m, n, p);

    cout << "\nResultant Matrix C = A x B:" << endl;
    printMatrix(C);

    return 0;
}
```

---

### What the Code Does

- The program defines two matrices A (3×2) and B (2×3)
- The `multiplyMatrices()` function:
  - Uses three nested loops to compute each element of the result matrix
  - Accumulates the dot product of each row of A with each column of B
- The `printMatrix()` function displays any matrix in grid format
- The program outputs:
  - Matrix A and Matrix B
  - The resulting product matrix C

---

### Sample Output
```
Matrix A:
1    2
3    4
5    6

Matrix B:
7    8    9
10   11   12

Resultant Matrix C = A x B:
27   30   33
61   68   75
95   106  117
```

---

### Conclusion
Matrix Multiplication is a core operation in fields like computer graphics, machine learning, and scientific computing.
The standard triple-loop algorithm runs in O(n³) time and is simple to implement.
Optimized algorithms like Strassen's reduce this to approximately O(n^2.81), suitable for very large matrices.
