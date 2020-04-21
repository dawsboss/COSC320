### Grant Dawson

# Lab10 : Graphs and BFS algorithm

### In this lab you will focus on the following objectives:
*  Review basic graph representations and operations
*  Develop familiarity with the c++ standard library tools.
*  Solve the problems of implementing abstract algorithms with programming languages.
## Questions:

#### (a)  Summarize your approach to the problem, and how your code addresses the abstractions needed.
  I started coding this lab by making the base of the class work before touching the BFS algorithm. I made a map that maps the data to a vector of the given data. This is to hold the vertex and what other vertices it points to. Once I had this idea down and done with a print function, I attempted the BFS print. I stated by making maps that hold the meta data needed for the algorithm to operate. These maps are the same size as the vertices map because each vertex has it's own metadata. Which this was strange because the loop to fill on map could be used for all of them and the loop does not use any data from the maps being filled. This was a foreign idea to me but I pressed on. I came to the actual algorithm and began catching myself using operator[] and find interchangeable which this took some research to find out why that is a bad practice and an error. Finally bring me to the print where similar to the loop that filled maps it didn't use anything that was actually being printed. Now looking bakc this although weird makes complete sense because the maps all held the same number of vertices no mater what just the second item in the pairs would differ.

#### (b)  What is the theoretical time complexity of your algorithms (best and worst case), in terms of the size of the tree?  Be sure to vary the parameters enough to use the observations to answer the next questions!
  * addVertex : 
  * addEdge :
  * print :
  * printBFS :

#### (c)  How could the code be improved in terms of usability, efficiency, and robustness?
  I wish I had caught myself earlier on in my BFS implementation with my mess of .find() function calls and operator[] calls and stuck to one or the other (I would rather have operator []). I also could clean some of these functions if statements checking if the function was called on valid data.
