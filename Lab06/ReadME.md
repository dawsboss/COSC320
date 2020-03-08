### Grant Dawson

# Lab05 : Priority Queue

### In this lab you will focus on the following objectives:
*  Experiment with randomized versions of standard algorithms
*  Develop experience with statistical data gathering and interpretation

## Questions:

####(a)  Summarize your approach to the problem, and how your code addresses the abstractions needed.

####(b)  What is the theoretical time complexity of your algorithms (best and worst case), in terms of the input size?  Be sure to vary the parameters enough to use the observations to answer the next questions!
* 1.  For example, if your algorithm takes time T(n) =n2, and you double the input (e.g.  1000 to2000), is the time now T(2000) = 20002= 22∗10002= 22∗T(1000) =T(2∗1000) ?
* 2.  Consider this mode of thought for other complexity classes:  How much longer should it take to double the input?  Does your experiment reflect this?  If not, what could be the reasons that change the performance in practice?
* 3.  Which algorithms are most/least impacted by the initial ordering of the array?  Why or why not?

####(c)  How does the absolute timing of different algorithms scale with the input?  Use the data collected to rectify this with the theoretical time complexity, e.g.  what non-asymptotic function ofnmostlyclosely matches the timings that you observe as n grows?
* 1.  Does the average number of assistants hired look close to the theoretical expectation?
* 2.  For quicksort, does the number of swaps look like the expectation proved in class?

####(d)  What, roughly, should the worst case running time look like (in seconds)?  Estimate this from yourobserved time (e.g.  after counting comparisons/swaps, calculate the time per swap and consider if there were the worst case number of swaps).  Do the algorithms ever come close to incurring this worst case cost?

####(e)  Use  Mathematica  or  another  program  to  plot  your  average  timing  data  as  a  function  of  array size.  Then try to find a function that smoothly approximates your data (e.g.  some constant times nlogn).
####(f)  Can you think of a way to judge the quality of your shuffle routine?  Do you see ways it could be made to have a more random output?(

####g)  How could the code be improved in terms of usability, efficiency, and robustness?
