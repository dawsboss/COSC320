### Grant Dawson

# Lab05 : Priority Queue

### In this lab you will focus on the following objectives:
*  Experiment with randomized versions of standard algorithms
*  Develop experience with statistical data gathering and interpretation

## Questions:

#### (a)  Summarize your approach to the problem, and how your code addresses the abstractions needed.
  My approach to this problem for the lab was to take all my previous code and put it all into one big cpp file that has the capability of running all need sorting algorithms. So I went back to previous labs and extracted all required functions to allow them to run (isSorted, timeSort, QuickSort, MergeSort, BuildMaxHeap, MaxHeapify, HeapSort, ect). My code has some "repeat" functions but that is because not all the sorters use the same paremeters, Merge/Quick/RandQuick all use the same functions (isSorted and timeSort) but all heap functions use a Heap struct and therefore can not use the same functions (timeSort and isSorted).
#### (b)  What is the theoretical time complexity of your algorithms (best and worst case), in terms of the input size?  Be sure to vary the parameters enough to use the observations to answer the next questions!
* 1.  For example, if your algorithm takes time T(n) =n2, and you double the input (e.g.  1000 to2000), is the time now T(2000) = 20002= 22∗10002= 22∗T(1000) =T(2∗1000) ?
* 2.  Consider this mode of thought for other complexity classes:  How much longer should it take to double the input?  Does your experiment reflect this?  If not, what could be the reasons that change the performance in practice?
* 3.  Which algorithms are most/least impacted by the initial ordering of the array?  Why or why not?

    * QuickSort: 3.845135 -> 17.084200    Difference .004531 (s)
                 649,941,344 -> 2,524,132,614 Difference 1,874,191,270 elements
               360,000  -> 710,000 (elements) difference 350,000
     Best:  t(n) = nlog(n) => t(2n) = 2n*log(2n) = 2n(log(n) + log(2)), so if you double the size it will take 2 time plus log(2) more time.
     Worst: t(n) = n^2 => t(2n) = (2n^2) = 4*n^2, so if you double the size of the array you will spend 4 times the work to sort it.
     We can see that we got closer to a worst case seniorio here because the when we doubled the length of the array the time took nearly 4 times as long.

     * RandQuickSort: 3.839361 -> 14.885790    Difference 11.04643 (s)
                      649,850,706 -> 2,524,334,832 Difference 1,874,484,126 elements
                360,000  -> 710,000 (elements) difference 350,000
      Best:  t(n) = nlog(n) => t(2n) = 2n*log(2n) = 2n(log(n) + log(2)), so if you double the size it will take 2 time plus log(2) more time.
      Worst: t(n) = n^2 => t(2n) = (2n^2) = 4*n^2, so if you double the size of the array you will spend 4 times the work to sort it.
      Also We can analyze this along side of the QuickSort and we see that this had a better time. We can say this came from either that the random numbers were nicer for the sorter or more likely that the sorting algorithm with the modified choosing of the piviot helped it's running time.


     * MergeSort: 0.063240 -> 0.128895 Difference .065655 (s)
                  13,351,424 -> 27,722,848 Difference 14,371,424 elements
               360,000  -> 710,000 elements difference 350,000
     t(n) = nlog(n) => t(2n) = 2nlog(2n) -> 2n(log(n) + log(2)), so if you double the size it will take 2 time plus log(2) more time.

     * Heap: 0.214678 -> 0.457201 Difference .242523 (s)
             6,281,085 -> 13,075,653 Difference 6,794,568 elements
               360,000  -> 710,000 elements difference 350,000
     t(n) = nlog(n) => t(2n) = 2nlog(2n) -> 2n(log(n) + log(2)), so if you double the size it will take 2 time plus log(2) more time.

#### (c)  How does the absolute timing of different algorithms scale with the input?  Use the data collected to rectify this with the theoretical time complexity, e.g.  what non-asymptotic function of n mostly closely matches the timings that you observe as n grows?
* 1.  Does the average number of assistants hired look close to the theoretical expectation?
    Yes as we can see from the analysis above.
* 2.  For quicksort, does the number of swaps look like the expectation proved in class?
  See analysis above.
#### (d)  What, roughly, should the worst case running time look like (in seconds)?  Estimate this from your observed time (e.g.  after counting comparisons/swaps, calculate the time per swap and consider if there were the worst case number of swaps).  Do the algorithms ever come close to incurring this worst case cost?
  For the hiring problem: the worst case seems to comes from when the array of cannadates is in accending, This means the the program does the most work/has to most cost because ever single iteration the hired canadate is re-chosen. Which that is bad for the exsample but is all bad for the code because that although doesn't add as much as a interview it adds another operation increasing the time takes by the program (only slightly).
  Not: Data came from 360,00 elements.
  * Merge: Is completed extremely quickly (fastest avgs) and each swap is 13,351,424 (swaps) / 0.063240 (s).
    211,123,086 swaps per second
  * QuickSort: Is completed extremely slowly (tied) and each swap is 649,941,344 (swaps) / 3.845135 (s).
    169,029,525 swaps per second
  * RandQuickSort: Is completed extremely slowly (tied) and each swap is 649,850,706 (swaps) / 3.839361 (s).
    169,260,120 swaps per second
  * Heap: Is completed extremely quickly (second fastest avgs) and each swap is 6,281,085 (swaps) / 0.214678 (s).
    29,258,168 swaps per second

With this we can see that Merge did the most swaps per second but we can also see that HeapSort seemed to be pretty low on the rankings but it was because it had the least amount of swaps/hiring of any of the other sorting algorithms. The worst that would come form Merge or heap would be where they are at because they have a constant big O and will have no shift based on randomness. But Quick sorts will, the randomized limits the big O because it minimize the chance of the worst case ever happening. Both quick sorts got extremely close to their big O's but we are blaming this to a computer error with cashing but we can see at least they do not go over their big expected times.(around .0000000059009 seconds per swap) with this number we can guess that the worst cases for the QuickSorts with big O of n^2 will be around 764 seconds for 360,000 elements (4 * 360,000 * .0000000059009).

#### (e)  Use  Mathematica  or  another  program  to  plot  your  average  timing  data  as  a  function  of  array size.  Then try to find a function that smoothly approximates your data (e.g.  some constant times nlogn).
#### (f)  Can you think of a way to judge the quality of your shuffle routine?  Do you see ways it could be made to have a more random output?
  I like to think of the effectiveness in regards to doing the same algorithm to a deck of cards. The shuffle could be better for the same reason people don;t shuffle the deck of cards once. If you run the shuffle several times then it will be even more shuffled.
#### (g)  How could the code be improved in terms of usability, efficiency, and robustness?
  I would have liked to put each of the sorting algorithms in their own class but time did not permit. I also would have liked to have them read out straight to a docs sheet so I did not have to copy and paste my data into one for graphing.
#### (Extra Credit) Analysis of the Priority queue shuffling
  We have to think of the probibility that the shuffle won't work and we will end up with the array be given to the function caller pre-sorted. If we have n elements and the shuffle runs through a loop giving them a rand priotity between 1 and n^3. So for each n there are 1/n^3 total possibilities for that priority. And for the array to get priorities making it pre-sorted is extremely low, and in fact can be calculated using permutations. P = n!/(n-r)!, which is the general equationg but for us it is (n^3)! / (n^3-n)! total permutations. and only one of those is a perefectly accending array. so the probability is 1 / (total permutations).
