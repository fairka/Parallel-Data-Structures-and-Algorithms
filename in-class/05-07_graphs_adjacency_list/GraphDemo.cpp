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

  Graph graph3;

  Vertex *vertexA3 = graph3.AddVertex("A");
  Vertex *vertexB3 = graph3.AddVertex("B");
  Vertex *vertexC3 = graph3.AddVertex("C");
  Vertex *vertexD3 = graph3.AddVertex("D");

  graph3.AddUndirectedEdge(vertexA3, vertexB3);
  graph3.AddUndirectedEdge(vertexA3, vertexD3);
  graph3.AddUndirectedEdge(vertexB3, vertexC3);
  graph3.AddUndirectedEdge(vertexB3, vertexD3);

  cout << endl << "Print graph3" << endl;
  printGraph(graph3);

Graph graph4;

  Vertex *vertex1 = graph4.AddVertex("1");
  Vertex *vertex3 = graph4.AddVertex("3");
  Vertex *vertex5 = graph4.AddVertex("5");
  Vertex *vertex7 = graph4.AddVertex("7");
  Vertex *vertex9 = graph4.AddVertex("9");
  Vertex *vertex11 = graph4.AddVertex("11");

  graph4.AddDirectedEdge(vertex1, vertex3);
  graph4.AddDirectedEdge(vertex3, vertex1);
  graph4.AddDirectedEdge(vertex11, vertex1);
  graph4.AddDirectedEdge(vertex9, vertex1);
  graph4.AddDirectedEdge(vertex9, vertex9);
  graph4.AddDirectedEdge(vertex5, vertex9);
  graph4.AddDirectedEdge(vertex5, vertex7);

  cout << endl << "Print Graph4"<< endl;
  printGraph(graph4);

  return 0;
}
