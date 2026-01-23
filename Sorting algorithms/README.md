# Sorting Algorithms

to sort something , for example an array there is a lot of ways to do it
for now i will only implement the most popular one's

## selection sort

Works by repeatedly selecting the smallest element from the unsorted part of the array and placing it in its correct position.  
It always performs the same number of comparisons regardless of the input order, so its time complexity does not change.

## bubble sort

Repeatedly compares adjacent elements and swaps them if they are in the wrong order.  
Larger elements “bubble up” to the end of the array.  
It is simple but inefficient for large datasets.

## insertion sort

Builds the sorted array one element at a time by inserting each new element into its correct position.  
It is very efficient when the array is already sorted or nearly sorted.

## quick sort

Uses a divide-and-conquer approach by selecting a pivot element and partitioning the array into elements smaller and larger than the pivot.  
It is very fast on average but can be slow in the worst case if the pivot choice is poor.

## merge sort

Divides the array into smaller subarrays, sorts them recursively, then merges them back together.  
It guarantees good performance in all cases but requires extra memory.
$\space$
$\space$
<br>
<br>

# Time and Space complexity for sorting

each sorting algorithm has it's unique time complexity while sorting making each one of them suitable for a specific task and they also have their space complexity which also makes also one of them suitable for a specific task based on the number of element , memory , and time

here is the Worst and Average and best case scenario Time complexity and space complexity for each one of them

|                    | Best case scenario                                     | Average case scenario        | Worst case scenario          | space complexity                                                                              |
| ------------------ | ------------------------------------------------------ | ---------------------------- | ---------------------------- | --------------------------------------------------------------------------------------------- |
| **selection sort** | $O(n^2)$                                               | $O(n^2)$                     | $O(n^2)$                     | $O(1)$                                                                                        |
| **bubble sort**    | $O(n^2)$<br>( could be $O(n)$ with optimization/flag ) | $O(n^2)$                     | $O(n^2)$                     | $O(1)$                                                                                        |
| **insertion sort** | $O(n)$                                                 | $O(n^2)$                     | $O(n^2)$                     | $O(1)$                                                                                        |
| **quick sort**     | $O(\space n * log(n)\space)$                           | $O(\space n * log(n)\space)$ | $O(n^2)$                     | $O(\space log (n)\space)$ in best and average case scenario and $O(n)$ in worst case scenario |
| **merge sort**     | $O(\space n * log(n)\space)$                           | $O(\space n * log(n)\space)$ | $O(\space n * log(n)\space)$ | $O(n)$                                                                                        |
