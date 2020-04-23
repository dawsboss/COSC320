//Defualt constructor
template<class T>
Graph<T>::Graph(){

}

//Copy Constructor
/*template<class T>
Graph<T>::Graph(Graph& B){
	vertices(B.vertices);
	verticesParent(B.verticesParent);
}*/

//= operaotor
/*template<class T>
Graph& Graph<T>::operaotr=(Graph& B){
	if(vertices.size() != 0){
		delete vertices;
	}
	if(verticesParent.size() != 0){
		delete vertices;
	}
	vertices(B.vertices);
	verticesParent(B.verticesParent);
}*/

//Deconstructor
/*template<class T>
Graph<T>::~Graph(){
		delete vertices;
		delete verticesParent;
}*/

//Finds all vertices that are starting points/dont have anything pointing to it
template<class T>
std::vector<typename Graph<T>::VertexStuff> Graph<T>::findStarts(){

}

//Finds the end of the jobs/where to stop
template<class T>
typename Graph<T>::VertexStuff Graph<T>::findEnd(){

}

//takes in file name and adds all the data from the file into the map
template<class T>
void Graph<T>::addData(std::string){

}


//addVertex : adds a new vertex to the map - starts with no edges
template<class T>
void Graph<T>::addVertex(T newData){
	if(vertices.find(newData) == vertices.end()){ //will check if the element is already there TODO broken with find()
		vertices.insert(std::pair<T, std::vector<VertexStuff>>(newData, std::vector<VertexStuff>()));
	}else{
		std::cout<<newData<<" was already in the list!\n";
	}
}

//addEdge : This will give the parent node a edge to the child node
template<class T>
void Graph<T>::addEdge(T Parent, T child, double price){
	if(vertices.find(Parent) != vertices.end()){ //if there is an element to point from
		if(vertices.find(child) != vertices.end()){ //if there is an element to point too
			bool inAlready = false;
			for(auto j=vertices[Parent].begin(); j!=vertices[Parent].end(); ++j){
				//std::cout<<*j<<" ";
				if((*j).data==child){
					//std::cout<<" REE ";
					inAlready=true;
					break;
				}
			}
			if(!inAlready){
				vertices[Parent].push_back(VertexStuff(child, price));
			}else{
				std::cout<<"Edge already included!"<<std::endl;
			}
		}else{
				std::cout<<"There is no "<<child<<" to point too!"<<std::endl;
		}
	}else{
		std::cout<<"There is no "<<Parent<<" to point from!"<<std::endl;
	}

}

//print : prints out all verticies and where they point
template<class T>
void Graph<T>::print(){
	int size = vertices.size();
		for( auto i=vertices.begin(); i!=vertices.end(); ++i){
			std::cout<<"Vector: "<<i->first<<" | Point to: ";

			for(auto j=i->second.begin(); j!=i->second.end(); ++j){
				std::cout<<(*j).data<<"'s' cost: "<<(*j).cost<<" | ";
			}
			std::cout<<std::endl;
	}
}

// //printBfs : prints out all relations and fast path form a specfic node to the others
// template<class T>
// void Graph<T>::printBfs(T B){
// 	enum color_t{
// 		WHITE, GREY, BLACK
// 	};
// 	std::map<T, color_t> color;
// 	std::map<T, int> distance;
// 	std::map<T, T*> parent;
//
// 	for(auto i=vertices.begin(); i!=vertices.end(); ++i){
// 		color.insert(std::pair<T, color_t>(i->first, WHITE));
// 		distance.insert(std::pair<T, int>(i->first, -1));
// 		parent.insert(std::pair<T, T*>(i->first, nullptr));
// 	}
// 	auto S = vertices.find(B);
// 	color.find(B)->second = GREY;
// 	distance.find(B)->second = 0;
// 	parent.find(B)->second = nullptr;
//
// 	std::queue<T> q;
// 	q.push(B);
// 	while(!q.empty()){
// 		T U = q.front();q.pop();
// 		for(auto j=vertices[U].begin(); j!=vertices[U].end(); ++j){
// 				std::cout<<"Node "<<U<<" edge: "<<*j<<std::endl;
// 			if(color.find(*j)->second == WHITE){
// 				color.find(*j)->second = GREY;
// 				distance.find(*j)->second = distance.find(U)->second +1;
// 				parent.find(*j)->second = &U;
// 				std::cout<<parent.find(*j)->first<<"'s parent is "<<U<<" or "<<&U<<std::endl;
// 				q.push(*j);
// 			}
// 			color.find(*j)->second = BLACK;
// 		}
// 	}
//
//
//
// 	std::cout<<"Starting at: "<<B<<std::endl;
// 	for(auto i=vertices.begin(); i!=vertices.end(); ++i){
// 		if(parent[i->first] == nullptr){
// 				std::cout<<"Node: "<<i->first<< " distance: "<<distance[i->first]<< " parent: No Parents"<<std::endl;
// 		}else{
// 		std::cout<<"Node: "<<i->first<< " distance: "<<distance[i->first]<< " parent: "<<*parent[i->first]<<std::endl;
// 		}
// 	}
//
// }






//gamer
