# PRACTICAL - 1

## Aim
To implement Horner’s method using recursion to represent a polynomial expression efficiently.

## Theory
Horner’s method is an efficient technique used to represent and evaluate polynomials.
It reduces the number of multiplications required by rewriting the polynomial in a nested form.
This approach improves efficiency and simplifies polynomial evaluation.

## Algorithm

1. Start
2. Input coefficients
3. If last element → print
4. Else:
   print "("
   recursive call
   print "x + coefficient"
   print ")"
5. Stop

## Graph
![alt text](horner.png)
   
## Time Complexity

O(n), where n is the number of coefficients

## Space Complexity

O(n) due to recursive function calls

## Code
```
void hornor(int k, int m, vector<int> &a)
{

    if(k==m-1)
    {
        cout<<a[k];
        return;
    }
    cout<<"(";
    hornor(k+1,m,a);
    cout<<"x + "<<a[k]<<")";
}
```
## What the Code Does

This program prints the polynomial expression using Horner’s method through recursion.

The hornor(k, m, a) function recursively processes the coefficients of the polynomial stored in the vector a.
When the last coefficient is reached, it is printed and the recursion stops.

For each recursive call, the function prints an opening parenthesis and calls itself for the next coefficient.
After returning from recursion, it prints "x + " followed by the current coefficient and a closing parenthesis.

In the main() function, the number of coefficients is taken as input from the user.
The coefficients are stored in a vector and passed to the recursive function.

The output represents the polynomial in nested Horner’s form.

## Conclusion

Horner’s method provides an efficient way to represent and evaluate polynomials.
Using recursion, the polynomial is expressed in a clean and optimized nested format, reducing computational complexity compared to the standard polynomial form.

# PRACTICAL - 2
## Aim
To implement the Linear Search algorithm using recursion and measure the time taken to search for a key element.

## Theory
Linear Search is a simple searching algorithm that checks each element of the list sequentially until the desired element is found or the list ends.
In the recursive approach, the function compares the current element with the target value.
If a match is found, the index is returned.
Otherwise, the function calls itself for the next index.

This method is easy to understand but inefficient for large datasets.

## Algorithm
1. Start
2. Input array and target
3. If index >= n → return -1
4. If a[index] == target → return index
5. Else call function with next index
6. Stop

## Graph
![alt text](lin-search.png)
   
## Time Complexity

Best Case: O(1) (key found at first position)
Average Case: O(n)
Worst Case: O(n)

## Space Complexity

O(n) due to recursive function calls

## Code
```
int linearS(vector<int> &a, int target, int j)
{
  if (j == a.size())
    return -1;
  if (a[j] == target)
    return j;
  else
  {
    return linearS(a, target, j + 1);
  }
}
```
## What the Code Does

This program searches for a key element in a list of randomly generated numbers using recursive Linear Search.
The linearS(a, target, j) function recursively checks each element of the vector starting from index j.
If the index reaches the end of the vector, the function returns −1, indicating the key is not found.
If the current element matches the target, the index is returned.
Otherwise, the function calls itself with the next index.

In the main() function, the number of elements is taken as input from the user.
Random numbers are generated and stored in a vector.
A random key value is selected for searching.

The time taken for the search operation is measured using the chrono library and displayed in nanoseconds along with the index result.

## Conclusion

Linear Search successfully finds the target element if it exists in the list.
Although simple to implement, it is inefficient for large datasets due to its linear time complexity.
The recursive approach demonstrates the use of recursion in searching algorithms.

# PRACTICAL - 3

## Aim
To generate all possible permutations of a given string using recursion and backtracking.

## Theory
Permutation generation is the process of arranging the elements of a string in all possible orders.
For a string of length n, the total number of permutations is n!.

This program uses recursion with backtracking to generate permutations.
At each recursive step, the algorithm fixes one character and recursively permutes the remaining characters.
After each recursive call, the original order is restored using backtracking.

## Algorithm
1. Start
2. If k == n → print string
3. Else:
   For i = k to n-1:
      swap
      recursive call
      swap back
4. Stop

## Graph
![alt text](permutations.png)
   
## Time Complexity

O(n!), where n is the number of characters

## Space Complexity

O(n) due to recursive call stack

## Code 
```
void permGen(vector<char> &a,int k,int n)
{
    if(k==n) 
    {
        for (char c : a)
            cout << c;
        cout << endl;
        return;
    }
    else{
        for(int i=k;i<n;i++)
        {
            swap(a[i],a[k]);
            permGen(a,k+1,n);
            swap(a[i],a[k]);
        }
    }
} 
```
### Use Cases
- Anagram generation
- Combinatorial problems
- Testing all possible arrangements


## What the Code Does
This program generates and prints all permutations of a string entered by the user.

The permGen(a, k, n) function generates permutations recursively.
If k == n, a complete permutation is formed and printed.
Otherwise, the function iterates from index k to n − 1, swapping the current character with each subsequent character.

After each swap, the function calls itself for the next position (k + 1).
Once the recursive call returns, the characters are swapped back to restore the original order.
This backtracking step ensures all permutations are generated without duplication.
  In the main() function, the number of characters and the string are taken as input from the user.
  The recursive function is then called to display all possible permutations.

## Conclusion
The program successfully generates all permutations of a string using recursion and backtracking.
Although the algorithm is computationally expensive due to factorial time complexity, it is effective for small input sizes and demonstrates the concept of recursive backtracking clearly.

SHere are the README structures for the requested practicals, formatted to match the exact style and detail level of your Tower of Hanoi example.

---

# PRACTICAL - Missing Number in a Sequence

## Aim
To find the missing number in a given sequence of integers from 1 to N.

## Theory
Finding a missing number in a sequence is a classic array problem that can be optimized using mathematical principles. 
If an array contains $N-1$ distinct integers in the range of 1 to $N$, exactly one number is missing. 

Instead of searching for the number iteratively, which can be time-consuming, we can use the mathematical formula for the sum of the first $N$ natural numbers: $S = N(N + 1) / 2$. By subtracting the actual sum of the array's elements from this expected sum, the difference reveals the missing number.

## Algorithm
findMissing(arr, N)

1. Calculate the expected sum: expected_sum = N * (N + 1) / 2
2. Initialize actual_sum = 0
3. For each element i in arr:
4.     actual_sum = actual_sum + i
5. missing_number = expected_sum - actual_sum
6. return missing_number

## Graph
![alt text](missing-num.png)

## Time Complexity
O(N), where N is the size of the array.

## Space Complexity
O(1), as no extra space is required.

## Code
```cpp
int findMissingNumber(int arr[], int n) {
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;
    
    for(int i = 0; i < n - 1; i++) {
        actualSum += arr[i];
    }
    
    return expectedSum - actualSum;
}
```

### Use Cases
- Data validation and integrity checks.
- Identifying missing packets in network transmissions.
- Finding sequential gaps in database indexing.

## What the Code Does
This program mathematically computes the missing element in a sequence. 
The function `findMissingNumber(arr, n)` first computes what the sum of numbers from 1 to `n` should be. 
It then loops through the provided array (which contains `n-1` elements) to compute the actual sum of the elements present.
Finally, it subtracts the actual sum from the expected sum and returns the result, which is guaranteed to be the missing sequence number.

## Conclusion
The missing number problem is efficiently solved in linear time using a straightforward mathematical formula, bypassing the need for sorting or nested loops and demonstrating the power of math in algorithm optimization.

---

# PRACTICAL - Permutation Generation of Binary Strings

## Aim
To generate all possible binary strings of a given length $n$ using recursion and backtracking.

## Theory
Generating all permutations of binary strings is an excellent demonstration of exploring a state-space tree. 
A binary string of length $n$ can have $2^n$ possible combinations, as each position in the string can be filled with either a '0' or a '1'.

The recursive approach involves moving through each index of an array. At each index, we branch into two paths: one where the current element is set to '0', and one where it is set to '1'. This process continues until we reach the end of the string (the base case).

## Algorithm
generateBinary(n, arr, i)

1. if i == n then
2.     print arr
3.     return
4. arr[i] = 0
5. generateBinary(n, arr, i + 1)
6. arr[i] = 1
7. generateBinary(n, arr, i + 1)

## Graph
![alt text](BTT.png)

## Time Complexity
O(2ⁿ), where n is the length of the binary string.

## Space Complexity
O(n) due to the recursive call stack.

## Code
```cpp
void generateBinary(int n, int arr[], int i) {
    if (i == n) {
        for (int j = 0; j < n; j++) {
            cout << arr[j];
        }
        cout << endl;
        return;
    }
    
    arr[i] = 0;
    generateBinary(n, arr, i + 1);
    
    arr[i] = 1;
    generateBinary(n, arr, i + 1);
}
```

### Use Cases
- Generating truth tables.
- Exhaustive search algorithms.
- Bitmask generation for subset problems.

## What the Code Does
This program prints every possible binary sequence for a given length `n`.
The `generateBinary(n, arr, i)` function uses `i` to track the current position in the array. 

If `i` equals `n`, it means the array is fully populated, so it prints the current sequence and returns.
Otherwise, it sets the current index to 0 and recursively calls itself to fill the remaining positions. 
Once that recursive call finishes (backtracking), it changes the current index to 1 and makes another recursive call. 
This ensures every combination is systematically explored.

## Conclusion
Permutation generation relies heavily on recursion and backtracking to exhaustively explore all possible states. While it has exponential time complexity, it provides the foundational logic for solving complex combinatorial problems.

---

# PRACTICAL - Power (Iterative)

## Aim
To calculate the power of a number (x^y) using an iterative approach.

## Theory
Calculating the power of a base number `x` raised to an exponent `y` means multiplying `x` by itself `y` times. 
The simplest way to compute this is by using a loop that runs `y` times, maintaining a running product. 

While simple, this linear iterative approach forms the foundation for understanding computational loops and state accumulation before moving on to more optimized methods.

## Algorithm
powerIterative(x, y)

1. Initialize result = 1
2. Loop i from 1 to y:
3.     result = result * x
4. return result

## Graph
![alt text](power-iter.png)

## Time Complexity
O(y), where y is the exponent.

## Space Complexity
O(1), as it uses a constant amount of memory.

## Code
```cpp
long long powerIterative(int x, int y) {
    long long result = 1;
    for (int i = 0; i < y; i++) {
        result *= x;
    }
    return result;
}
```

### Use Cases
- Basic arithmetic operations in software.
- Simple interest / compound interest calculations for small time periods.
- Introduction to loops and accumulators in programming.

## What the Code Does
This program calculates $x^y$ sequentially. 
The function `powerIterative(x, y)` initializes a variable `result` to 1. 
It then enters a `for` loop that iterates exactly `y` times. In each iteration, it multiplies the current `result` by the base `x`. 
Once the loop terminates, it returns the accumulated result. 

## Conclusion
The iterative approach to calculating power is intuitive and uses no extra memory stack. However, for very large exponents, it becomes inefficient compared to divide-and-conquer techniques.

---

# PRACTICAL - Power (Recursive / Divide & Conquer)

## Aim
To calculate the power of a number (x^y) efficiently using the Divide and Conquer strategy.

## Theory
The Divide and Conquer algorithm drastically reduces the number of multiplications needed to calculate $x^y$. 
Instead of multiplying `x` by itself `y` times, we divide the problem in half. 
We know that mathematically:
- If y is even: $x^y = x^{y/2} * x^{y/2}$
- If y is odd: $x^y = x * x^{y/2} * x^{y/2}$

By calculating $x^{y/2}$ only once and reusing it, we cut the problem size in half at each recursive step, leading to logarithmic time complexity.

## Algorithm
powerRecursive(x, y)

1. if y == 0 then return 1
2. temp = powerRecursive(x, y / 2)
3. if y % 2 == 0 then
4.     return temp * temp
5. else
6.     return x * temp * temp

## Graph
![alt text](power-recur.png)

## Time Complexity
O(log y), where y is the exponent.

## Space Complexity
O(log y) due to the recursive call stack.

## Code
```cpp
long long powerRecursive(int x, int y) {
    if (y == 0) return 1;
    
    long long temp = powerRecursive(x, y / 2);
    
    if (y % 2 == 0) {
        return temp * temp;
    } else {
        return x * temp * temp;
    }
}
```

### Use Cases
- Cryptography (e.g., RSA encryption relies heavily on modular exponentiation).
- Computer graphics algorithms.
- Fast computations in scientific calculators.

## What the Code Does
This program efficiently computes exponential values. 
The `powerRecursive(x, y)` function first checks the base case: if the exponent `y` is 0, it returns 1. 
Otherwise, it makes a single recursive call to calculate the power of `x` raised to `y/2`, storing it in `temp`. 

It then checks if the exponent is even or odd. If even, it simply squares `temp`. If odd, it squares `temp` and multiplies it by one additional `x`. This avoids redundant calculations.

## Conclusion
The Divide and Conquer approach optimizes exponentiation significantly, reducing linear time complexity to logarithmic time complexity. It serves as a prime example of how algorithmic strategy can vastly improve performance.

---

# PRACTICAL - Sum of Arrays

## Aim
To calculate the total sum of all elements present in an array.

## Theory
Calculating the sum of an array is a fundamental data structure operation that involves traversing a linear collection of elements. 
The process requires an accumulator variable initialized to zero. As the algorithm visits each index of the array, it adds the value at that index to the accumulator. 
This sequential processing is the basis for many other array operations, such as finding averages or aggregating data.

## Algorithm
arraySum(arr, n)

1. Initialize sum = 0
2. Loop i from 0 to n-1:
3.     sum = sum + arr[i]
4. return sum

## Graph
![alt text](sumOfArray.png)

## Time Complexity
O(N), where N is the number of elements in the array.

## Space Complexity
O(1), as no auxiliary space is required.

## Code
```cpp
int sumOfArray(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}
```

### Use Cases
- Statistical analysis (calculating mean).
- Accumulating scores or financial totals in applications.
- Evaluating objective functions in machine learning.

## What the Code Does
This program iteratively adds up all the integers in an array.
The `sumOfArray(arr, n)` function sets an integer variable `sum` to 0. 
It then uses a `for` loop to traverse the array from index 0 up to `n-1`. 
During each iteration, the current element `arr[i]` is added to the `sum` variable. 
After the loop visits every element, the total `sum` is returned to the caller.

## Conclusion
Finding the sum of an array is a straightforward, linear operation that demonstrates basic array traversal and the use of accumulator variables, acting as a stepping stone for more complex data manipulation tasks.

# PRACTICAL -9
## Aim
To solve the Tower of Hanoi problem using recursion and display the sequence of moves required to transfer the disks.

## Theory
The Tower of Hanoi is a classical problem that demonstrates the concept of recursion.
It consists of three pegs: source, destination, and auxiliary.

The objective is to move n disks from the source peg to the destination peg by following these rules:
Only one disk can be moved at a time.
A larger disk cannot be placed on top of a smaller disk.
An auxiliary peg can be used for intermediate moves.
The recursive solution breaks the problem into smaller subproblems until the base case is reached.

## Algorithm
TOH(n, source, destination, auxiliary)

1. if n = 1 then
2.     print move source → destination
3. else
4.     TOH(n-1, source, auxiliary, destination)
5.     print move source → destination
6.     TOH(n-1, auxiliary, destination, source)

   
## Time Complexity

O(2ⁿ), where n is the number of disks
## Space Complexity

O(n) due to recursive call stack

## Code
```
void TOH(int n,int src,int dest, int ext){
    if(n==1) cout<<"move disk from "<<src<<"->"<<dest<<endl;
    else{
        TOH(n-1,src,ext,dest);
        cout<<"move disc from " <<src<<"-> "<<dest<<endl;
        TOH(n-1,ext,dest,src);
    }
}
```

### Use Cases
- Understanding recursion deeply
- Algorithm design using divide-and-conquer
- Puzzle solving and state transitions

## What the Code Does
This program prints the steps required to solve the Tower of Hanoi problem using recursion.
The TOH(n, src, dest, ext) function moves n disks from the source peg to the destination peg using an auxiliary peg.

If n == 1, the function directly moves the disk from the source to the destination.
Otherwise, it first moves n − 1 disks from the source peg to the auxiliary peg.
Then it moves the largest disk from the source peg to the destination peg.
Finally, it moves the n − 1 disks from the auxiliary peg to the destination peg.

In the main() function, the number of disks is taken as input from the user, and the recursive function is called to display all the moves.

## Conclusion
The Tower of Hanoi problem is efficiently solved using recursion by breaking it into smaller subproblems.
Although the number of moves grows exponentially, the problem clearly illustrates recursive thinking and divide-and-conquer strategy.


# Practical: Find First Duplicate

### Aim
To find the first duplicate element in an array — the element that appears more than once and has the **smallest index** of its second occurrence.

---

### Theory
Finding the first duplicate in an array is a classic searching problem with multiple approaches:

Key idea:
- A **duplicate** is an element that appears more than once in the array
- The **first duplicate** is defined by the earliest second occurrence
- Using a **hash set** allows O(1) lookup to detect if an element has been seen before

Approaches:
- **Brute Force**: Compare every pair — O(n²) time
- **Hashing**: Track seen elements using a set — O(n) time, O(n) space
- **In-place marking**: For arrays with values in range [1, n] — O(n) time, O(1) space

---

### Algorithm
1. Start
2. Input array `arr[]` of size `n`
3. Create an empty hash set `seen`
4. For each element `x` in `arr[]`:
   - If `x` is already in `seen`:
     - Return `x` as the first duplicate
   - Else:
     - Insert `x` into `seen`
5. If no duplicate found, return -1
6. Stop

---

## Graph
![alt text](first-dup.png)

### Time Complexity

| Case         | Complexity |
|--------------|------------|
| Best Case    | O(1)       |
| Average Case | O(n)       |
| Worst Case   | O(n)       |

---

### Space Complexity
- O(n) — for the hash set storing visited elements

---

### Code
```cpp
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int findFirstDuplicate(vector<int>& arr) {
    unordered_set<int> seen;

    for (int x : arr) {
        if (seen.count(x)) {
            return x;        // First duplicate found
        }
        seen.insert(x);
    }
    return -1;               // No duplicate exists
}

int main() {
    vector<int> arr = {2, 3, 1, 0, 5, 3, 4, 1};

    int result = findFirstDuplicate(arr);

    if (result != -1)
        cout << "First duplicate: " << result << endl;
    else
        cout << "No duplicate found." << endl;

    return 0;
}
```

---

### What the Code Does

- The program takes an integer array as input
- The `findFirstDuplicate()` function:
  - Iterates through the array once
  - Uses an `unordered_set` to track all seen elements
  - Returns the first element that is found already in the set
- The program outputs:
  - The first duplicate element, or
  - A message indicating no duplicates exist

---

### Sample Output
```
First duplicate: 3
```

---

### Conclusion
Finding the first duplicate using hashing is an efficient approach with O(n) time complexity.
It avoids the quadratic cost of brute-force comparison and provides a clean, readable solution.
This technique is widely applicable in data validation, stream processing, and preprocessing pipelines.