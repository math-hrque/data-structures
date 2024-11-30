# **Data Structures**  
_A Modular Collection of Algorithms and Data Structures for Performance Testing and Comparison_

## Introduction

This project provides implementations of various fundamental algorithms and data structures, focusing on the efficiency and flexibility of their operations. Instead of having a fixed main source file, the project allows the user to choose and compile any individual `.c` file, making it easy to test specific algorithms or data structures like sorting, searching, trees, graphs, and more. The goal is to offer a modular approach to studying and testing different algorithms in practice.

## Requirements

- A C compiler (e.g., GCC)
- `make` tool installed on your system (for compiling using the Makefile)

## How to Run

1. Clone this repository:
    ```bash
    git clone https://github.com/math-hrque/data-structures.git
    ```
2. Open a terminal and navigate to the directory where the project files are located.

### To compile a specific `.c` file:

Instead of compiling the entire project, you can compile and run any specific `.c` file directly. You can modify the `Makefile` to compile specific source files.

- **Option 1: Using `make`**:  
  Open the terminal and run the following command, specifying the target you want to compile. For example, if you want to compile `binary_search.c`, use:
  ```bash
  make binary_search
  ```

- **Option 2: Compile manually using gcc**:
Alternatively, you can manually compile a specific .c file using the following command:
  ```bash
  gcc -o program <filename.c>
  ```

  Replace <filename.c> with the name of the .c file you want to compile. For example:
    ```bash
    gcc -o program binary_search.c
    ```

### After compilation:
- Run the compiled program:
  ```bash
  ./program
  ```
- You can then follow the prompts within the program to test the functionality of the algorithm or data structure.

---

## Sorting Algorithms and Performance

This project includes implementations of various sorting algorithms to rank words or strings based on frequency. The choice of algorithm can significantly impact execution time depending on the size and distribution of the dataset.

The sorting algorithms are implemented in the following files:

- **algorithms/basic_sorting_algorithms.c**: Contains simple sorting algorithms such as **Bubble Sort**, **Selection Sort**, **Insertion Sort**, **Shell Sort**, and **Counting Sort**.
- **algorithms/advanced_sorting_algorithms.c**: Contains more advanced sorting algorithms such as **Merge Sort**, **Quick Sort**, **Heap Sort**, and **Radix Sort**.

Below are the sorting algorithms implemented, their time complexities, and explanations of the **best case** and **worst case** scenarios for each.

| **Algorithm**         | **Best Case**      | **Average Case**     | **Worst Case**       |
|-----------------------|--------------------|----------------------|----------------------|
| **Bubble Sort**        | O(n)               | O(n²)                | O(n²)                |
| **Selection Sort**     | O(n²)              | O(n²)                | O(n²)                |
| **Insertion Sort**     | O(n)               | O(n²)                | O(n²)                |
| **Shell Sort**         | O(n log n)         | O(n log n)           | O(n²)                |
| **Counting Sort**      | O(n + k)           | O(n + k)             | O(n + k)             |
| **Merge Sort**         | O(n log n)         | O(n log n)           | O(n log n)           |
| **Quick Sort**         | O(n log n)         | O(n log n)           | O(n²)                |
| **Heap Sort**          | O(n log n)         | O(n log n)           | O(n log n)           |
| **Radix Sort**         | O(nk)              | O(nk)                | O(nk)                |

---

### **Explanation of Best and Worst Case Scenarios for Each Algorithm**

#### **Bubble Sort**
- **Best Case (O(n))**: Occurs when the array is already sorted or nearly sorted. Since Bubble Sort is adaptive, it can terminate after one pass without any swaps if the array is sorted.
- **Worst Case (O(n²))**: Happens when the array is completely unsorted. Each element has to be compared and swapped, resulting in the maximum number of comparisons and swaps.

##### **Example**: 
- Best case: `[1, 2, 3, 4, 5]` (the algorithm makes one pass and finishes).
- Worst case: `[5, 4, 3, 2, 1]` (the algorithm performs the maximum number of comparisons and swaps).

#### **Selection Sort**
- **Best Case (O(n²))**: Selection Sort always performs **O(n²)** comparisons, regardless of whether the array is sorted or not.
- **Worst Case (O(n²))**: The time complexity remains the same, as the algorithm always goes through the entire array to find the smallest (or largest) element in each iteration.

##### **Example**:
- Best and worst case: `[5, 4, 3, 2, 1]` or `[1, 2, 3, 4, 5]` (the algorithm always performs O(n²) comparisons).

#### **Insertion Sort**
- **Best Case (O(n))**: Occurs when the array is already sorted, as the algorithm only makes comparisons and no swaps.
- **Worst Case (O(n²))**: Happens when the array is in reverse order, as each new element must be compared with all previous ones, leading to the maximum number of comparisons and shifts.

##### **Example**:
- Best case: `[1, 2, 3, 4, 5]` (no shifts, only comparisons).
- Worst case: `[5, 4, 3, 2, 1]` (each new element must be shifted to the start of the array).

#### **Shell Sort**
- **Best Case (O(n log n))**: Depending on the choice of gap sequence, Shell Sort can perform much better than Insertion Sort, especially on partially sorted arrays.
- **Worst Case (O(n²))**: If an inefficient gap sequence is chosen, the performance can degrade to **O(n²)**, similar to Insertion Sort.

##### **Example**:
- Best case: Partially sorted arrays with an optimal gap sequence.
- Worst case: An inefficient gap sequence results in **O(n²)** behavior.

#### **Counting Sort**
- **Best Case (O(n + k))**: As a non-comparative algorithm, its performance directly depends on **k**, the range of values.
- **Worst Case (O(n + k))**: Even in the worst case, the complexity is still **O(n + k)**, but if **k** is large, the algorithm may become inefficient.

##### **Example**:
- Best case: `[1, 2, 3, 4, 5]`, with values in a small range.
- Worst case: A large range of values where **k** is very large.

#### **Merge Sort**
- **Best Case (O(n log n))**: Always divides the array in half and merges them, even when the data is already sorted. Complexity remains **O(n log n)**.
- **Worst Case (O(n log n))**: The division and merging steps are always performed the same way, resulting in **O(n log n)** complexity regardless of the input order.

##### **Example**:
- Best and worst case: `[1, 2, 3, 4, 5]` or `[5, 4, 3, 2, 1]` (the behavior of the algorithm is the same in both cases).

#### **Quick Sort**
- **Best Case (O(n log n))**: Occurs when the pivot is chosen well (usually the pivot divides the array into two roughly equal halves).
- **Worst Case (O(n²))**: Happens when the pivot is always the smallest or largest element, leading to an unbalanced partition and a time complexity of **O(n²)**.

##### **Example**:
- Best case: A pivot divides the array well (e.g., `[3, 2, 1, 4, 5]`).
- Worst case: A pivot is the smallest or largest element repeatedly (e.g., `[1, 2, 3, 4, 5]`).

#### **Heap Sort**
- **Best Case (O(n log n))**: Always builds the heap and performs the extraction. The performance does not depend on the initial order of the data.
- **Worst Case (O(n log n))**: Even in the worst case, Heap Sort maintains **O(n log n)** complexity since the heap construction and element extraction steps are consistent.

##### **Example**:
- Best and worst case: The complexity is always **O(n log n)**, regardless of input.

#### **Radix Sort**
- **Best Case (O(nk))**: Depends on the number of digits (k) in the values, and it is very efficient when **k** is small.
- **Worst Case (O(nk))**: The complexity remains the same, but if **k** is large, the algorithm may become inefficient. It is ideal for data with small digit lengths or fixed-length strings.

##### **Example**:
- Best case: Numbers or strings with fewer digits (e.g., `[123, 234, 345]`).
- Worst case: Large numbers or strings with many digits (e.g., large integers).

---

### **Performance Impact**

The choice of sorting algorithm can significantly influence the execution time of the program, especially when processing large datasets or datasets with highly variable frequencies.

- **Bubble Sort**, **Selection Sort**, and **Insertion Sort** are simple but inefficient for large datasets, with **O(n²)** time complexity in the worst case. They are best suited for small or partially sorted datasets.
- **Shell Sort** can be more efficient, especially for small to medium-sized lists, but its worst-case time complexity is **O(n²)**. Its performance heavily depends on the choice of gap sequence.
- **Counting Sort** and **Radix Sort** are non-comparative algorithms that can be very efficient when the dataset has a limited range of values or small digit lengths. Both have **O(n + k)** or **O(nk)** complexity but can become inefficient if the range of values is large.
- **Merge Sort**, **Quick Sort**, and **Heap Sort** are more reliable for large datasets with **O(n log n)** time complexities. However, **Quick Sort** can degrade to **O(n²)** in the worst case if the pivot selection is poor.

In general, for large datasets, **Merge Sort**, **Quick Sort**, or **Heap Sort** are the most predictable and efficient choices. **Radix Sort** is ideal for numeric data or strings with fixed lengths. **Counting Sort** works well when the range of data is well-defined but can be problematic if **k** (the range of values) is very large.

---

## Search Algorithms and Tree Data Structures

The following section compares various search algorithms and tree data structures, outlining their respective time complexities for **search**, **insert**, **delete**, **best case**, **average case**, **worst case**, and whether the operations are ordered. It also covers the **Key Interface** (i.e., the key methods used in the data structure).

| **Structure/Algorithm**         | **Search**    | **Insert**    | **Delete**    | **Best Case**  | **Average Case** | **Worst Case**  | **Ordered Ops** | **Key Interface**          |
|---------------------------------|---------------|---------------|---------------|----------------|------------------|-----------------|-----------------|----------------------------|
| **Sequential Search**           | O(n)          | -             | -             | O(1)           | O(n)             | O(n)            | No              | `equals()`                 |
| **Binary Search**               | O(log n)      | -             | -             | O(1)           | O(log n)         | O(log n)        | Yes             | `compareTo()`              |
| **Hash Table (Chaining)**       | O(1) (avg)    | O(1)          | O(1)          | O(1)           | O(1)             | O(n)            | No              | `equals()`, `hashCode()`   |
| **Binary Search Tree (BST)**    | O(log n)      | O(log n)      | O(log n)      | O(1)           | O(log n)         | O(n)            | Yes             | `compareTo()`              |
| **Red-Black Tree**              | O(log n)      | O(log n)      | O(log n)      | O(1)           | O(log n)         | O(log n)        | Yes             | `compareTo()`              |

---

### **1. Sequential Search**

Sequential Search is a simple search technique that iterates through a sequence of data, checking each item until it finds the target or traverses the entire sequence. This technique does not require the data to be ordered.

#### Complexity:
- **Best Case (O(1))**: When the element is at the first position.
- **Worst Case (O(n))**: When the element is not present or is at the last position in the sequence.

In the file `algorithms/sequential_search.c`, the sequential search is performed on a string of characters input by the user.

---

### **2. Binary Search**

Binary Search is an efficient search technique that works only on sorted lists. The idea is to repeatedly divide the search interval in half, comparing the middle value with the target. If the middle value is greater than the target, the search continues in the lower half; otherwise, it continues in the upper half.

#### Complexity:
- **Best Case (O(1))**: When the element is found in the middle.
- **Worst Case (O(log n))**: When the search interval must be reduced down to the last element.

The file `algorithms/binary_search.c` implements binary search on a sorted string, which is first sorted using Insertion Sort.

#### Key Interface:
- **`compareTo()`**: This method is used to compare elements, and it is essential for maintaining the sorted order during binary search.

---

### **3. Hashing**

#### Hash Function

A hash function is used to map data of any size to a fixed value (an integer), which can be used as an index in a hash table. In the file `algorithms/hash_code.c`, we implement a simple hash function to calculate the hash value of a string.

**Formula**: The hash function sums the ASCII values of the characters in the string, multiplies them by a base (31), and reduces them modulo a prime number.

#### Hash Table

Hash tables are data structures that map keys to values. They provide an efficient way to store and retrieve data. In the file `algorithms/hash_table.c`, a hash table is implemented with chaining to handle collisions. Each "bucket" contains a linked list of nodes.

##### Main Operations:
- **Insert**: Inserts a key-value pair into the table.
- **Search**: Finds a value given a key.
- **Delete**: Removes a key-value pair from the table.
- **Print**: Displays the contents of the table.

**Example Operation**:  
The `insert` function is responsible for adding new elements, while `search` retrieves the value associated with a key. In case of collisions, insertion occurs at the start of the linked list for the corresponding bucket.

#### Key Interface:
- **`equals()`**: This method is used to compare keys during searching and insertion.
- **`hashCode()`**: The hash code of the key is computed using this method to determine the index in the hash table.

---

### **4. Binary Search Tree (BST)**

A Binary Search Tree (BST) is a tree data structure where each node has at most two children: the left child has a smaller value than the node, and the right child has a larger value. The operations of searching, insertion, and removal in a BST occur in **O(log n)** time in the best case, but can degrade to **O(n)** in the worst case if the tree becomes unbalanced.

In the file `trees/binary_search_tree.c`, the functions `insert`, `search`, `removeNode`, and `inOrder` are used to manipulate the binary search tree. The `printTree` function displays the tree in a readable format.

#### Operations:
- **Insertion**: Values are inserted recursively to maintain the binary search tree property.
- **Search**: Performed recursively by comparing the value with the current node.
- **Removal**: Removing a node is more complex and may involve replacing it with a successor or predecessor.

#### Key Interface:
- **`compareTo()`**: This method is used to compare node values in the tree during search, insertion, and deletion.

---

### **5. Red-Black Tree**

A Red-Black Tree is a type of balanced binary search tree where each node is colored (either red or black) to ensure reasonable balancing. It is used to guarantee that search, insertion, and removal operations are performed in **O(log n)** time, even in the worst case.

In the file `trees/red_black_tree.c`, insertion follows the balancing rules of Red-Black trees, with left and right rotations, as well as mechanisms to ensure that the root node is always black.

#### Properties:
- The root is black.
- The children of a red node are always black.
- Any path from the root to a leaf contains the same number of black nodes.

The `insert` function takes care of both insertion and automatic balancing of the tree using rotations and color swaps.

#### Key Interface:
- **`compareTo()`**: Used to compare node values during insertion and search, ensuring the Red-Black tree properties are maintained.

---

### **Performance Impact**

Each data structure has its advantages and disadvantages, depending on the type of operation you need to perform most frequently:

#### Search Algorithms:
- **Sequential Search** is simple but not efficient for large datasets.
- **Binary Search** is very efficient on sorted lists, with a worst-case time complexity of **O(log n)**.

#### Hashing:
- **Hash Tables** offer **O(1)** search time in the best case but can degrade to **O(n)** in case of many collisions.

#### Trees:
- **Binary Search Trees (BSTs)** can become unbalanced, degrading their performance to **O(n)**. However, they remain efficient for insertion and removal operations when balanced.
- **Red-Black Trees** guarantee **O(log n)** time for all operations due to their automatic balancing.

---

## Graph Data Structures

Graphs are versatile data structures used to represent relationships between entities. They consist of vertices (or nodes) connected by edges. This project includes implementations of various types of graphs, offering efficient ways to represent and process complex networks.

### Types of Graphs Implemented

1. **Adjacency Matrix (Undirected, Weighted Graph)**  
   The adjacency matrix is a 2D array where the element at row `i` and column `j` represents the presence and/or weight of an edge between vertex `i` and vertex `j`. The matrix is symmetric for undirected graphs and may contain edge weights if it's a weighted graph.

2. **Directed Graph (Digraph)**  
   A directed graph (digraph) contains edges that have a direction, from one vertex to another. Unlike undirected graphs, the relationship between two vertices is not mutual.

3. **Undirected Graph**  
   In an undirected graph, edges have no direction. The relationship between two vertices is bidirectional, meaning if there is an edge between vertex `i` and vertex `j`, there is also an edge between `j` and `i`.

4. **Weighted Graph**  
   In weighted graphs, edges carry a weight or cost. These weights can represent anything from distances to costs or any other numeric value that quantifies the relationship between vertices.

### Graph Operations

- **Create a Graph**: Functions to initialize a graph with a specified number of vertices and edges.
- **Add Edge**: Allows the addition of an edge between two vertices, optionally with a specified weight.
- **Print Graph**: Functions for visualizing the graph structure, whether represented by an adjacency matrix or list.
- **Free Memory**: Functions to properly clean up and release the memory allocated for the graph.

### Performance Impact

Graphs are particularly useful for representing networks but can become complex when it comes to efficiency. The choice between an adjacency matrix, adjacency list, or other graph representations affects both memory usage and time complexity for graph traversal or manipulation algorithms.

- **Adjacency Matrix**: Ideal for dense graphs, where the number of edges is close to the maximum possible. It provides fast lookups but can consume a lot of space for sparse graphs.
- **Adjacency List**: More efficient for sparse graphs, as it only stores the edges that exist. However, accessing edges can be slower than with an adjacency matrix.
- **Directed vs Undirected Graphs**: Directed graphs are necessary when the relationships between vertices are asymmetric (e.g., one-way streets), while undirected graphs are used for symmetric relationships (e.g., social connections).
- **Weighted Graphs**: Essential for problems involving pathfinding, network optimization, and other scenarios where edges have varying costs.

---

## Heap Data Structures

A **Heap** is a binary tree-based data structure that satisfies the **heap property**. It is often used in algorithms that require efficient retrieval of the maximum or minimum element, such as **Priority Queues**.

### Types of Heaps Implemented

1. **Fibonacci Heap**  
   A Fibonacci Heap is a more advanced heap structure that allows for more efficient merge operations and amortized time complexities for many heap operations compared to binary heaps. This is ideal for algorithms like **Dijkstra's shortest path algorithm**, where merging heaps frequently occurs.

2. **Max-Heap**  
   A Max-Heap is a binary tree where the value of each node is greater than or equal to the values of its children. The root node contains the maximum element, making it useful for problems that involve repeatedly extracting the largest value, such as in **Heap Sort** or **Priority Queues**.

3. **Min-Heap**  
   A Min-Heap is the reverse of a Max-Heap, where the value of each node is less than or equal to its children's values. The root node contains the minimum element, making it ideal for algorithms that need to repeatedly extract the smallest element, such as **Dijkstra's algorithm** or **Prim's algorithm** for finding the minimum spanning tree.

### Heap Operations

- **Create Heap**: Initializes a heap with a given capacity.
- **Insert**: Inserts an element into the heap while maintaining the heap property.
- **Extract Root**: Removes and returns the root element (max or min, depending on the heap type).
- **Heapify**: Rearranges the heap to ensure that it maintains the heap property after an operation like insertion or deletion.
- **Free Memory**: Cleans up and frees the memory used by the heap.

### Performance Impact

Heaps are essential when you need efficient access to the largest or smallest elements in a collection, such as in **Priority Queues**. Here is a summary of the time complexities:

- **Fibonacci Heap**: Allows faster decrease-key and merge operations with amortized time complexity of **O(1)** for **insert** and **O(log n)** for **extract-min/max**.
- **Max-Heap/Min-Heap**: Operations like **insert** and **extract** both run in **O(log n)** time, making them ideal for applications like **Heap Sort**, where the entire data structure is repeatedly accessed and modified.

---

## Recursion Problems

This section covers solutions to classic problems using the **recursion** technique. Recursion is a programming paradigm where a function calls itself to solve smaller subproblems. While intuitive, recursion can have significant performance impacts, especially in problems involving large datasets.

### Implemented Problems

The following problems are solved recursively, and their solutions are located in the respective files:

- **recursion_problems/fibonacci_sequence.c**: Implements the Fibonacci sequence in two ways:
  - **Recursive**: The function `fibonacciRecursive(int n)` computes the n-th Fibonacci number by recursively calling itself until the base case is reached.
  - **Iterative**: The function `fibonacciIterative(int n)` solves the problem efficiently using a loop.

- **recursion_problems/n_queens_backtracking.c**: Solves the N-Queens problem using **backtracking**. The recursive function `solveNQueensUtil(int board[N][N], int col)` tries to place a queen in each column, backtracking when no solution is found.

- **recursion_problems/tower_of_hanoi.c**: Solves the classic Towers of Hanoi problem, where disks must be moved between three pegs. The recursive function `autoTowerOfHanoi(int n, Stack* source, Stack* destination, Stack* auxiliary)` is implemented to move the disks accordingly.

---

### Time Complexity Tables

Below are the time complexities for the recursive solutions to each problem, taking into account the best, average, and worst-case scenarios.

| **Problem**             | **Best Case**    | **Average Case**   | **Worst Case**     |
|-------------------------|------------------|--------------------|--------------------|
| **Recursive Fibonacci**  | O(1)             | O(n)               | O(2^n)             |
| **Backtracking (N-Queens)** | O(N)           | O(N!)              | O(N!)              |
| **Towers of Hanoi**      | O(1)             | O(2^n)             | O(2^n)             |

---

### Performance Analysis

While recursion provides elegant solutions to many problems, it can significantly affect performance when dealing with large datasets:

- **Recursive Fibonacci**: The recursive version of this problem has a time complexity of **O(2^n)**, making it inefficient for large values of `n`. On the other hand, the iterative version runs in **O(n)** time, making it more efficient in terms of execution time.

- **N-Queens (Backtracking)**: The backtracking approach has a time complexity of **O(N!)**, meaning the execution time grows exponentially as `N` increases. While backtracking is an effective technique for exploring solutions, it can become impractical for larger values of `N`.

- **Towers of Hanoi**: The recursive solution has a time complexity of **O(2^n)**, as the number of moves doubles with each additional disk. While the solution is straightforward, it becomes inefficient for larger values of `n`.

---

### Recursion's Impact on Performance

Recursion is a useful technique, but its complexity can be a limiting factor, especially in problems with large inputs. Although recursive solutions are often more elegant and easier to understand, they can be inefficient in terms of time and space. In many cases, **iterative approaches** or techniques like **memoization** can be more efficient.

- **Recursive Fibonacci**: The recursive version is impractical for large `n` due to the explosion of function calls. Solutions like **memoization** or the **iterative version** are better suited for larger values of `n`.

- **Backtracking (N-Queens)**: The use of recursion in backtracking is great for exploring all possible solutions, but the time cost is high. In larger problems, **optimizing with pruning** or other search space reduction techniques can be beneficial.

- **Towers of Hanoi**: Recursion works well for the Towers of Hanoi problem when `n` is small, but it quickly becomes impractical as the number of disks increases due to exponential time complexity.
