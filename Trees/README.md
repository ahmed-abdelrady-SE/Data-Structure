# Data Structures: Trees Implementation (C++)

This repository contains a generic implementation of **Binary Trees (BT)** and **Binary Search Trees (BST)** using C++ Templates.

## 🌲 What is a Tree?

A **Tree** is a hierarchical data structure consisting of nodes connected by edges. Unlike arrays or linked lists, which are linear, trees represent data in a parent-child relationship.

### **1. Binary Tree (BT)**
A general tree where each node has at most two children (Left and Right). It is used for representing hierarchical structures like folder systems or expression trees.

### **2. Binary Search Tree (BST)**
An optimized version of a binary tree where:
* The **Left** subtree contains only nodes with values **less than** the parent node.
* The **Right** subtree contains only nodes with values **greater than** the parent node.



---

## 🔍 Tree Traversals

To visit every node in a tree, we use Depth-First Search (DFS) strategies. The order depends on when the parent node is processed:

| Traversal | Order | Best Use Case |
| :--- | :--- | :--- |
| **Inorder** | Left → Root → Right | **BST Special:** Returns elements in sorted order. |
| **Preorder** | Root → Left → Right | Used to create a copy of the tree. |
| **Postorder** | Left → Right → Root | Used for deleting trees (deletes children before parents). |



---

## 🛠 Supported Operations & Complexity

The efficiency of a tree depends on its **Height ($h$)**. In a balanced tree, $h = \log(n)$, but in the worst case (skewed tree), $h = n$.

| Operation | Binary Tree (BT) | Binary Search Tree (BST) |
| :--- | :--- | :--- |
| **Insert** | $O(1)$ (manual) | $O(h)$ |
| **Search** | $O(n)$ | $O(h)$ |
| **Min/Max** | $O(n)$ | $O(h)$ |
| **Height** | $O(n)$ | $O(n)$ |
| **Space Complexity** | $O(n)$ | $O(n)$ |

---

## 🚀 Key Implementation Details

### **1. Memory Management (Destructor)**
Since nodes are allocated dynamically on the **Heap** using `new`, a recursive destructor is implemented to traverse the tree in **Postorder** and `delete` each node. This ensures that memory is freed from the leaves up to the root, preventing memory leaks.

### **2. Efficient Search in BST**
Instead of checking every node like in a linear search, the BST search "prunes" half of the tree at each step, similar to binary search in an array:
* If `target < current`, we only search the **left** branch.
* If `target > current`, we only search the **right** branch.

### **3. Finding Extremes**
* **Min Value:** The leftmost node in the tree.
* **Max Value:** The rightmost node in the tree.

---

## 📂 Project Structure

* `BinaryTree.cpp`: General tree structure with basic traversals and property helpers.
* `BinarySearchTree.cpp`: Optimized implementation with BST-specific insertion and search logic.