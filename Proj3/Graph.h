#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <fstream>

template<class T>
class Graph{
	private:
		struct VertexStuff{
			T data;
			double cost;

			VertexStuff(T d, double c){
				data = d;
				cost = c;
			}
		};
		std::map<T, std::vector<VertexStuff>> vertices;
		//std::map<T, std::vector<T>> verticesParent;

	public:
		Graph();
		//Graph(Graph&);
		//Graph& operator=(Graph&);
		//~Graph();

		std::vector<typename Graph<T>::VertexStuff> findStarts();//Finds all vertices that are starting points/dont have anything pointing to it
		typename Graph<T>::VertexStuff findEnd(); //Finds the end of the jobs/where to stop

		void addData(std::string);//takes in file name and adds all the data from the file into the map

		//std::map<int, std::vector<T>> findPath();//TODO This is the hard part bois, we fins all paths and rank them 1 being the best and n being the worst

		void addVertex(T);
		void addEdge(T,T,double);
		void print();
		// void printBfs(T);
};

#include "Graph.cpp"
#endif
