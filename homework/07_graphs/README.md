# CPTR 242: Homework Assignment -- Graphs

## Problem Overview

Your task in this assignment is to implement a breadth first search algorithm on a graph.
The function __BreadthFirstSearch__ will return all the nodes it can reach and what level they are at.

## Solution Specifications

Your solution to this problem must meet the following criteria.

1. Implement __BreadthFirstSearch__ for the graph implementation in _BreadthFirstSearch.cpp_.
    A file has been provided for you and function header.
2. Pass all the tests in Submitty.

## Test Driver

The Submitty tests use a test driver similar to the first homework.

In this assignment you may find it helpful to create your own test input for the driver to validate your functions.
A QueueDriver.cpp has been provided to allow a user to run test input.
Please model the method we have used for homework 1 in creating your own test input for the driver.

These are the complete menu options available:

```sh
Menu options:
  AddVertex <vertex>. Adds vertex to graph
  AddEdge <vertex> <vertex> <weight>. Adds an edge from one vertex to another
  WeightIs. Returns associated with the edge
  GetToVertices <vertex>. Returns all adjacent vertexes from given vertex
  DeleteEdge <vertex> <vertex>. Deletes given vertex in the graph 
  Print. Prints Graph
  BFS <vertex>. Performs a Breadth-First search from starting vertex
  Quit. Quit application.
  Menu. Display menu.
```

The code can be compile by running the `make` command.

Example Input:

```sh
Menu
Print
AddVertex 1
AddVertex 2
AddVertex 3
AddVertex 4
AddVertex 5
AddVertex 9
AddVertex 6
AddEdge 2 1 1
AddEdge 2 2 1
AddEdge 1 2 1
AddEdge 2 3 1
AddEdge 2 4 1
AddEdge 2 9 1
AddEdge 6 9 1
AddEdge 5 6 1
Print
Quit
```

To test the code, run this command:

```sh
./Graph.out
```

Resulting Standard Output:

```sh
AddVertex Command number 1 completed.
AddVertex Command number 2 completed.
AddVertex Command number 3 completed.
AddVertex Command number 4 completed.
AddVertex Command number 5 completed.
AddVertex Command number 6 completed.
AddVertex Command number 7 completed.
AddEdge Command number 8 completed.
AddEdge Command number 9 completed.
AddEdge Command number 10 completed.
AddEdge Command number 11 completed.
AddEdge Command number 12 completed.
AddEdge Command number 13 completed.
AddEdge Command number 14 completed.
AddEdge Command number 15 completed.
Print Command number 16 completed.
Quit
Testing completed.

```

Resulting `solutions.txt`:

```sh
Sample Test
Vertex 1 was added.
Vertex 2 was added.
Vertex 3 was added.
Vertex 4 was added.
Vertex 5 was added.
Vertex 9 was added.
Vertex 6 was added.
Edge (2, 1) with weight 1 has been created.
Edge (2, 2) with weight 1 has been created.
Edge (1, 2) with weight 1 has been created.
Edge (2, 3) with weight 1 has been created.
Edge (2, 4) with weight 1 has been created.
Edge (2, 9) with weight 1 has been created.
Edge (6, 9) with weight 1 has been created.
Edge (5, 6) with weight 1 has been created.
  1 2 3 4 5 9 6 
1 0 1 0 0 0 0 0 
2 1 1 1 1 0 1 0 
3 0 0 0 0 0 0 0 
4 0 0 0 0 0 0 0 
5 0 0 0 0 0 0 1 
9 0 0 0 0 0 0 0 
6 0 0 0 0 0 1 0 
Testing completed.
```

**You will also find the solution in a `solutions.txt` file while the standard output is primarily for logging.**

## Tips

* Reference back to Zybooks *7.7 C++: Breadth-first search* as segments of code have been given to you.
* You create a text file with all the user input. Then when you run the program you may pass in this file as input.

  ```sh
  Graph.out < sample.txt
  ```

  This is a good way to recreate your test each time you run your program.

## Submission

Your submission must include a _BreadthFirstSearch.cpp_ file.
All other file _.h_ and _.cpp_ should remain unchanged.
