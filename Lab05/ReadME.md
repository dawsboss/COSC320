### Grant Dawson

# Lab05 : Priority Queue

### In this lab you will focus on the following objectives:
*  Use the heap data structure to implement a priority queue.
*  Review implementations of heaps and binary trees in c++.

## Questions:

#### (a)  Summarize your approach to the problem, and how your code addresses the abstractions needed.
This Lab is extremely similar to our Lab03. The key/main difference is that this is templated and that we are working with an array of structs. The was that I setup this lab allows for an easy addition of Heap Sort (either by the keys or data). I attacked the problem by figuring out for my algorithms I can ignore the data and I would only be checking keys of the data versus one another.
#### (b)  What is the theoretical time complexity of your algorithms (best and worst case), in terms of the input size?  Be sure to vary the parameters enough to use the observations to answer the next questions!
* IncreaseKey - Worst case: O(log(n)) The worst case comes from if the element being increased will be the heap array's new greatest value.
                Best case:  O(c) The best case comes from when the element being increased will be the smallest value in the whole heap array.
* MaxHeapify -  Worst case: O(log(n)) The worst cases from if the algorithm has to max heapify with the smallest element in the heap at the top
                Best case:  O(c) There is no need to swap and everything is already max heaped (bigger elements on top of smaller)
* Print -       O(n) this runs through the whole array and prints out everything
* ExtractMax, Insert, ExpandArray, and Peek - all do the a constant amount of work. They all do a constant amount of work and then call other functions that have the potential of running long (if that).
#### (c)  How does the absolute timing of different algorithms scale with the input?  Use the data collected to rectify this with the theoretical time complexity, e.g.  what non-asymptotic function of n mostly closely matches the timings that you observe as n grows?
The absolute timing will scale with the number of elements plus a constant. No matter what size the array is there are some functions that just do a constant amount of work/it does not rely on n to do the work. While other functions will rely on n (print, MaxHeapify, IncreaseKey) so Although it is scaling with n it is not equal to n.  
#### (d)  Describe 2-3 different larger application areas where a priority queue would be helpful.  Explain and give some justification why it would be a better choice than other data structures.
* To do lists - This gives you your most important item on your list first where you can peek to see it and then when you are done extract it to put it on your completed list.
* List of most popularity between *objs* (movie, song, ect.) - This can allow for companies to see which song/movies/ect has the most likes or views (every view/like adds one ot the priority) which this can give a lot of meta data about their website/artists/their customers.
* Ticketing system - IT help desk/Food ordering - Makes a moving list that a IT help desk could use in that if something comes in that needs to be done now it can be moved right up the list.
#### (e)  How could the code be improved in terms of usability, efficiency, and robustness?
I would like to make this system more user friendly in the sense that it could have a user interface but as a class to use this class is very general and open to any application, especially with the fact it is templated for any data type and the data type does not need to have any overloaded operators than just operaoter=.
