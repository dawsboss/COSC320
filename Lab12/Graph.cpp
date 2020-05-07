//Defualt constructor
template<class T>
Graph<T>::Graph(bool d){
	dir = d;
}
template<class T>
Graph<T>::Graph(){
}

template<class T>
void Graph<T>::initDIR(bool d){
	dir = d;
}

//Prints back what type of a graph the current session is set to
template<class T>
void Graph<T>::graphType(){
	if(dir){
		std::cout<<"Dirrected"<<std::endl;
	}else{
		std::cout<<"Undirrected"<<std::endl;
	}
}

//Finds all vertices that are starting points/dont have anything pointing to it
template<class T>
std::vector<T> Graph<T>::findStarts(){
	std::vector<T> rtn;
	for( auto i=v.begin(); i!=v.end(); ++i){
		if(i->second.verticesParent.empty()){//If a node has nothing point to it as a vertex then it is a "start"
			rtn.push_back(i->first);
			std::cout<<"start: "<<i->second.data<<std::endl;
		}
	}
	return rtn;
}

//Finds the end of the jobs/where to stop
template<class T>
std::vector<T> Graph<T>::findEnd(){
	std::vector<T> rtn;
	for( auto i=v.begin(); i!=v.end(); ++i){
		if(i->second.vertices.empty()){//If a node doesn;t have any verteces then it is a "end"
			rtn.push_back(i->first);
			std::cout<<"end: "<<i->second.data<<std::endl;
		}
	}
	return rtn;
}

//addVertex : adds a new vertex to the map - starts with no edges
template<class T>
void Graph<T>::addVertex(T newData, double price){
		DFSneeded=true;
		v.insert(std::make_pair(ID, VertexStuff(newData, price, ID)));//Makes a new element in the v map with the given properties (newData and price)
		ID++;//Sets up the ID for the next vertex to be added
}

//addEdge : Adds edge based on index

template<class T>
void Graph<T>::PaddEdge(int Parent, int child){
	if(Parent>=ID || child>=ID || Parent<=0 || child<=0){//Is parent or child invalid?
		std::cout<<"Parent or child invalid/too big!"<<std::endl;// "<<Parent<<" "<<child
		return;
	}

	DFSneeded=true;


	for(auto i=v[Parent].vertices.begin(); i!=v[Parent].vertices.end(); ++i){
		if(*i == child){//Proves that parent and child already havea  connection
			return;
		}
	}
	DFSneeded=true;
	v[Parent].vertices.push_back(child);
	v[child].verticesParent.push_back(Parent);
	Edges.push_back(std::make_pair(Parent,child));
	if(!dir){
		v[child].vertices.push_back(Parent);
		v[Parent].verticesParent.push_back(child);
		Edges.push_back(std::make_pair(child,Parent));
	}
}

//addEdge : adds edge by value
template<class T>//TODO fix this stuff (5,5)edge case
void Graph<T>::addEdge(T Parent, T child){
	int p=-1, c=-1;
	 //std::cout<<"Parent/child "<<Parent<<" "<<child<<"\n";
	for(auto i=v.begin(); i!=v.end(); ++i){
		// std::cout<<"i->second.data "<<i->first<<" "<<i->second.data<<std::endl;
		if(i->second.data == Parent)
			p=i->first;
		if(i->second.data == child)
			c=i->first;
	}
	PaddEdge(p,c);
}

//print : prints out all verticies and where they point
template<class T>
void Graph<T>::print(){
	DFS();
	std::cout<<"The graph is ";
	if(!Acyclic)
		std::cout<<"NOT ";
	std::cout<<"Acyclic and is ";
	if(!DAG)
		std::cout<<"NOT ";
	std::cout<<"a DAG and is ";
	graphType();

	std::cout<<std::endl;

	for(auto i=v.begin(); i!=v.end(); ++i){//printsd where a node points // runs through all of the nodes
		std::cout<<"Vector: "<<v[i->first].data<<" points to: ";
		for(auto j=v[i->first].vertices.begin(); j!=v[i->first].vertices.end(); ++j){//takes each node's meta data to print
			std::cout<<v[*j].data<<" cost: "<<v[*j].cost<<" ID: "<<i->first<<" | ";
		}
		std::cout<<std::endl;
	}

	std::cout<<std::endl;
	std::cout<<"parents: "<<std::endl;
	std::cout<<std::endl;

	for(auto i=v.begin(); i!=v.end(); ++i){//Prints the same thing as above but what points to one node
		std::cout<<"Vector: "<<v[i->first].data<<" is pointed to by: ";
		for(auto j=v[i->first].verticesParent.begin(); j!=v[i->first].verticesParent.end(); ++j){
			std::cout<<v[*j].data<<"'s' cost: "<<v[*j].cost<<" ID: "<<i->first<<" | ";
		}
		std::cout<<std::endl;
	}

	std::cout<<std::endl;
	std::cout<<"EDGES: "<<std::endl;
	std::cout<<std::endl;

	for(auto i=Edges.begin(); i!=Edges.end(); ++i){
		std::cout<<"("<<i->first<<","<<i->second<<")"<<std::endl;
	}
}

template<class T>
void Graph<T>::DFS(){
	if(DFSneeded){
		for(auto i=v.begin(); i!=v.end(); ++i){
			v[i->first].color=WHITE;
		}
		time=0;
		for(auto i=v.begin(); i!=v.end(); ++i){
			if(v[i->first].color == WHITE)
				DFS_Visit(i->first);
		}
		DFSneeded=false;
		if(!dir){
			DAG=false;
			return;
		}
		if(!Acyclic){
			DAG=false;
		}else{
			DAG=true;
		}

	}
}

template<class T>
void Graph<T>::DFS_Visit(int node){
	time++;
	//std::cout<<"time: "<<time<<" node: "<<node<<" "<<v[node].data<<std::endl;
	v[node].start=time;
	v[node].color=GREY;
	for(auto i=v[node].vertices.begin(); i!=v[node].vertices.end(); ++i){
		//std::cout<<"!!!!"<<v[node].color<<" node: "<<node<<" "<<v[node].data<<std::endl;
		if(v[*i].color == GREY)
			Acyclic=false;
		if(v[*i].color == WHITE){
			v[*i].P=node;
			DFS_Visit(*i);
		}
	}
	v[node].color=BLACK;
	time++;
	//std::cout<<"====time: "<<time<<" node: "<<node<<" "<<v[node].data<<std::endl;
	v[node].finish=time;
}

template<class T>
void Graph<T>::topologicalSort(){
	DFS();
	if(!DAG){
		std::cout<<"Graph is not a DAG! Can't topologicalSort..."<<std::endl;
		return;
	}

	std::map<int,T> topolist;

	for(auto i=v.begin(); i!=v.end(); ++i){
		topolist.insert(std::pair<int,T>(i->second.finish,i->second.data));
	}

	for(auto i=topolist.rbegin(); i!=topolist.rend(); ++i){
		std::cout<<i->second<<" time "<<i->first<<"| ";
	}
	std::cout<<std::endl;
}

template<class T>
void Graph<T>::SCC(){
	DFS();
	std::map<int,int> topolist;
	for(auto i=v.begin(); i!=v.end(); ++i){
		topolist.insert(std::pair<int,int>(i->second.finish,i->first));
		v[i->first].color=WHITE;
	}
	time=0;
	for(auto i=topolist.rbegin(); i!=topolist.rend(); ++i){
		//std::cout<<"Checking: "<<i->second<<std::endl;
		if(v[i->second].color == WHITE){
			SCCDFS_Visit(i->second);
		}
		std::cout<<std::endl;
	}
}

template<class T>
void Graph<T>::SCCDFS_Visit(int node){
	time++;
	v[node].color=GREY;
	for(auto i=v[node].verticesParent.begin(); i!=v[node].verticesParent.end(); ++i){
		if(v[*i].color == WHITE){
			v[*i].P=node;
			SCCDFS_Visit(*i);
		}
	}
	v[node].color=BLACK;
	time++;
	std::cout<<v[node].data<<" ";
}

//finds the aproximate vertex cover
template<class T>
std::vector<int> Graph<T>::AVC(){
	std::vector<int> rtn;
	std::vector<std::pair<int,int>> copyEdges = Edges;//copies the on going list of edges (don't want to ruin it)
	int u,v;

	// if(copyEdges.empty()){
	// 	for(auto i=v.begin(); i!=v.end(); ++i){
	// 		rtn.push_back(i->first);
	// 	}
	// 	return rtn;
	// }

	while(!copyEdges.empty()){
		auto i = copyEdges.begin();
		rtn.push_back(i->first);
		rtn.push_back(i->second);
		u=i->first;
		v=i->second;

		for(auto j=copyEdges.begin(); j!=copyEdges.end(); ){
			if(j->first==u || j->second==u || j->first==v || j->second==v){
				j = copyEdges.erase(j);
			}else{
				++j;
			}
		}
	}
	return rtn;
}


template<class T>
std::vector<int> Graph<T>::RAVC(){
	std::vector<int> rtn;
	std::vector<std::pair<int,int>> copyEdges = Edges;//copies the on going list of edges (don't want to ruin it)
	int u,v;

	// if(copyEdges.empty()){
	// 	for(auto i=v.begin(); i!=v.end(); ++i){
	// 		rtn.push_back(i->first);
	// 	}
	// 	return rtn;
	// }

	while(!copyEdges.empty()){
		auto i = copyEdges.begin();
		for(int w=0; w<rand()%copyEdges.size(); w++){
			++i;
		}
		rtn.push_back(i->first);
		rtn.push_back(i->second);
		u=i->first;
		v=i->second;

		for(auto j=copyEdges.begin(); j!=copyEdges.end(); ){
			if(j->first==u || j->second==u || j->first==v || j->second==v){
				j = copyEdges.erase(j);
			}else{
				++j;
			}
		}
	}
	return rtn;
}

//int r = rand()%Prime.size();
//auto edge =ePrime[r];




template<class T>
bool Graph<T>::isVertexCover(std::vector<int> d){
	for(auto i=Edges.begin(); i!=Edges.end(); ++i){
		//std::cout<<"testing edges"<<std::endl;
		bool covered=false;
		for(auto j=d.begin(); j!=d.end(); ++j){
			//std::cout<<"isVertexCover===\n	i-first: "<<i->first<<" i-second: "<<i->second<<" *j: "<<*j<<std::endl;
			if(i->first==*j || i->second==*j){
				covered = true;
			}
		}
		if(!covered)
			return false;
	}
	return true;
}

//
template<class T>
std::vector<int> Graph<T>::BVC(){
	std::vector<int> tester;
	std::vector<int> rtn;
	int binary;

	// 1 == 0000001 == 1 << 0 == 1 << (1-1)
	// 2 == 0000010 == 1 << 1 == 1 << (2-1)
	// 4 == 0000100 == 1 << 2

	int n = v.size();
	int rtnSize = n+1;
	// to check the 3rd bit, e.g. 0100)2 = 4)10
	// binary & 4 == 1 iff the 3rd bit is 1

	// test every binary up to 2^n - 1
	for(binary = 0; binary < 1<<n; binary++){
		tester.clear(); // empty out tester

		// e.g. binary == 12_10 == 01100_2

		// for every "1" in the binary put the corresponding vertex into tester
		for(int i = 0; i<n; i++){
		  // to check the ith bit:
			if(binary & 1<<i){
				// add v[i] to the subset
				tester.push_back(i+1);
				//std::cout << i+1 << " ";
			}
		}
		//std::cout << std::endl;
		// if isCover(test) blah blah
		if(isVertexCover(tester) && tester.size() < rtnSize){
			//std::cout<<"AM I true?"<<std::endl;
			rtn=tester;
			rtnSize=rtn.size();
		}
	}
	return rtn;
}
