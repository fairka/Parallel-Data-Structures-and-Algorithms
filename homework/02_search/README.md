# CPTR 242: Searching Homework

## Problem Overview

Your task in this assignment is to implement a two sort functions with data stored in a vector.
Each search function will implement a different search algorithm: linear search and binary search.
To better understand how these algorithms compare, you will count the number of comparisons made by each algorithm.

## Object Comparison

The data will be stored in a vector of objects called `ItemType`.
In a system with real data, information may not be easily compared.
Consider sorting a list of students, do you sort by name, age, height, etc.
The object may include a function called `CompareTo` to define how to compare to objects.
For this assignment, the two objects will be compared with each other using this function.

The result will be one of these values from the `enum RelationType`:

```c++
enum RelationType { LESS, GREATER, EQUAL };
```

Consider this example for doing the comparison between `item1` and `item2`.
Notice how a switch is used to jump to the comparison result.

```c++
switch (item1.ComparedTo(item2)) {
case LESS:
    // Do something for less than
    break;
case GREATER:
    // Do something for greater than
    break;
case EQUAL:
    // Do something for equal
    break;
}
```

## Solution Specifications

Your solution to this problem must meet the following criteria.

1. Implement a __Linear Search__ over sorted data with the implementation in _LinearSearch.cpp_.
     * See the _LinearSearch.h for the function definition.
     * Include an early exit condition if you know the value will not be in the results.
2. Implement a __Binary Search__ over sorted data with the implementation in _BinarySearch.cpp_.
     * See the _BinarySearch.h for the function definition.
3. Pass all the tests in Submitty.

## Test Driver

The Submitty tests use a test driver similar to the first homework.

In this assignment you may find it helpful to create your own test input for the driver to validate your functions.
A SearchDriver.cpp has been provided to allow a user to run test input.
Please model the method we have used for homework 1 in creating your own test input for the driver.

These are the complete menu options available:

```sh
Menu options:
  LinearSearch <key>. Searches key within the list using a Linear Algorithm.
  BinarySearch <key>. Searches key within the list using a Binary Algorithm
  LoadListFromFile <data>. Searches key within the list using a Binary Algorithm
  GetLength. Returns size of list
  MakeEmpty. Clears List
  PrintList. Prints out list
  Quit. Quit application.
  Menu. Display menu.
```

The code can be compile by running the `make` command.

Example Input:

```sh
InputTest
LoadListFromFile list_micro.txt
PrintList
LinearSearch 2
BinarySearch 2
LinearSearch 17
BinarySearch 17
Quit
```

To test the code, run this command:

```sh
./Search.out
```

Resulting Standard Output:

```sh
Enter name of test run; press return.
LoadListFromFile Command number 1 completed.
PrintList Command number 2 completed.
LinearSearch Command number 3 completed.
BinarySearch Command number 4 completed.
LinearSearch Command number 5 completed.
BinarySearch Command number 6 completed.
Quit
Testing completed.
```

Resulting `solutions.txt`:

```sh
InputTest
list_micro.txt has loaded 5 items.
[11, 13, 17, 19, 23]
2 is not in list.
Linear search performed 1 comparisons.
2 is not in list.
Binary search performed 2 comparisons.
17 was found at 2 in list.
Linear search performed 3 comparisons.
17 was found at 2 in list.
Binary search performed 1 comparisons.
```

**You will also find the solution in a `solutions.txt` file while the standard output is primarily for logging.**

## Tips

* Reference back to Zybooks *2.3 C++: Linear and binary search* as segments of code have been given to you.
* You create a text file with all the user input. Then when you run the program you may pass in this file as input.

  ```sh
  Search.out < sample.txt
  ```

  This is a good way to recreate your test each time you run your program.

## Submission

Your submission must include a _LinearSearch.cpp_ and _BinarySearch.cpp_ files.
All other file _.h_ and _.cpp_ should remain unchanged.
