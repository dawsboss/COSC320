#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <vector>
#include <queue>

template<class T>
class Graph{
	private: 
		/*struct VertexStuff{
			
		};*/
		std::map<T, std::vector<T>> vertices;	
		//std::map<T, std::vector<T>> verticesParent;

	public:
		Graph();
		//Graph(Graph&);
		//Graph& operator=(Graph&);
		//~Graph();

		void addVertex(T);
		void addEdge(T,T);
		void print();
		void printBfs(T);
};

#include "Graph.cpp"
#endif
