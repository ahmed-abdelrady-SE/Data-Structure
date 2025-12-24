# Data Structures: Linked Lists Implementation (C++)

A comprehensive C++ library implementing core Linked List variations. This project focuses on efficient memory management and providing a clean API for common list operations.

## 🚀 Supported List Types

1.  **Singly Linked List (SLL):** Basic nodes with a single pointer to the next element.
2.  **Doubly Linked List (DLL):** Bi-directional nodes allowing traversal in both directions.
3.  **Circular Linked List (CSLL):** A variation where the last node points back to the head.

---

## 🛠 Features & Functions

The library provides a consistent interface across all implementations:

### **1. Insertion Operations**
* `AddFromHead`: Inserts a new element at the beginning of the list ($O(1)$).
* `AddFromTail`: Appends a new element to the end.

### **2. Deletion Operations**
* `DeleteFromHead`: Removes the first element.
* `DeleteFromTail`: Removes the last element.
* `DeleteValue`: Searches for a specific value and removes its node.

### **3. Search & Utility**
* `SearchForValue`: Returns the position or existence of a target value.
* `PrintList`: A clean, formatted output showing the flow of the list (e.g., `1 -> 2 -> 3 -> NULL`).

---

## 📂 Project Structure

* `SinglyLinkedList.h / .cpp`: Implementation of the Singly Linked List.
* `DoublyLinkedList.h / .cpp`: Implementation of the Doubly Linked List.
* `CircularLinkedList.h / .cpp`: Implementation of the Circular Linked List.

---

## 💻 How to Use

To use these implementations in your own project, simply include the desired header file:

```cpp
#include "SinglyLinkedList.h"

// Example initialization
SinglyLinkedList list;

list.AddFromHead(10);
list.AddFromTail(20);
list.PrintList();