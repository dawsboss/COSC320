### Grant Dawson

# Heap Sort and Appications

NOTE: To test the prints they are in the buildHeap function and are just commented out
NOTE: These files are also setup to make there own text file (you pick the name in main in init) and will put all results to these files

##### (a)  Summarize your approach to the problem, and how your code addresses the abstractions needed.
* This program has 4 main functions. 2 of these main functions are designed to only build a max heap.
* MaxHeapify - makes sure everything from the given node and it's children follow the rules of max heap in that the array is set up as it was a tree.
So it takes the heap and a given index of where to start and it makes sure that the parent and left/right are in correct order and if it fixes makes sure it
didn't mess up any other parent children relationships.
* BuildHeap - calls heapify and slowly builds a max heap out of the given heap by starting at the top layer of the heap and slowly goes down to the bottom (Until it is working on leaves as the parent) calling Heapify making the largest number be the root essentially.
* HeapSort - calls for the Heap to be built into a maxHeap. Then takes the root and smallest value and switches them and the size of the array that needs to be sorted by one and then calls maxHeapify so that we get the new biggest value back to the root and makes sure the rest of the heap gets fixed.
* printHeap - This will print a heap in the pyrimid form that the functions imagine it as and not the array that it is held in. it is given a starting index and starting depth for it to stat printing from and prints the rest of the tree as if the start is/was the root.
* Use - To use this/modify there are two points to edit. One is the array named "size", this holds the sizes of arrays that will be tested. Second is the
      variable named "sizes" which holds the number of elements in size/this tells the for loops how many times to run.



#### (b)  What is the theoretical time complexity of your sorting algorithm (best and worst case), in terms of the array size?
Best and worst case: O(n*log(n)), n-array size
#### (c)  Test your sorting algorithm on different size and types of arrays, as you did with labs 1 and 2.Be sure to vary the parameters enough to use the observations to answer the next questions!
#### (d)  How does the absolute timing scale with the number of elements in the array?  The size of the elements?
Use the data collected to rectify this with the theoretical time complexity, e.g.  what n on-asymptotic function of n mostly closely matches the timings that you observe as n grows?
    To visulize the relation between the times and swaps vs the number of elements in the array, I made an extra graph with the swap and time graphs that
      shows the relation to their big O counter part and that the times and the amount of swpas and the time it takes are related to the number of
      elements by n*log2(n). With that we can look at the graphs and see how close they are and how they hold the same shape as one another (n*log2(n) vs time and swaps graphs)


#### (e)  Aggregate your data into a graph of the complexity for the various array sizes, for example with a spreadsheet program like LibreOffice Calc or Microsoft Word.
##### (f)  How does the sort perform in different cases?  What is the best and worst case, according to your own test results?
The sorts preformed primially very similar no matter what case was given but I did notice that the decending arrays had less swaps done in them apposed to Accending and deccending arrays.

##### (g)  How could the code be improved in terms of usability, efficiency, and robustness?
This is an extremely efficient and well thought out design but I can't help but feel that there could be a better method than switching one of the smallest elements in the array with the biggest. But all around this as efficient or more efficient as the previous sorts.
