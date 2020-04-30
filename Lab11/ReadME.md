### Grant Dawson

# Lab10 : Graphs and BFS algorithm

### In this lab you will focus on the following objectives:
*  Review basic graph representations and operations
*  Develop familiarity with the c++ standard library tools.
*  Solve the problems of implementing abstract algorithms with programming languages.
## Questions:

#### (a)  Summarize your approach to the problem, and how your code addresses the abstractions needed.
  I started with the code form Lab10 and went from there. I made some new functions along with some new data in the vertices data structs. This enabled me to not need 5 different maps for color, start time, finish time, ect.

#### (b)  What is the theoretical time complexity of your algorithms (best and worst case), in terms of the size of the tree?  Be sure to vary the parameters enough to use the observations to answer the next questions! All these time analyses are about my functions and not the std functions I use:
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

#### (c)  How could the code be improved in terms of usability, efficiency, and robustness?
    There are no real improvements I could see that I need to do. The Graph class is efficient on memory/it isn't throwing around data T around but indexes. Perhaps instead of automatically saving the transpose only do it while requested.
