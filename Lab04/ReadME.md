### Grant Dawson

# Lab04 : Matrix class 
Note: This class has overloaded operators for addition, subtraction, and multiplication 

### In this lab you will focus on the following objectives:
*  Design and implement a new, mathematically motivated, data structure.
*  Develop familiarity with matrices and matrix operations.
*  Study the algorithmic problems of matrix algebra both in theory and in practice.

 
 ## Questions: 

#### (a)  Summarize your approach to the problem, and how your code addresses the abstractions needed for matrix arithmetic.
  My code makes sure the operations done on the matrixies (addition, subtraction, or multiplication) are legal. In that if the two matrixies do not have the same number of rows/coumns they won't do anything ad return an error. The mutiplication also has a check but it doesn't need the same specifications the multiplication need that the first matrix's number of columns is equal to the seconds number of rows. My approach is to just throw back an error message which should be caught
#### (b)  Analyze your benchmark observations:  what does the timing suggest for the time complexity of addition, subtraction, and multiplication for two n×n matrices?
  I made a graph to visualize the time complexities. Although I made two seperate graphs for adding/subtracting and multiplication, it was because the multiplication was so much large than addition and subtraction. We also see that the subtraction/addition are on the same line. Multiplication is just so much larger we wouldn't be able to see the other graphs.
    That said the multiplication being n^3 makes sences since the addition and subtraction are n^2 time complexity
#### (c)  What is the arithmetic time complexity of your implementation of each operation, when done on two n×n matrices?  Give tight asymptotic bounds.
  * Multiply - If we analyze the code we can see there are three for loops that each run (if both matrixies are nxn) n times They each do a constant amount of work and they do not rely on one another so the multiply function is big theta of (n^3)
  * Add - If we analyze the code we see that there are two for loops and they both run (if the matixies are nxn) n amount of times and they each do a constant amount of work and do not rely on one another so the addition function is big theta of (n^2)
  * Subtract - Although this is the exact same code as the Addition (other than one + switches to a -) we see that there are two for loops and they each run (if the matrixies are nxn) n times and do not rely on one another so the subtraction function is also big theta of (n^2)
#### (d)  How could the code be improved in terms of usability, efficiency, and robustness?
  The code could be modified to be better only in regards to the matrix multiplication in that it is very inefficient with 3 for loops. Other than that the +/- operations are quiet efficient.
