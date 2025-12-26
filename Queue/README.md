# Data Structures: Queue Implementation (C++)

This repository contains a comprehensive implementation of the **Queue** data structure using two fundamental approaches: **Static Array** and **Dynamic Linked List**. 

## 📌 What is a Queue?

A **Queue** is a linear data structure that operates on the **FIFO (First-In, First-Out)** principle. This means that the first element added to the queue will be the first one to be removed, similar to a real-world line of customers.


### **The FIFO Principles:**
* **Front:** The reference point for the first element in the queue. All deletions (**Dequeue**) happen here.
* **Rear (Tail):** The reference point for the last element in the queue. All additions (**Enqueue**) happen here.
* **Strict Order:** Elements are processed in the exact order they arrive, ensuring fairness and sequential processing.

---

## 🛠 Supported Operations

Both the Array-based and Linked List-based implementations support the following core operations:

| Operation | Description | Time Complexity |
| :--- | :--- | :--- |
| `enqueue(data)` | Appends a new element to the **Rear** of the queue. | `O(1)` |
| `dequeue()` | Removes the element from the **Front** of the queue. | `O(1)` |
| `peek()` | Retrieves the **Front** element without removing it. | `O(1)` |
| `size()` | Returns the current number of elements in the queue. | `O(1)` |
| `print()` | Traverses and displays all elements from Front to Rear. | `O(n)` |

---

## 🚀 Real-World Applications

### **1. Process Scheduling**
Operating Systems use queues to manage tasks waiting for CPU time. In **Round Robin Scheduling**, processes are kept in a FIFO queue. The CPU takes the process at the front, executes it for a brief moment, and if it's not finished, it puts it back at the rear of the queue.

### **2. Buffering**
Queues act as buffers in scenarios where data is transmitted asynchronously (e.g., IO Buffers, video streaming, or printer spools). The queue holds the data until the receiving device is ready to process it, preventing data loss.

---

## 🕸 Breadth-First Search (BFS) - Deep Dive

**Breadth-First Search (BFS)** is the most significant application of the Queue data structure in graph theory. It is an algorithm used for traversing or searching tree or graph data structures.

### **The Concept**
Unlike Depth-First Search (DFS), which follows a branch as far as possible before backtracking, BFS explores the neighbor nodes first, before moving to the next level neighbors. It explores the graph **level by level**.

### **Why a Queue?**
The Queue is the engine of BFS. It ensures that all nodes at distance $k$ from the starting node are visited before any nodes at distance $k+1$. By enqueuing neighbors as we discover them, the FIFO property naturally maintains the "level-by-level" order.


### **BFS Algorithm Implementation:**

```cpp
/**
 * BFS Implementation using a Queue
 * This algorithm visits all vertices reachable from a starting node.
 */
void BFS(int startNode, vector<int> adj[], int totalNodes) {
    // 1. Initialize a boolean visited array to keep track of visited nodes
    vector<bool> visited(totalNodes, false);

    // 2. Create our custom Queue (Linked List or Array based)
    Queue_LL q; 

    // 3. Mark the starting node as visited and enqueue it
    visited[startNode] = true;
    q.enqueue(startNode);

    cout << "BFS Traversal starting from node " << startNode << ": " << endl;

    while (!q.is_empty()) {
        // 4. Dequeue a vertex from the front and print it
        int currNode = q.peek();
        cout << currNode << " ";
        q.dequeue();

        // 5. Get all adjacent vertices of the current node
        for (int neighbor : adj[currNode]) {
            // 6. If an adjacent node has not been visited, mark it visited and enqueue it
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.enqueue(neighbor);
            }
        }
    }
    cout << endl;
}
