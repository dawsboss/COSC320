### Grant Dawson

# Lab10 : Graphs and BFS algorithm

### In this lab you will focus on the following objectives:
*  Review basic graph representations and operations
*  Develop familiarity with the c++ standard library tools
*  Implement method to find an approximate vertex cover of a simple undirected graph
## Questions:

#### (a)  Summarize your approach to the problem, and how your code addresses the abstractions needed.
    I started out by taking all the code from my previous lab 11 and proceeded to add on to it. I added three new functions and a new vector for the whole class called "Edges." The new vector will hold every edge between all nodes. This new vector will be used in the new functions, AVC, RAVC, and BVC.
      1. AVC  - Approximate vertex cover
      2. RAVC - Random approximate vertex cover
      3. BVC  - Brute-force vertex cover
#### (b)  What is the theoretical time complexity of your algorithms (best and worst case), in terms of the size of the tree?  Be sure to vary the parameters enough to use the observations to answer the next questions!
    1. addVertex : This will run in O(1), I run a simple command to add the data to the map with a small check in-front that will make sure it is not adding any old data.
    2. addEdge : This will run in O(v), I run another simple command to add the data to the maps vector. There are several small checks to makes sure that the edge that is being given the new edge is real and that the new edge already exists. But the heavy hitting test comes from when we want to make sure we are not repeating ourselves with the same edges for vertices.
      * Worst case: O(n) - This comes from when the "new" edge is actually new and we need to add it.
      * Best case: O(1) - This comes form when we see right off the start that the "new" edge isn't new at all.
    3. print : This will run O(v+e) is the fancy way of saying it. I run through ever node and print it and it's other vertices that is points to.
      * Worst case: O(n^2) - This comes from the case that all vertices have an edge to ever vertex in the graph. So there will be n elements with n items in it's vector of edges.
      * Best case: O(n) - This comes from the case that all vertices do not have any edges
    4. DFS : O(v+e)
      * Worst case: O(n^2) - This comes from the case that all vertices have an edge to ever vertex in the graph. So there will be n elements with n items in it's vector of edges.
      * Best case: O(n) - This comes from the case that all vertices do not have any edges
    5. Topological Sort : O(+v+e) : Difference between this and DFS is that this sort will make a new map and fill it with a loop of O(v) and print with O(v)
      * Worst case: O(n^2) - This comes from the case that all vertices have an edge to ever vertex in the graph. So there will be n elements with n items in it's vector of edges.
      * Best case: O(n) - This comes from the case that all vertices do not have any edges
    6. SCC : O(v+e) : Difference between this and DFS is that
      * Worst case: O(n^2) - This comes from the case that all vertices have an edge to ever vertex in the graph. So there will be n elements with n items in it's vector of edges.
      * Best case: O(n) - This comes from the case that all vertices do not have any edges

    These all have very the same big O's because they all call DFS and us the data made from DFS to formulate extra data about the graph. All the big O's are different base multiples of v and e
    7. AVC  - O()
      * Worst case: When for every 2 nodes there is an edge between them. Each node has one edge with on other node. This case comes from when it takes the most nodes to cover the whole graph (directed). In this case it would give you your min vertex cover.
      * Best case: When every edge has at least one of the same node/the is when central node.  This means when you do the first loops of the while loop you will be done because one of the nodes were in every single edge and will return after the first loop.
    8. RAVC - O()
    * Worst case: When for every 2 nodes there is an edge between them. Each node has one edge with on other node. This case comes from when it takes the most nodes to cover the whole graph (directed). In this case it would give you your min vertex cover.
    * Average case:
    * Best case: When every edge has at least one of the same node/the is when central node.  This means when you do the first loops of the while loop you will be done because one of the nodes were in every single edge and will return after the first loop.
    9. BVC  - O((V+E)2^n)
      * Best/Worst case: This being the brute force method of solving the problem, it is extremely inefficient and runs the same amount of time just depending on how many nodes you have (n).

#### (c)  Find and provide some specific graph instances where the computed cover is always suboptimal. Show how bad the approximation is and how closes it gets to its best and worst theoretical case.
    The most suboptimal solutions that the AVC or RAVC will produce occurs when the nodes are parsed into pairs with a single edge between them.
    * NOTE: There are other suboptimal solutions that just this case
    The most optimal solution comes form the case that there are no edges between any nodes
#### (d)  For what graph structures is the algorithm close to the optimal?  Far from it?
    See (c) above

#### (e)  How does the randomized version compare with the deterministic one on average?
AVC:                BVC:
1 8 2 4 3 10       1 2 3 4 7
RAVC:
1 8 3 9 2 4
2 10 6 1 3 9 7 8
3 2 6 1 4 10 7 8
2 4 3 9 6 1 7 8
2 5 7 8 3 9 6 1 4 10
2 10 3 9 1 8
2 10 1 8 3 9
2 10 6 1 3 9 7 8
2 4 3 10 1 8
1 8 2 10 3 9

On average the RAVC suggests: 72/10 = 7.2 ~ 7 vertices to cover the graph.


#### (f)  How could the code be improved in terms of usability, efficiency, and robustness?
  This code is fairly straight forwards. Prehpas I could have made multiple functions for each of the main functions that would return other things than the indexes of the nodes in the calulated cover (return stuff like the data). Also I suppose I could have also broken some of the code into more functions to make it easier to see what each function does.
