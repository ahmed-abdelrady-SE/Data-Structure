# Stack Data Structure (C++)

In this folder, I implement the **Stack** data structure in two different ways: using **Arrays** and using **Linked Lists**. I also added some important applications to show how to use Stacks.

## What is a Stack?
A Stack is a linear data structure. It follows the **LIFO** (Last In, First Out) principle. 
This means the last element you add is the first one you remove.

> **Simple Example:** Think of a stack of books. You put a book on top, and you must take the top book first to reach the others.



---

## 📂 Project Files

### 1. `StackUsingLinkedList.cpp`
This file has the Stack implementation using a dynamic Linked List.
* **push**: Add new item to the top.
* **pop**: Remove the item from the top.
* **peek (top)**: See the value of the top item.
* **size**: Count how many items in the stack.

### 2. `StackUsingArray.cpp`
This is the same as the first file, but I used a fixed-size **Array** for the implementation.
* It includes all basic operations: **push**, **pop**, **peek**, and **size**.

### 3. `StackApplications.cpp`
In this file, I used the Stack to solve these problems:
* **Check_balance**: Checking if brackets `()` `{}` `[]` in a string are correct.
* **reverse_string**: Using Stack to make a string backward.
* **infix_to_postfix**: Converting normal math expressions to postfix.
* **postfix_expression_evaluation**: Calculating the final result of a postfix expression.