#include "Graph.h"
#include <iostream>
#include <cstdlib>
#include <stack>

Graph::Graph(int size)
{
	rootVertex = NULL;
	for (int i = 1; i <= size; i++)
	{
		vertex *newVertex = new vertex();
		newVertex->value = i;
		newVertex->nextVertex = rootVertex;
		rootVertex = newVertex;
	}
}

Graph::~Graph()
{

}

void Graph::AddEdge(int srcVertex, int destVertex)
{
	if (srcVertex == destVertex)
	{
		std::cerr << "ERROR: Source and destination vertex should be different..." << std::endl;
		return;
	}

	vertex *srcV = FindVertex(srcVertex), *destV = FindVertex(destVertex);
	if (srcV == NULL || destV == NULL)
	{
		std::cerr << "Source or destination vertex not found..." << std::endl;
		return;
	}

	// Append edge with destVertex to srcVertex->edge
	edge *newEdge = new edge;
	newEdge->next = srcV->edge;
	srcV->edge = newEdge;
	srcV->edge->vertex = destV;
	// Append edge with srcVertex to destVertex->edge
	newEdge = new edge;
	newEdge->next = destV->edge;
	destV->edge = newEdge;
    destV->edge->vertex = srcV;

	std::cout << "Adding edge from " << srcV->value << " to " << destV->value << std::endl;
}


vertex* Graph::FindVertex(int value)
{
	vertex *srcV = rootVertex;
	// Find pointers to source and destination vertices
	while (srcV != NULL)
	{
		if (srcV->value == value)
			break;
		srcV = srcV->nextVertex;
	}
	return srcV;
}

void Graph::TraverseBFS(int startVertexValue)
{
	
}