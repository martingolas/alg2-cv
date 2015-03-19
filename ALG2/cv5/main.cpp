#include "Graph.h"
#include <iostream>

void main()
{
	Graph *g = new Graph(8);

	g->AddEdge(1, 2);
	g->AddEdge(1, 3);
	g->AddEdge(2, 4);
	g->AddEdge(2, 5);
	g->AddEdge(3, 6);
	g->AddEdge(3, 7);
	g->AddEdge(5, 8);

	g->TraverseBFS(1);

	std::cin.get();
}