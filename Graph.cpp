// Graph.cpp
// Created by Mark on 8/26/2019.
// Compliments of Techie Delight https://www.techiedelight.com/graph-implementation-using-stl/

#include "Graph.h"

Graph::Graph(vector<Edge> const &edges, int N)
{
    // resize the vector to N elements of type vector<int>
    adjList.resize(N);

    // add edges to the directed graph
    for (auto &edge: edges)
    {
        // insert at the end
        addEdge(edge);

        // Uncomment below line for undirected graph
         adjList[edge.dest].push_back({edge.src, edge.weight});
    }
}

void Graph::addVertex()
{
    adjList.emplace_back();
}

void Graph::addEdge(Edge edge)
{
    adjList[edge.src].push_back({edge.dest, edge.weight});
}

#include "Graph.h"
