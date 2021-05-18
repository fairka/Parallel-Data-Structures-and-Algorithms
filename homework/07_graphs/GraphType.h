/*************************************************************************
 *
 * Assignment 5: BFS Algorithm, vertex
 *
 * File Name: GraphType.h
 * Course:    CPTR 242
 *
 */
#ifndef GRAPH_TYPE_H
#define GRAPH_TYPE_H

#include "QueueType.h"
#include <fstream>
#include <map>

using namespace std;

const int NULL_EDGE = 0;

template <class VertexType>
// Assumption: VertexType is a type for which the "=",
// "==", and "<<" operators are defined
class GraphType {
public:
  GraphType();         // Default of 50 vertices
  GraphType(int maxV); // maxV <= 50
  ~GraphType();

  void AddUnusedVertex(int index);
  void AddVertex(VertexType);
  void AddEdge(VertexType, VertexType, int);
  void DeleteEdge(VertexType, VertexType);
  void DeleteVertex(VertexType);
  void GetToVertices(VertexType, QueueType<VertexType> &);
  int IndexIs(VertexType);
  void MakeEmpty();
  void Print(std::ostream &dataFile);
  int WeightIs(VertexType, VertexType);

  map<VertexType, int> BreadthFirstSearch(VertexType startVertex);
  // Pre: startVertex is in the set of vertices
  // Post: Returns map of Graph Tree using Breadth-First Search algorithm by
  // given startVertex

private:
  int numVertices;
  int maxVertices;
  VertexType *vertices;
  int edges[50][50] = {};
  QueueType<VertexType> unusedVertices;
  bool *marks; // marks[i] is mark for vertices[i].
};

#endif // GRAPH_TYPE_H