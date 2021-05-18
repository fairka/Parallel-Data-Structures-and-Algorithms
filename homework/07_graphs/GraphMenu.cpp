/*************************************************************************
 *
 * Assignment 5: BFS Algorithm, vertices driver file
 *
 * File Name: GraphDriver.cpp
 * Course:    CPTR 242
 * Date:       May 9, 2021
 */

#include "GraphMenu.h"
#include "GraphType.h"
#include <iostream>
#include <map>
#include <string>

void GraphMenu(std::istream &inStream, std::ostream &outStream,
               std::string outputLabel) {
  std::string command; // operation to be executed

  GraphType<int> graph;
  map<int, int> distance;
  int numCommands;
  int vertex1;
  int vertex2;
  int weight;

  outStream << outputLabel << std::endl;
  inStream >> command;

  numCommands = 0;
  while (command != "Quit") {
    std::cout << command;
    if (command == "Menu") {
      outStream << "Menu options:" << std::endl;
      outStream << "  AddVertex <vertex>. Adds vertex to graph" << std::endl;
      outStream << "  AddEdge <vertex> <vertex> <weight>. Adds an edge from one vertex to another"
                << std::endl;
      outStream << "  WeightIs. Returns associated with the edge" << std::endl;
      outStream << "  GetToVertices <vertex>. Returns all adjacent vertexes "
                   "from given vertex"
                << std::endl;
      outStream << "  DeleteEdge <vertex> <vertex>. Deletes given vertex in the graph "
                << std::endl;
      outStream << "  Print. Prints Graph" << std::endl;
      outStream << "  BFS <vertex>. Performs a Breadth-First search from "
                   "starting vertex"
                << std::endl;
      outStream << "  Quit. Quit application." << std::endl;
      outStream << "  Menu. Display menu." << std::endl;
    } else {
      try {
        if (command == "AddVertex") {
          inStream >> vertex1;
          graph.AddVertex(vertex1);
          outStream << "Vertex " << vertex1 << " was added." << std::endl;
        } else if (command == "AddEdge") {
          inStream >> vertex1;
          inStream >> vertex2;
          inStream >> weight;
          outStream << "Edge (" << vertex1 << ", " << vertex2
                    << ") with weight " << weight << " has been created."
                    << std::endl;
          graph.AddEdge(vertex1, vertex2, weight);
        } else if (command == "WeightIs") {
          inStream >> vertex1;
          inStream >> vertex2;
          outStream << "Edge (" << vertex1 << ", " << vertex2 << ") has weight "
                    << weight << "." << std::endl;
        } else if (command == "GetToVertices") {
          outStream << "GetToVertices is not yet implemented." << std::endl;
        } else if (command == "DeleteEdge") {
          inStream >> vertex1;
          inStream >> vertex2;
          graph.DeleteEdge(vertex1, vertex2);
          outStream << "Edge (" << vertex1 << ", " << vertex2
                    << ") was deleted." << std::endl;
        } else if (command == "DeleteVertex") {
          inStream >> vertex1;
          graph.DeleteVertex(vertex1);
          outStream << "Vertex " << vertex1 << " was deleted." << std::endl;
        } else if (command == "Print") {
          graph.Print(outStream);
        } else if (command == "MakeEmpty") {
          outStream << "Graph has been emptied" << std::endl;
          graph.MakeEmpty();
        } else if (command == "BFS") {
          inStream >> vertex1;
          distance = graph.BreadthFirstSearch(vertex1);
          outStream << "Breadth-First Search" << std::endl;
          for (auto const &pair : distance) {
            outStream << pair.first << ": " << pair.second << std::endl;
          }
        } else {
          std::cout << "Command is not recognized." << std::endl;
        }
      } catch (FullQueue) {
        outStream << "FullQueue exception thrown." << std::endl;
      } catch (EmptyQueue) {
        outStream << "EmtpyQueue exception thrown." << std::endl;
      }
    }
    numCommands++;
    std::cout << " Command number " << numCommands << " completed."
              << std::endl;
    inStream >> command;
  }
  outStream << "Testing completed." << std::endl;
  std::cout << "Quit" << std::endl << "Testing completed." << std::endl;
}