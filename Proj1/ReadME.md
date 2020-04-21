### Grant Dawson

# Project 1 : "Input-Output" model

### In this lab you will focus on the following objectives:

You will implement a recursive algorithm to compute the inverse of a matrix, then apply that solution to the problem of analyzing economical "Input-Output" models.

## How to run this program
#### Project:
To run this program, you will need to first compile the code:

````
make
````

Now that our code is complied and ready to execute we can then call out function on the desired data:

````
./main *file*
````
*file* - This file should be accessable and capable of being oppend by fstream.
    If the file is invalid the program will not execute and will prompt you with an error message.


##### File setup

The file can have as many "problems" in it as you want or you can have each one in individual files.

The file that will be given to the program should be set up like:


Companies
---
Matrix
---
Demand


ex:
	Coal
	Electricity
	Produce
	---
	0.6 0.02 0.1
	0.3 0.2 0.4
	0.2 0.4 0.3
	---
	20
	34
	80
	
#### Driver
To run this program, you will need to first compile the code:

````
make driver
````

Now that our code is complied and ready to execute and test the our functions on an array of sizes of matrixies

````
./driver
````
This prints out the time it took for the functions to run.


## Output

The out put will print:

CompanyName1: # of elements needed to be made
CompanyName2: # of elements needed to be made
	.
	.
	.

	ex:
		Coal:         133.72 units
		Electricity:  236.45 units
		Produce:      287.61 units  

## Analyze Driver

We can see that the subtraction and addition have the same exact amount of operations preformed. Multiplication as expected has more operations, we can expect this because it has to do the job of the adding and also go through the entire Column of one matrix just to do the one element in the first matrix. All times and number of operations are listed when the program is executed. In the driver we test all functions along with a test of the inverse, we only test this once because there is no current implementation of determanent to test if a matrix is invertable.
