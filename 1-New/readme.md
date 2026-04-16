### 1. Horner's Rule (Polynomial Evaluation)
* **Problem:** Evaluate a polynomial P(x) = a_n * x^n + a_{n-1} * x^(n-1) + ... + a_1 * x + a_0 efficiently for a given value of x.
* **Algorithmic Approach:** Instead of calculating x^n for every term (which is computationally expensive), Horner's method factors out x at each step. The polynomial is rewritten as:
  P(x) = a_0 + x(a_1 + x(a_2 + ... + x(a_{n-1} + a_n * x)...))
  In a recursive approach, you evaluate the inner nested terms first and multiply by x as the recursion unwinds.
* **Time Complexity:** O(n) — It reduces the number of multiplications from O(n^2) (in a naive approach) to exactly n multiplications and n additions.
* **Space Complexity:** O(n) for the recursive call stack. *(Note: An iterative approach would drop this to O(1)).*
* **Practical Application:** Heavily used in computational mathematics, cryptography, and machine learning algorithms where rapid polynomial evaluation is required without overflowing hardware limits.

### 2. Linear Search
* **Problem:** Find the exact index of a specific target element within an array.
* **Algorithmic Approach:** Start at the first index (usually `0`) and sequentially compare each element to the target. Return the index immediately if a match is found. If the loop exhausts the array without finding the target, return `-1` (or a similar null indicator).
* **Time Complexity:** O(n) — In the worst-case scenario, the target is at the very end of the array, or doesn't exist, requiring n comparisons.
* **Space Complexity:** O(1) — No extra memory is needed regardless of array size.
* **Practical Application:** The go-to search method for small datasets or completely unsorted data where the overhead of sorting (for a binary search) isn't worth the computation.

### 3. Missing Number in a Sequence
* **Problem:** Given an array containing n distinct numbers taken from the sequence 0, 1, 2, ..., n, find the one number that is missing.
* **Algorithmic Approach:** * *Your Approach (Checking gaps):* Iterating to check for a gap > 1 works in O(n) time **only if the array is already sorted**.
  * *Optimal Math Approach:* Calculate the expected sum of the sequence using Gauss's formula: n(n+1)/2. Then, iterate through the array to find the actual sum. The missing number is simply `Expected Sum - Actual Sum`.
* **Time Complexity:** O(n) to traverse the array and calculate the actual sum.
* **Space Complexity:** O(1) — Only a few integer variables are stored.
* **Practical Application:** Data integrity checks. It's a foundational concept for detecting dropped packets in network transmissions or missing sequential IDs in a database.

### 4. Permutation Generation of Binary Strings
* **Problem:** Generate all possible binary strings (combinations of `0`s and `1`s) of a specific length n.
* **Algorithmic Approach:** Use a recursive backtracking tree. For an array of size n, start at index `0`. Assign `0` to the current index and recursively call the function for the next index. Once that branch completes, assign `1` to the current index and recurse again. Print the array when the index reaches n.
* **Time Complexity:** O(2^n) — At each of the n positions, there are 2 choices, resulting in 2^n total combinations.
* **Space Complexity:** O(n) — The depth of the recursion tree goes exactly n levels deep.
* **Practical Application:** Generating truth tables for boolean logic circuits, exhaustively testing state machines, or brute-forcing binary locks.

### 5. Permutation Generation of a String
* **Problem:** Generate all unique arrangements (permutations) of the characters in a given string.
* **Algorithmic Approach:** Backtracking. Anchor a character at the current starting position, then recursively find all permutations of the remaining substring. To iterate through choices, swap the anchored character with every other character in the string, recurse, and then "backtrack" by swapping them back to restore the original state for the next iteration.
* **Time Complexity:** O(n!) — The first position has n choices, the second has n-1, the third n-2, leading to n! total permutations.
* **Space Complexity:** O(n) — For the recursion stack.
* **Practical Application:** Solving constraint satisfaction problems like Sudoku, cryptography (analyzing cipher anagrams), or routing problems like the Traveling Salesperson Problem (evaluating all paths).

### 6. Power (Iterative)
* **Problem:** Calculate x^n (base x raised to the exponent n).
* **Algorithmic Approach:** Initialize a result variable to `1`. Run a `for` or `while` loop exactly n times, multiplying the result by x in each iteration.
* **Time Complexity:** O(n) — The number of multiplications scales directly with the size of the exponent n.
* **Space Complexity:** O(1) — Uses a constant amount of memory.
* **Practical Application:** Standard implementation for small exponents in basic scripting and backend logic.

### 7. Power (Recursive / Divide & Conquer)
* **Problem:** Calculate x^n highly efficiently.
* **Algorithmic Approach:** Use the mathematical property that x^n = (x^(n/2)) * (x^(n/2)). Recursively divide the exponent in half. 
  * If n is even: return `half_power * half_power`
  * If n is odd: return `x * half_power * half_power`
* **Time Complexity:** O(log n) — Because the exponent is halved at every recursive step, the depth of the operations shrinks logarithmically. Computing 2^100 takes only about 7 steps instead of 100.
* **Space Complexity:** O(log n) — The recursion stack depth corresponds to the number of times n can be halved.
* **Practical Application:** This algorithm (Binary Exponentiation) is the backbone of modern cryptography (like RSA), where modular exponentiation involves massive prime numbers that would take thousands of years to compute iteratively.

### 8. Sum of Arrays
* **Problem:** Calculate the total sum of all numerical elements stored in an array.
* **Algorithmic Approach:** Initialize an `accumulator` variable to `0`. Loop through each element in the array from index `0` to `n-1`, adding the current element's value to the accumulator.
* **Time Complexity:** O(n) — Every element must be visited exactly once.
* **Space Complexity:** O(1) — Only the accumulator variable is stored in memory.
* **Practical Application:** Fundamental to data processing pipelines, calculating metrics (like averages), and serving as the underlying logic for built-in array methods like `.reduce()` in JavaScript/React architectures.

### 9. Tower of Hanoi
* **Problem:** Move a stack of n varying-sized disks from a source rod to a destination rod using an auxiliary rod, without ever placing a larger disk on top of a smaller one.
* **Algorithmic Approach:** A classic example of recursive problem-solving. To move n disks:
  1. Recursively move the top n-1 disks from the Source to the Auxiliary rod.
  2. Move the largest remaining disk (nth disk) directly from the Source to the Destination rod.
  3. Recursively move the n-1 disks from the Auxiliary rod to the Destination rod.
* **Time Complexity:** O(2^n) — Moving n disks requires exactly 2^n - 1 steps. Adding just one disk doubles the required work.
* **Space Complexity:** O(n) — The maximum depth of the recursive call stack is n.
* **Practical Application:** While it's primarily a pedagogical tool to teach recursion and system states, the underlying logic is used in task scheduling, backup rotation schemes, and theoretical computer science.