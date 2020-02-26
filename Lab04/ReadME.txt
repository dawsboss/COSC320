(a)  Summarize your approach to the problem, and how your code addresses the abstractions needed for matrix arithmetic.
  My code makes sure the operations done on the matrixies (addition, subtraction, or multiplication) are legal. In that if the two matrixies do not have the same number of rows/coumns they won't do anything ad return an error. The mutiplication also has a check but it doesn't need the same specifications the multiplication need that the first matrix's number of columns is equal to the seconds number of rows. My approach is to just throw back an error message which should be caught
(b)  Analyze your benchmark observations:  what does the timing suggest for the time complexity of addition, subtraction, and multiplication for two n×n matrices?

(c)  What is the arithmetic time complexity of your implementation of each operation, when done on two n×n matrices?  Give tight asymptotic bounds.
  
(d)  How could the code be improved in terms of usability, efficiency, and robustness?
  The code could be modified to be better only in regards to the matrix multiplication in that it is very inefficient with 3 for loops. Other than that the +/- operations are quiet efficient.
