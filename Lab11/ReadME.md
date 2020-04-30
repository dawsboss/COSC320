### Grant Dawson

# Lab10 : Graphs and BFS algorithm

### In this lab you will focus on the following objectives:
*  Review basic graph representations and operations
*  Develop familiarity with the c++ standard library tools.
*  Solve the problems of implementing abstract algorithms with programming languages.
## Questions:

#### (a)  Summarize your approach to the problem, and how your code addresses the abstractions needed.
  I started coding this lab by making the base of the class work before touching the BFS algorithm. I made a map that maps the data to a vector of the given data. This is to hold the vertex and what other vertices it points to. Once I had this idea down and done with a print function, I attempted the BFS print. I stated by making maps that hold the meta data needed for the algorithm to operate. These maps are the same size as the vertices map because each vertex has it's own metadata. Which this was strange because the loop to fill on map could be used for all of them and the loop does not use any data from the maps being filled. This was a foreign idea to me but I pressed on. I came to the actual algorithm and began catching myself using operator[] and find interchangeable which this took some research to find out why that is a bad practice and an error. Finally bring me to the print where similar to the loop that filled maps it didn't use anything that was actually being printed. Now looking bakc this although weird makes complete sense because the maps all held the same number of vertices no mater what just the second item in the pairs would differ.

#### (b)  What is the theoretical time complexity of your algorithms (best and worst case), in terms of the size of the tree?  Be sure to vary the parameters enough to use the observations to answer the next questions! All these time analyses are about my functions and not the std functions I use:
    1. addVertex : This will run in O(1), I run a simple command to add the data to the map with a small check in-front that will make sure it is not adding any old data.
    2. addEdge : This will run in O(e), I run another simple command to add the data to the maps vector. There are several small checks to makes sure that the edge that is being given the new edge is real and that the new edge already exists. But the heavy hitting test comes from when we want to make sure we are not repeating ourselves with the same edges for vertices.
      * Worst case: O(n) - This comes from when the "new" edge is actually new and we need to add it.
      * Best case: O(1) - This comes form when we see right off the start that the "new" edge isn't new at all.
    3. print : This will run O(v+e) is the fancy way of saying it. I run through ever node and print it and it's other vertices that is points to.
      * Worst case: O(n^2) - This comes from the case that all vertices have an edge to ever vertex in the graph. So there will be n elements with n items in it's vector of edges.
      * Best case: O(n) - This comes from the case that all vertices do not have any edges
    4. DFS : O(e+v)
      * Worst case: O(n^2) - This comes from the case that all vertices have an edge to ever vertex in the graph. So there will be n elements with n items in it's vector of edges.
      * Best case: O(n) - This comes from the case that all vertices do not have any edges
    5. Topological Sort : O(e+v) : Difference between this and DFS is that this sort will make a new map and fill it with a loop of O(v) and print with O(v)
      * Worst case: O(n^2) - This comes from the case that all vertices have an edge to ever vertex in the graph. So there will be n elements with n items in it's vector of edges.
      * Best case: O(n) - This comes from the case that all vertices do not have any edges
    6. SCC : O(v+e) : Difference between this and DFS is that 
      * Worst case: O(n^2) - This comes from the case that all vertices have an edge to ever vertex in the graph. So there will be n elements with n items in it's vector of edges.
      * Best case: O(n) - This comes from the case that all vertices do not have any edges

    These all have very the same big O's because they all call DFS and us the data made from DFS to formulate extra data about the graph. All the big O's are different base multiples of v and e

#### (c)  How could the code be improved in terms of usability, efficiency, and robustness?
  I wish I had caught myself earlier on in my BFS implementation with my mess of .find() function calls and operator[] calls and stuck to one or the other (I would rather have operator []). I also could clean some of these functions if statements checking if the function was called on valid data.
