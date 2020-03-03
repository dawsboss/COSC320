### Grant Dawson

# Lab05 : Priority Queue

### In this lab you will focus on the following objectives:
*  Use the heap data structure to implement a priority queue.
*  Review implementations of heaps and binary trees in c++.

## Questions:

#### (a)  Summarize your approach to the problem, and how your code addresses the abstractions needed.
This Lab is extremely similar to our Lab03. The key/main difference is that this is templated and that we are working with an array of structs. The was that I setup this lab allows for an easy addition of Heap Sort (either by the keys or data). I attacked the problem by figuring out for my algorithms I can ignore the data and I would only be checking keys of the data versus one another.
#### (b)  What is the theoretical time complexity of your algorithms (best and worst case), in terms of the input size?  Be sure to vary the parameters enough to use the observations to answer the next questions!

#### (c)  How does the absolute timing of different algorithms scale with the input?  Use the data collected to rectify this with the theoretical time complexity, e.g.  what non-asymptotic function of n mostly closely matches the timings that you observe as n grows?

#### (d)  Describe 2-3 different larger application areas where a priority queue would be helpful.  Explain and give some justification why it would be a better choice than other data structures.

#### (e)  How could the code be improved in terms of usability, efficiency, and robustness?
