#pragma once
struct edge;

struct vertex {
	int value;
	bool visited;
	vertex *nextVertex;
	edge *edge;
};

struct edge {
	vertex *vertex;
	edge *next;
};

class Graph
{
	public:
		Graph(int size);
		~Graph();
		void AddEdge(int srcVertex, int destVertex);
		void TraverseBFS(int startVertexValue);


	private:
		vertex *rootVertex;

		vertex* FindVertex(int value);
};

