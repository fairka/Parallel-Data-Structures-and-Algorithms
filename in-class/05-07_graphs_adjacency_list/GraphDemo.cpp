#include "Graph.h"
#include <iostream>
using namespace std;

void printGraph(Graph graph) {
  // Show the graph's vertices and edges
  for (Vertex *vertex : graph.GetVertices()) {
    cout << "Vertex: " << vertex->label << endl;

    // Show outgoing edges (flights from location)
    cout << "  Node(s) connected from " << vertex->label << ":" << endl;
    for (Edge *outgoingEdge : *graph.GetEdgesFrom(vertex)) {
      cout << "   - " << vertex->label << " to ";
      cout << outgoingEdge->toVertex->label << endl;
    }

    // Show incoming edges (flights to location)
    cout << "  Node(s) connected to " << vertex->label << ":" << endl;
    for (Edge *incomingEdge : *graph.GetEdgesTo(vertex)) {
      cout << "   - " << incomingEdge->fromVertex->label << " to ";
      cout << vertex->label << endl;
    }
  }
}

int main() {
  // Create a new Graph object
  Graph graph1;

  // Add vertices and edges representing plane flights
  Vertex *vertexA = graph1.AddVertex("A");
  Vertex *vertexB = graph1.AddVertex("B");
  graph1.AddUndirectedEdge(vertexA, vertexB, 1);

  cout << "Print undirected graph details" << endl;
  printGraph(graph1);

  // Create a new Graph object
  Graph graph2;

  // Add vertices and edges representing plane flights
  Vertex *vertexA2 = graph2.AddVertex("A");
  Vertex *vertexB2 = graph2.AddVertex("B");
  graph2.AddDirectedEdge(vertexA2, vertexB2, 1);
  graph2.AddDirectedEdge(vertexB2, vertexA2, 1);

  cout << endl << "Print directed graph details" << endl;
  printGraph(graph2);

  return 0;
}
