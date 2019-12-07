#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "Graph.h"
using std::vector;
using std::set;

struct Vertex
{
    size_t id, distance;
};

vector<int> getShortestPaths(const Graph& graph, int startingVertex)
{
    vector<Vertex> openSet(graph.adjList.size());
    vector<int> closedSet(graph.adjList.size(), -1);

    for (auto i = 0ul; i < openSet.size(); ++i)
    {
        if (i != startingVertex)
        {
            openSet[i] = {i, std::numeric_limits<int>::max()};
        }
        else
        {
            openSet[i] = {i, 0};
        }
    }

    while (!openSet.empty())
    {
        auto v = std::min_element(openSet.begin(), openSet.end(), [](auto a, auto b){return a.distance < b.distance;});

        if (closedSet[v->id] == -1)
        {
            closedSet[v->id] = v->distance;
        }

        for (auto edge : graph.adjList[v->id])
        {
            auto nextVertex = std::find_if(openSet.begin(), openSet.end(), [edge](auto a){return a.id == edge.dest;});
            auto distanceFromCurrent = v->distance + edge.weight;
            if (distanceFromCurrent < nextVertex->distance)
            {
                openSet[nextVertex - openSet.begin()].distance = distanceFromCurrent;
            }
        }

        openSet.erase(v);
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