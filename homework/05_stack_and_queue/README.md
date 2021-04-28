# CPTR 242: Homework Assignment - Stack and Queues

## Problem Overview

Your task in this assignment is to implement queue using two stack data structures.
In addition to `Enqueue` and `Dequque`, you will need to create a `ReplaceItem` function.
The function __ReplaceItem__ takes an new item, finds the old item(s) in the _queue_, and replaces the old item with the new item in the _queue_.
The function should be implemented using only the standard functions on a stack (i.e. push and pop).
ALL instances of the old item in the queue should be replaced with the new item.

## Solution Specifications

Your solution to this problem must meet the following criteria.

1. Implement __Enqueue__, __Dequeue__, and __ReplaceItem__ for the queue implementation in _QueueType.cpp_.
    A cpp file has been provided for you with a function header.
2. Pass all the tests in Submitty.

## Test Driver

The Submitty tests use a test driver similar to the first homework.

In this assignment you may find it helpful to create your own test input for the driver to validate your functions.
A QueueDriver.cpp has been provided to allow a user to run test input.
Please model the method we have used for homework 1 in creating your own test input for the driver.

These are the complete menu options available:

```sh
Menu options:
  Enqueue <item>. Adds Item at the rear of Queue
  Dequeue. Removes first item in Queue
  IsEmpty. Returns true if Queue List is empty
  IsFull. Returns true if Queue List reach max limit of items it can hold
  ReplaceItem <oldItem> <newItem>. Updates oldItem in Queue with the newItem
  Print. Prints Queue list
  MakeEmpty. Clears Queue list
  Quit. Quit application.
  Menu. Display menu.
```

The code can be compile by running the `make` command.

Example Input:

```sh
Enqueue Z
Print
ReplaceItem Q T
Print
ReplaceItem Z M
Print
Quit
```

To test the code, run this command:

```sh
./Sort.out
```

Resulting Standard Output:

```sh
Enqueue Command number 1 completed.
Print Command number 2 completed.
ReplaceItem Command number 3 completed.
Print Command number 4 completed.
ReplaceItem Command number 5 completed.
Print Command number 6 completed.
Quit
Testing completed.
```

Resulting `solutions.txt`:

```sh
Sample Test
Z is enqueued.
PrintQueue: Z 
Q was replaced with T
PrintQueue: Z 
Z was replaced with M
PrintQueue: M 
Testing completed.

```

**You will also find the solution in a `solutions.txt` file while the standard output is primarily for logging.**

## Tips

* Reference back to Zybooks *4.20 C++: Stacks and Queues* as segments of code have been given to you.
* You create a text file with all the user input. Then when you run the program you may pass in this file as input.

  ```sh
  Queue.out < sample.txt
  ```

  This is a good way to recreate your test each time you run your program.

## Submission

Your submission must include a `QueueType.cpp` file.
All other file `.h` and `.cpp` should remain unchanged.
