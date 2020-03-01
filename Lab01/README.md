### Grant Dawson

# Lab01 : Bubble/Insertion/Selection Sorts and Applications
### In this lab you will focus on the following objectives:
 *  Review dynamic memory and array usage in c++
 *  Explore empirical tests for program efficiency
 *  Compare theoretical algorithm analysis with practical implementations of recursive and iterative sorting algorithms

## Questions:
#### a)  What is the theoretical time complexity of your sorting algorithms (best and worst case), in termsof the array size?
   * BubbleSort -    Worst: n^2
		        Best: n
   * InsertionSort - Worst: n^2
                    Best: n
   * SelectionSort - Worst/Best: n^2

#### (b)  How does the absolute timing scale with the number of elements in the array?  The size of the elements?  Can you use the data collected to rectify this with the theoretical time complexity?
   * BubbleSort -    Worst: n^2 so if you increase n by 2 is will take 4 time as long
		          Best: n if you increase it by 2 then it will run for two times the time
   * InsertionSort - Worst: n^2 if you increase the amount of numbers (2n) then it will take 4 times the amount of time
		          Best: n if you increase the number of elements by 2 (2n) then it will take 2 times the times
   * SelectionSort - Best/Worst: if you increase the number of elements by 2 (2n) then it will take (2n)-1) so it will take two times the time

#### c)  Aggregate your data into a graph of the complexity for the various array sizes, for example witha spreadsheet program like LibreOffice Calc or Microsoft Word.
  Other papper...

#### d)  How do the algorithms perform in different cases?  What is the best and worst case, according toyour own test results?.
  * BubbleSort - Best was the presorted array and the worst was the reverse sorted array
  * InsertionSort - Best was the the presorted array and the worst was the reversed sorted array.
  * SelectionSort - Best and worst were any of them, the sort went through every element minus 1 no matter what and resorted

#### (e)  How could the code be improved in terms of usability, efficiency, and robustness?
  Well the bubble sort was a great exsample of this because there were two possible verssions that we know and could be used easily. The one verssion goes through the array the same amount no 
    matter what. Altough effective it will be extremely ineficient compared to it's counter part. It is also very robust because it is just two for loops slapped to gether to go through the array n^2 times.
    (no matter what). THe other version will go through the array as much as it needs too, this means if it sees that the array is in order and it's last pass didn't swap anything then it says it is all done
    and will go on it's merry way. 




