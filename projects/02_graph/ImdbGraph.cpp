/*************************************************************************
 *
 * Project: ImdbGraph implementation
 *
 * File Name: ImdbGraph.cpp
 * Name:      ??
 * Course:    CPTR 242
 * Date:      ??
 *
 */
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "GraphAdjList.h"
#include "ImdbGraph.h"
#include "SLelement.h"
#include "data_src/ActorMovieIMDB.h"

using namespace bridges;

// Constructor
ImdbGraph::ImdbGraph() {}

// Destructor
ImdbGraph::~ImdbGraph() {}

// Function: Adds a vertex to the graph.
// Pre:  Graph has been initialized.
// Post: The actor or movie will be added as a vertex.
//          No duplicate vertics will be created.
void ImdbGraph::AddVertex(string actorOrMovie) {
  graph.addVertex(actorOrMovie);
}

// Function: Adds a edge to the graph.
// Pre:  Graph has been initialized.
//          Vertics have been already added to the graph.
// Post: The actor movie edge will be added to the graph.
//          No duplicate edges will be created.
void ImdbGraph::AddEdge(string actorOrMovie, string movieOrActor) {
  // TODO Add code here.
  graph.addEdge(actorOrMovie, movieOrActor, "1");
  graph.addEdge(movieOrActor, actorOrMovie, "1");
}

// Function: Updates the visualization for to vertex.
// Pre:  Graph has been initialized.
//          Vertex is in the graph.
// Post: The vertex will display the new color.
void ImdbGraph::setVertexColor(string actorOrMovie, string color) {
  // TODO Add code here.
  graph.getVisualizer(actorOrMovie)->setColor(color);
  graph.getVisualizer(actorOrMovie)->setSize(50.0);
  graph.getVisualizer(actorOrMovie)->setOpacity(1.);
  graph.getVisualizer(actorOrMovie)->setShape(DIAMOND);
}

// Function: Updates the visualization for to edge.
// Pre:  Graph has been initialized.
//          Edge is in the graph.
// Post: The edge will display the new color.
void ImdbGraph::setEdgeColor(string actorOrMovie, string movieOrActor2,
                             string color) {
  // TODO Add code here.
  graph.getLinkVisualizer(actorOrMovie, movieOrActor2)->setColor(color);
  graph.getLinkVisualizer(movieOrActor2, actorOrMovie)->setColor(color);
  graph.getLinkVisualizer(actorOrMovie, movieOrActor2)->setThickness(10.0);
  graph.getLinkVisualizer(movieOrActor2, actorOrMovie)->setThickness(10.0);
}

// Function: Resets all visualizations to the default.
// Pre:  Graph has been initialized.
// Post: The vertics and edges will display the default color.
void ImdbGraph::ResetVisualizer() {
  // TODO Add code here.
  for (std::string key : graph.keySet()) {
    for (Edge<std::string> edge : graph.outgoingEdgeSetOf(key)) {
      edge.setColor("#4682b4");
    }
    graph.getVisualizer(key)->setColor("#4682b4");
  }
}

// Function: Calculates the Bacon Number for two actors.
//           In addition to returning the number, the graph is update to
//           highlight the path.
//           https://en.wikipedia.org/wiki/Six_Degrees_of_Kevin_Bacon
// Pre:  Graph has been initialized.
//          Vertices are in the graph.
//          Edges connect the actors in the graph.
// Post: The number returned will be lowest number of actor connections used to
// connect them.
//          The graph will visually show the path to connect the actors.
int ImdbGraph::GetBaconNumber(string sourceActor, string destinationActor) {
  // TODO Add code here.
  int baconNumber = 0;
  bool search = false;
  queue<string> Check;
  map<string, string> parent;
  Check.push(sourceActor);

  while (!Check.empty()) {
    string src = Check.front();
    Check.pop();
    if (src == destinationActor) {
      search = true;
      break;
    }
    // all find adjacent actors
    auto adjList = graph.getAdjacencyList(src);
    for (auto edge = adjList; edge != nullptr; edge = edge->getNext()) {
      auto destination = edge->getValue().to();
      if (parent.count(destination) == 0) {
        parent.emplace(destination, src);
        Check.push(destination);
      }
    }
  }
  // get bacon number and change visualizer
  if (search) {
    string curr = destinationActor;
    setVertexColor(curr, "#90ee90");
    while (curr != sourceActor) {
      string node = parent.at(curr);
      LinkVisualizer *edge = graph.getLinkVisualizer(node, curr);
      setEdgeColor(node, curr, "#90ee90");
      setVertexColor(node, "#90ee90");
      baconNumber++;
      curr = node;
    }
    setVertexColor(sourceActor, "#90ee90");
    return baconNumber / 2;
  }
  return -1;
}
