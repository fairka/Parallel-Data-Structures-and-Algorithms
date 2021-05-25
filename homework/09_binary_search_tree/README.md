# CPTR 242: Homework Assignment -- BST

## Problem Overview

Your task in this assignment is to implement __CountLeaves__, __CountSingleChildren__, and __CountGreaterThan__ for the class _TreeType_ which implements a Binary Search Tree (BST).

* The function __CountLeaves__ returns the number of leaf nodes in the BST.
* The function __CountSingleChildren__ returns the number of nodes with only a single child. A single child is a node with no direct siblings, i.e. their parent has only one direct child.
* The function __CountGreaterThan__ returns the number of nodes whose _info_ is greater than the input _value_.

## Solution Specifications

Your solution to this problem must meet the following criteria.

1. Implement the three versions of _count_ for a linked implementation in _CountNodes.cpp_.
   HINT: A recursive implementation may be useful for some of the count implementations.
   If you decide to go this route, create an additional, separate function that can be called recursively, and call that function from the respective _count_ implementation (so, __CountLeaves__ might call a separate recursive function).
2. Pass all the tests in Submitty.
3. Fill out the information in __ASSIGNMENT.md__!

## Test Driver

The Submitty tests use a test driver similar to the first homework.

In this assignment you may find it helpful to create your own test input for the driver to validate your functions.
A QueueDriver.cpp has been provided to allow a user to run test input.
Please model the method we have used for homework 1 in creating your own test input for the driver.

These are the complete menu options available:

```sh
Menu options:
  CountLeaves. Number of leaf nodes in the tree is returned
  CountSingleChildren. Number of nodes with only a single child returned.
  CountGreaterThan <value>. Number of nodes with values greater than input value returned.
  PutItem <item>. Places item in Binary Tree
  DeleteItem <item>. Deletes item from Binary Tree
  GetItem <item>. Returns a boolean variable if item is found in Binary Tree
  GetLength. Returns length of Binary Tree
  GetNextItem <order>. Returns the next item in the desired order.
  IsFull. Returns a boolean variable if Binary Tree is full
  ResetTree <order>. Resets Binary Tree depending on user order
  PrintTree. Prints Binary Tree
  MakeEmpty. Empty Graph
  Quit. Quit application.
  Menu. Display menu.
```

The code can be compile by running the `make` command.

Example Input:

```sh
PutItem D
PutItem Q
PutItem C
PutItem Z
GetLength
PrintTree
GetItem Z
MakeEmpty
PrintTree
Quit
```

To test the code, run this command:

```sh
./Tree.out
```

Resulting Standard Output:

```sh
PutItem Command is completed.
PutItem Command is completed.
PutItem Command is completed.
PutItem Command is completed.
GetLength Command is completed.
PrintTree Command is completed.
GetItem Command is completed.
MakeEmpty Command is completed.
PrintTree Command is completed.
Quit
Testing completed.
```

Resulting `solutions.txt`:

```sh
Sample Test
D is inserted
Q is inserted
C is inserted
Z is inserted
Number of nodes is 4
CDQZ
Z found in list.
Tree has been made empty.
Binary Tree is empty.
Testing completed.
```

**You will also find the solution in a `solutions.txt` file while the standard output is primarily for logging.**

## Tips

* Binary Search Tree visualization <https://www.cs.usfca.edu/~galles/visualization/BST.html>
* Reference back to Zybooks *9.11 C++: Binary search tree* as segments of code have been given to you.
* You create a text file with all the user input. Then when you run the program you may pass in this file as input.

  ```sh
  Tree.out < sample.txt
  ```

  This is a good way to recreate your test each time you run your program.

## Submission

Your submission must include a _BreadthFirstSearch.cpp_ file.
All other file _.h_ and _.cpp_ should remain unchanged.
