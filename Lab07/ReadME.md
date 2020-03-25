### Grant Dawson

# Lab07 : Hash basics

### In this lab you will focus on the following objectives:
*  Practice implementing and studying hash functionss
*  Develop familiarity with list-concepts and memory management inc++
## Questions:

#### (a)  Summarize your approach to the problem, and how your code addresses the abstractions needed. / (b)  Explain your string conversion functions, and compare how they distribute the hashes of various strings.

    We had 3 Hashing functions we were asked to code:
    * The first of the three was one that the general idea and sudo code were given for. Here I took what was goven to us and made it in my own way (Diffrent prime numbers). The next two hashing functions were up to us to make, the only restaint was that these two should hash a string.

    * For my first self made hash function and my second hash function overall I turned each character into it's ascii's value/an integer and added them all up, at the end I took the mod(%) of the total sum by a prime number.

    * The last hash and my second string hashing function I had the same setup to where it would addd all the letters ascii values up but this time I would add the same prime number to each characters value.

#### (c)  How could the code be improved in terms of usability, efficiency, and robustness

    I could have made the string hashing functions more complex and relient on it's self to come up with obsered numbers. This in my case doesn;pt lookse me anyhting but in the real worldf my code is "very easy" to crack. I also would have made it so that my other hasing function used shifting operators as mentioned in the labs PDF.

#### (d)  Why does the number hasing function make sense?
    The first hashing algorithm make sence because it takes the original number and modifies it based on prime numbers. It doesn't make it any random number or use any random numbers to modify it. It uses set in stone or calculatable prime numbers from the given number (to be hashed). This specific function uses 2 prime numbers, a given number, and the size of the current machines word size (Mine is hard coded because most machines are 64 bit). meaning all my modifying numbers are "hard coded" some are used in diffrent ways but the numbers themselves are hard coded. 
