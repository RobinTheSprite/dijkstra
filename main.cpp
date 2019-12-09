#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Graph.h"
using std::vector;
using std::priority_queue;

struct Vertex
{
    size_t id, distance;
};

vector<int> getShortestPaths(const Graph& graph, int startingVertex)
{
    auto vertexGreater = [](auto a, auto b){return a.distance > b.distance;};
    priority_queue<Vertex, vector<Vertex>, decltype(vertexGreater)> openSet(vertexGreater);
    vector<int> closedSet(graph.adjList.size(), -1);

    //Set initial distances and starting point
    for (auto i = 0ul; i < graph.adjList.size(); ++i)
    {
        if (i == startingVertex)
        {
            openSet.push({i, 0});
        }
        else
        {
            openSet.push({i, std::numeric_limits<int>::max()});
        }
    }

    size_t verticesLeft = closedSet.size();
    size_t count = 0;
    while (verticesLeft)
    {
        count++;
        //Get minimum distance
        auto currentVertex = openSet.top();
        openSet.pop();

        //If vertex is not in the closed set, put it there
        if (closedSet[currentVertex.id] == -1)
        {
            closedSet[currentVertex.id] = currentVertex.distance;
            --verticesLeft;
        }

        //Adjust distances of adjacent nodes
        for (auto edge : graph.adjList[currentVertex.id])
        {
            auto distanceFromCurrent = currentVertex.distance + edge.weight;
            openSet.push({edge.dest, distanceFromCurrent});
        }
    }

    return closedSet;
}

int main()
{
    Graph g({{0, 1, 4},
             {1,2,8},
             {2,3,7},
             {3,4,9},
             {4,5,10},
             {5,6,2},
             {6,7,1},
             {7,8,7},
             {1,7,11},
             {2,8,2},
             {8,6,6},
             {2,5,4},
             {3,5,14},
             {7,0,8}},9);

    for (auto v : getShortestPaths(g, 0))
    {
        std::cout << v << std::endl;
    }

    return 0;
}