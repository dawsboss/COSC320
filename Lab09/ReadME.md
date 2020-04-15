### Grant Dawson

# Lab09 : Read Black Tree

### In this lab you will focus on the following objectives:
*  Review basic binary tree data structure and operations
*  Develop familiarity with Red-black trees, and augmenting existing data structures
## Questions:

#### (a)  Summarize your approach to the problem, and how your code addresses the abstractions needed.
  I initially started with my code form lab08 that worked don Binary Trees. Most code could be coppied over expect for the delete and a slight change to insert. Then i added two new functions to fix the tree after inserting and after deleting. These make sure that the tree's node stay in the laws of Red Black trees.
#### (b)  What is the theoretical time complexity of your algorithms (best and worst case), in terms of the size of the tree?  Be sure to vary the parameters enough to use the observations to answer the next questions!
Insertion - O(2h) - h's best and worst case for RB trees is O(log(n)) and O(2log(n+1)) = O(log(n)) so they are within a constant of one another but the big O of insert is O(log(n))

Deletion - O(3h) - h's best and worst cases for RB trees are O(log(n)) and O(2log(n+1)) = O(log(n)) so they are a within a constant of each other but the big O of delete is O(log(n))
#### (c)  Use timing tools to study the cost of each of the data structure algorithms.  Does the data align with the theoretical guarantees?

#### (d)  How could the code be improved in terms of usability, efficiency, and robustness?
  I would have liked to make this more of a working class, instead of a outer shell that does it's job but could be used universally if it had some simple templating.
