// Graph.h
// Created by Mark on 8/26/2019.
// Compliments of Techie Delight https://www.techiedelight.com/graph-implementation-using-stl/

#ifndef TEXT_RPG_GRAPH_H
#define TEXT_RPG_GRAPH_H

#include <vector>
using std::vector;

// data structure to store graph edges
struct Edge {
    size_t src, dest, weight;
};


// class to represent a graph object
class Graph
{
  private:
    struct Endpoint
    {
        size_t dest, weight;
    };
  public:
    // construct a vector of vectors to represent an adjacency list
    vector<vector<Endpoint>> adjList;

    // Graph Constructor
    Graph(vector<Edge> const &edges, int N);

   void addVertex();

   void addEdge(Edge);
};

#endif //TEXT_RPG_GRAPH_H
