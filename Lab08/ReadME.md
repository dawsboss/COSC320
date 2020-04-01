### Grant Dawson

# Lab08 : Binary Search Tree

### In this lab you will focus on the following objectives:
*  Review basic binary tree data structure and operations
*  Develop familiarity with list-concepts and memory management in c++
## Questions:

#### (a)  Summarize your approach to the problem, and how your code addresses the abstractions needed.
  I started with the base struct that is for the BinaryTree class. Where one node has a parent, left child, right child, and it's data. Then I proceeded to make functions that allowed me to modify and edit these nodes once in the Tree configuration without interfering with the trees laws.
#### (b)  What is the theoretical time complexity of your algorithms (best and worst case), in terms of the size of the tree?  Be sure to vary the parameters enough to use the observations to answer the next questions!
  * Insert: Worst - O(n) - n being the number of elements - this comes from when the biggest node is inserted the following nodes continue to deccending or the inverse (i.e. the tree is a one straight branch)
            Best - O(1) - The new node is the first and will take the spot of the root.
  * Remove: Worst - O(n) - n being the number of elements - this case comes from when the node that is desired to be removed/deleted is not even in the list
            Best - O(h) - h being the height of the total tree. Although to find what we will be deleting is O(1) we need to find the successor which is O(h) and finds the next largest number so at most we would have to go down one branch so the height.
  * Search: Worst - O(n) - n being the number of elements - this case comes from when the node that is being searched for is not even in the list
            Best - O(1) - This is when the desired node is the root and we have to only check one node
#### (c)  Use timing tools to study the cost of each of the data structure algorithms.  For example, time how long it takes to insert, find, delete 1000, 2000, 3000, etc.  elements and calculate the time per operation.  Look for how the time scales with the size of the tree.  Does the data align with the theoretical guarantees?
 * NOTE: These times were from 10 tests and left as ten test so we had bigger numbers to work with
Yes because the data grows way slower than the O(n) as expected as max. None are constant but they get close. although the insert may look wrong it just means that it took a but more work to insert the number than it did for the program to search/delete it. 

#### (d)  How could the code be improved in terms of usability, efficiency, and robustness?
This could be improved by doing more than just 3 required sizes of trees so I had some more data to actually make a graph of the data. Other than that there is not much to add, the times were so fast for 1k, 2k, 3k that I could just use bigger numbers so i didn't have to add 10 trials together to get a use-able number.
