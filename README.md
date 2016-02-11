Lab 3: getbits
This is lab #3 in the Spring 2016 course at UNM, CS241.

Section 2.9 of Kernighan and Ritchie provides the getbits function. Write a C
program that reads records from the standard input stream, passes the data in
each valid record to getbits and displays the result.

For this program, a record is a sequence of comma delimited numeric characters
terminated with a newline. A valid record has the form: x,p,n where x, p, and n
correspond to the x, p, and n in getbits and where each of these values is
within the range usable by getbits on a machine (such as moons.cs.unm.edu),
where an unsigned int is 4 bytes.

For each valid input record, you will print a line with the arguments to and
the result from calling getbits. For each error record, output an error message.
There will be sample input and output files for testing on the course web site.
