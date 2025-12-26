# Data Structures: Circular Queue Implementation (C++)

This repository contains an optimized implementation of the **Queue** data structure. To maximize memory efficiency, the array-based version is implemented as a **Circular Queue**.

## 📌 What is a Circular Queue?

A **Circular Queue** is an advanced version of the standard queue where the last position is connected back to the first position to make a circle. 

### **Why use a Circular Queue? (Solving Memory Waste)**
In a standard **Linear Queue**, once an element is dequeued, that space becomes "dead space" and cannot be reused even if the queue is not full. The Circular Queue solves this by "cycling" back to the beginning of the array when the end is reached, ensuring every slot is utilized.



---

## 🔄 The Queue Cycle (Modulo Arithmetic)

The "magic" that makes the queue circular is the **Modulo Operator (%)**. Instead of simply incrementing the `Front` and `Rear` pointers, we use the following formulas to allow them to "wrap around" the array:

* **Enqueue Cycle:** `rear = (rear + 1) % MAX_SIZE`
* **Dequeue Cycle:** `front = (front + 1) % MAX_SIZE`

This ensures that if the `rear` is at the last index and we add an element, it jumps back to index `0` if it's empty.

### **Key Conditions:**
* **Queue Empty:** When `front == -1`.
* **Queue Full:** When the next position of `rear` is `front`: `(rear + 1) % MAX_SIZE == front`.

---

## 🛠 Supported Operations

| Operation | Description | Time Complexity |
| :--- | :--- | :--- |
| `enqueue(data)` | Adds an element to the next available circular slot. | `O(1)` |
| `dequeue()` | Removes the front element and cycles the front pointer. | `O(1)` |
| `peek()` | Views the element currently at the front. | `O(1)` |
| `size()` | Calculates elements between front and rear. | `O(1)` |
| `print()` | Traverses the queue from front to rear circularly. | `O(n)` |

---

## 🚀 Real-World Applications

### **1. CPU Scheduling (Round Robin)**
Operating systems use circular queues to give each process a fixed time slot. Once a process's time is up, it is moved to the back of the circular queue to wait for its next turn.

### **2. Interrupt Handling**
In hardware systems, circular queues (often called **Ring Buffers**) handle incoming data interrupts to ensure data is processed in the exact order it was received without losing any packets.

---

## 🕸 Breadth-First Search (BFS) - Deep Dive

**BFS** is the primary algorithm for traversing graphs level-by-level. It relies heavily on a queue to keep track of nodes that are discovered but not yet processed.

### **The BFS Logic:**
1.  Enqueue the starting node and mark it as visited.
2.  While the queue is not empty:
    * Dequeue a node.
    * Enqueue all its unvisited neighbors.
    * Mark them as visited.



```cpp
void BFS(int startNode, vector<int> adj[], int totalNodes) {
    vector<bool> visited(totalNodes, false);
    Queue_Circular q; // Array-based Circular Queue

    visited[startNode] = true;
    q.enqueue(startNode);

    while (!q.is_empty()) {
        int curr = q.peek();
        q.dequeue();
        cout << curr << " ";

        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.enqueue(neighbor);
            }
        }
    }
}

```

## 📂 Project Structure

* `QueueArray.cpp`: Implementation using a fixed-size array (ideal for memory-constrained environments).
* `QueueLinkedList.cpp`: Implementation using a dynamic linked list (provides flexible sizing).

