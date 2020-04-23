#include "Graph.h"


int main(){
	Graph<int> t;
	t.addVertex(5);
	t.addEdge(5,5,1);
	t.print();

	std::cout<<std::endl;

	t.addVertex(10);
	t.print();

	std::cout<<std::endl;

	t.addVertex(7);
	t.addEdge(7,7,1);
	t.addEdge(7,5,1);
	t.addEdge(7,10,1);
	t.print();

	t.addVertex(11);
	t.addEdge(11,10,1);

	t.addVertex(15);
	t.addEdge(7,15,1);
	t.addEdge(15,11,1);

	std::cout<<std::endl;

	//t.printBfs(7);




	Graph<char> d;
	d.addVertex('a');
	d.addVertex('b');
	d.addVertex('c');
	d.addVertex('d');
	d.addVertex('e');
	d.addVertex('f');
	d.addVertex('g');
	d.addVertex('h');
	d.addVertex('i');
	d.addVertex('j');
	d.addVertex('k');
	d.addVertex('l');

	//not dirrected graph
//a
	d.addEdge('a','e',2);
	d.addEdge('a','f',1);
	d.addEdge('e','a',1);
	d.addEdge('f','a',1);
//b
	d.addEdge('b','e',1);
	d.addEdge('b','j',1);
	d.addEdge('e','b',1);
	d.addEdge('j','b',1);
//c
	d.addEdge('c','d',1);
	d.addEdge('c','g',1);
	d.addEdge('g','c',1);
	d.addEdge('d','c',1);
//d
	d.addEdge('d','c',1);
	d.addEdge('d','k',1);
	d.addEdge('c','d',1);
	d.addEdge('k','d',1);
//e
	d.addEdge('e','a',1);
	d.addEdge('e','b',1);
	d.addEdge('e','f',1);
	d.addEdge('e','i',1);
	d.addEdge('i','e',1);
	d.addEdge('f','e',1);
	d.addEdge('b','e',1);
	d.addEdge('a','e',1);
//f
	d.addEdge('f','a',1);
	d.addEdge('f','e',1);
	d.addEdge('f','g',1);
	d.addEdge('f','i',1);
	d.addEdge('f','j',1);
	d.addEdge('a','f',1);
	d.addEdge('e','f',1);
	d.addEdge('g','f',1);
	d.addEdge('i','f',1);
	d.addEdge('j','f',1);
//g
	d.addEdge('g','c',1);
	d.addEdge('g','h',1);
	d.addEdge('g','f',1);
	d.addEdge('g','j',1);
	d.addEdge('c','g',1);
	d.addEdge('h','g',1);
	d.addEdge('f','g',1);
	d.addEdge('j','g',1);
//h
	d.addEdge('h','g',1);
	d.addEdge('h','k',1);
	d.addEdge('g','h',1);
	d.addEdge('k','h',1);
//i
	d.addEdge('i','e',1);
	d.addEdge('i','f',1);
	d.addEdge('e','i',1);
	d.addEdge('f','i',1);
//j
	d.addEdge('j','f',1);
	d.addEdge('j','g',1);
	d.addEdge('j','b',1);
	d.addEdge('j','k',1);
	d.addEdge('f','j',1);
	d.addEdge('g','j',1);
	d.addEdge('b','j',1);
	d.addEdge('k','j',1);
//k
	d.addEdge('k','j',1);
	d.addEdge('k','d',1);
	d.addEdge('k','h',1);
	d.addEdge('k','l',1);
	d.addEdge('d','k',1);
	d.addEdge('h','k',1);
	d.addEdge('j','k',1);
	d.addEdge('l','k',1);
//l
	d.addEdge('l','k',1);
	d.addEdge('k','l',1);

	//d.addVertex('t'); edge case

	d.print();

	std::cout<<std::endl;

	//d.printBfs('a');








	return 0;
}
