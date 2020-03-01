### Grant Dawson

# Lab01
## In this lab you will focus on the following objectives:
* 1. Review dynamic memory and array usage in c++
* 2. Explore empirical tests for program efficiency
* 3. Compare theoretical algorithm analysis with practical implementations of recursive and iterative sorting
algorithms

## Questions:
### (a)  What is the theoretical time complexity of your sorting algorithms (best and worst case), in terms of the array size?
   * MergeSort
          Best: O(n*log(n))    Worst: O(n*log(n))
   * QuickSort
          Best: O(n*log(n))    Worst: O(n^2)
### b)  How does the absolute timing scale with the number of elements in the array?  The size of the elements? Can you use the data collected to rectify this with the theoretical time complexity?
   * QuickSort: .004142 -> .008673    Difference .004531 (s)
                    25,000  -> 50,000 (elements) difference 25,000
          Best:  t(n) = nlog(n) => t(2n) = 2n*log(2n) = 2n(log(n) + log(2)), so if you double the size it will take 2time plus log(2) more time.
          Worst: t(n) = n^2 => t(2n) = (2n^2) = 4*n^2, so if you double the size of the array you will spend 4 times the work to sort it.
   * MergeSort: .022588 -> .0859444 Difference .0633564 (s)
                    25,000  -> 50,000 elements difference 25,000
          t(n) = nlog(n) => t(2n) = 2nlog(2n) -> 2n(log(n) + log(2)), so if you double the size it will take 2time plus log(2) more time.
### (c)  How do the algorithms perform in different cases?  What is the best and worst case, according to your own test results?
   * QuickSort: Worst Case is when the array is already sorted
   * MergeSort: There is no real worst case because no matter what it does the same operations, it just does the same thing/the same number of operations
          no matter the digits in the array

   * QuickSort: Best case occurs when the array given is random
   * MergeSort: There is no real best case because no matter what it does the same operations, it just does the same thing/the same number of operations
           no matter the digits in the array
### d)  Do your observations confirm the difference in the best and worst case for Quicksort?  How does Mergesort handle these cases?
   * QuickSort worst cases come form a presorted array because it doesn't move the pivot(which is the right most index) which means that the array doesn't
          split. the best case occurs when the array is randomly sorted because the pivot is more randomized making for the p to be moved around more. This
          makes for more splitting and more work separated.
### (e)  How do these algorithms compare to your implementation of Bubble sort from Lab 1?
   * Quick sort is extremely similar to bubble sort in that it moves the pivot/the element of the array it is looking at to the correct place. Quick sort
          will move it to it's correct place, while bubble sort will put them in there spot but the biggest to the back.
   * Merge Sort: I relate this to more of selection sort in that it goes through all the elements no matter what. It also relates better to selection
          because it has the same big O matter what.

### (f)  How could the code be improved in terms of usability, efficiency, and robustness?
   * The Merge Sort is pretty optimal, the main form of optimization will come form the merge function.
   * The Quick Sort could be better if the pivot was chosen randomly and generally close too the center (at least 3 away from the end or start of the array)
