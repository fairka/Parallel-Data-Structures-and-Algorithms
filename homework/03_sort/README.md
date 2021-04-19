# CPTR 242: Sorting Homework

## Problem Overview

Your task in this assignment is to implement a four sort functions with data stored in a vector.
Each sort function will implement a different search algorithm: selection sort, insertion sort, merge sort and quick sort.
To better understand how these algorithms compare, you will count the number of comparisons and data writes made by each algorithm.

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

1. Implement a __Selection Sort__ with the definition in `SelectionSort.h` and the implementation in `SelectionSort.cpp`.
     * See the `SelectionSort.h` for the public function definition.
     * You may add an necessary private functions to complete the sort.
1. Implement a __Insertion Sort__ with the definition in `InsertionSort.h` and the implementation in `InsertionSort.cpp`.
     * See the `InsertionSort.h` for the public function definition.
     * You may add an necessary private functions to complete the sort.
1. Implement a __Merge Sort__ with the definition in `MergeSort.h` and the implementation in `MergeSort.cpp`.
     * See the `MergeSort.h` for the public function definition.
     * You may add an necessary private functions to complete the sort.
1. Implement a __Quick Sort__ with the definition in `QuickSort.h` and the implementation in `QuickSort.cpp`.
     * See the `QuickSort.h` for the public function definition.
     * You may add an necessary private functions to complete the sort.
1. Pass all the tests in Submitty.

## Test Driver

The Submitty tests use a test driver similar to the first homework.

In this assignment you may find it helpful to create your own test input for the driver to validate your functions.
A SearchDriver.cpp has been provided to allow a user to run test input.
Please model the method we have used for homework 1 in creating your own test input for the driver.

These are the complete menu options available:

```sh
Menu options:
  InsertionSort. Sorts list using a InsertionSort Algorithm.
  MergeSort. Sorts list using a MergeSort Algorithm.
  QuickSort. Sorts list using a QuickSort Algorithm.
  SelectionSort. Sorts list using a SelectionSort Algorithm.
  LoadListFromFile <data>. Loads a vector list from data file
  GetLength. Returns size of list
  MakeEmpty. Clears List
  PrintList. Prints out list
  Quit. Quit application.
  Menu. Display menu.
```

The code can be compile by running the `make` command.

Example Input:

```sh
LoadListFromFile list_micro.txt
SelectionSort
PrintList
MakeEmpty
LoadListFromFile list_micro.txt
InsertionSort
PrintList
MakeEmpty
LoadListFromFile list_micro.txt
MergeSort
PrintList
MakeEmpty
LoadListFromFile list_micro.txt
QuickSort
PrintList
Quit
```

To test the code, run this command:

```sh
./Sort.out
```

Resulting Standard Output:

```sh
LoadListFromFile Command number 1 completed.
SelectionSort Command number 2 completed.
PrintList Command number 3 completed.
MakeEmpty Command number 4 completed.
LoadListFromFile Command number 5 completed.
InsertionSort Command number 6 completed.
PrintList Command number 7 completed.
MakeEmpty Command number 8 completed.
LoadListFromFile Command number 9 completed.
MergeSort Command number 10 completed.
PrintList Command number 11 completed.
MakeEmpty Command number 12 completed.
LoadListFromFile Command number 13 completed.
QuickSort Command number 14 completed.
PrintList Command number 15 completed.
Quit
Testing completed.
```

Resulting `solutions.txt`:

```sh
SelectionSort Test
list_micro.txt has loaded 6 items.
Selection Sort performed 15 comparisons, 18 writes.
[2, 6, 14, 19, 23, 51]
List has been cleared 
list_micro.txt has loaded 6 items.
Insertion Sort performed 10 comparisons, 21 writes.
[2, 6, 14, 19, 23, 51]
List has been cleared 
list_micro.txt has loaded 6 items.
Merge Sort performed 11 comparisons, 32 writes.
[2, 6, 14, 19, 23, 51]
List has been cleared 
list_micro.txt has loaded 6 items.
Quick Sort performed 23 comparisons, 9 writes.
[2, 6, 14, 19, 23, 51]
Testing completed.
```

**You will also find the solution in a `solutions.txt` file while the standard output is primarily for logging.**

## Tips

* Reference back to Zybooks *3.3 C++: Selection Sort* as segments of code have been given to you.
* Reference back to Zybooks *3.5 C++: Insertion Sort* as segments of code have been given to you.
* Reference back to Zybooks *3.7 C++: Quick Sort* as segments of code have been given to you.
* Reference back to Zybooks *3.9 C++: Merge Sort* as segments of code have been given to you.
* You create a text file with all the user input. Then when you run the program you may pass in this file as input.

  ```sh
  Search.out < sample.txt
  ```

  This is a good way to recreate your test each time you run your program.

## Submission

Your submission must include a `SelectionSort.h`, `SelectionSort.cpp`, `InsertionSort.h`, `InsertionSort.cpp`, `MergeSort.h`, `QuickSort.h`, and `QuickSort.cpp` files.
All other file `.h` and `.cpp` should remain unchanged.
