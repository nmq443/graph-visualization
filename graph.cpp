#include "graph.h"

UndirectedGraph::UndirectedGraph()
{
    this->num_vertices = 0;
    this->graph.resize(0);
    this->not_allowed.resize(0);
}

UndirectedGraph::UndirectedGraph(int num_vertices)
{
    this->num_vertices = num_vertices;
    this->graph.resize(num_vertices);
    this->not_allowed.resize(num_vertices);
}

void UndirectedGraph::AddEdge(int u, int v, int weight)
{
    graph[u].push_back({v, weight});
    graph[v].push_back({u, weight});

    not_allowed[u].insert(v);
    not_allowed[v].insert(u);
}

void UndirectedGraph::DisplayGraph()
{
    if (num_vertices == 0)
    {
        std::cout << "Graph has no vertex!\n";
    }

    for (int u = 0; u < this->num_vertices; u++)
    {
        std::list<std::pair<int, int>>::iterator v;
        std::cout << "Vertex no " << u << ": ";
        int last_edge = 0;
        for (v = graph[u].begin(); v != graph[u].end(); v++)
        {
            std::cout << "{" << v->first << ", " << v->second << "}";
            last_edge++;
            if (last_edge < graph[u].size())
            {
                std::cout << ", ";
            }
        }
        std::cout << "\n";
    }
}

void UndirectedGraph::CreateRandomGraph(int maximum_vertices, int maximum_weight)
{
    num_vertices = (int) (rand() % maximum_vertices);
    graph.resize(num_vertices);
    not_allowed.resize(num_vertices);

    for (int u = 0; u < num_vertices; u++)
    {
        for (int v = 0; v < num_vertices; v++)
        {
            if (u == v)
            {
                continue;
            }

            if (not_allowed[u].find(v) != not_allowed[u].end())
            {
                continue;
            }

            double p = (rand() % maximum_vertices) / 100;
            if (p <= 0.5)
            {
                int rand_weight = (int)(rand() % maximum_weight);
                this->AddEdge(u, v, rand_weight);
            }
        }
    }
}
