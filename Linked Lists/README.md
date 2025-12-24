# Data Structures: Linked Lists Implementation (C++)

A comprehensive C++ library implementing core Linked List variations. This project focuses on efficient memory management and providing a clean API for common list operations.



## 🚀 Supported List Types

1.  **Single Linked List (SLL):** Basic nodes with a single pointer to the next element.
2.  **Doubly Linked List (DLL):** Bi-directional nodes allowing traversal in both directions.
3.  **Circular Linked List (CSLL):** A variation where the last node points back to the head.

---

## 🛠 Features & Functions

The library provides a consistent interface across all implementations:

### **1. Insertion Operations**
* `AddFromHead`: Inserts a new element at the beginning of the list (`O(1)`).
* `AddFromTail`: Appends a new element to the end.

### **2. Deletion Operations**
* `DeleteFromHead`: Removes the first element (`O(1)`).
* `DeleteFromTail`: Removes the last element.
* `DeleteValue`: Searches for a specific value and removes its node.

### **3. Search & Utility**
* `SearchForValue`: Returns the position or existence of a target value.
* `PrintList`: A clean, formatted output showing the flow of the list (e.g., `1 -> 2 -> 3 -> NULL`).

---

## 📂 Project Structure

The core logic is divided into the following implementation files:

* `SingleLinkedList.cpp`: Logic for the one-way linked list.
* `DoublyLinkedList.cpp`: Logic for the two-way linked list.
* `CircularLinkedList.cpp`: Logic for the circular (single) linked list.

---

## 💻 How to Use

To use these implementations in your own project, ensure you include the relevant file or its header:

```cpp
// Example: Using the Single Linked List
SingleLinkedList list;

list.AddFromHead(10);
list.AddFromTail(20);
list.PrintList();
```
