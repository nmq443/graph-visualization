#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <set>

class UndirectedGraph
{
public:
    UndirectedGraph();
    UndirectedGraph(int num_vertices);

    void AddEdge(int u, int v, int weight);
    void DisplayGraph();
    void CreateRandomGraph(int maximum_vertices, int maximum_weight);
private:
    int num_vertices;
    std::vector<std::list<std::pair<int, int>>> graph;
    std::vector<std::set<int>> not_allowed;
};

#endif // GRAPH_H
