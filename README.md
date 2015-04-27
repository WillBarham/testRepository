# Barham_CSCI2270_FinalProject

# Project	Summary
This project will implement 7 different sorting algorithms: bubble sort, insertion sort, selection sort, quick sort, heap sort, merge sort, and tree sort. In each of the sorting functions, counters will keep track of the algorithm's efficiency when sorting arrays of numbers. The user will choose the array size and the desired sorting algorithm, and three arrays of that size will be created by the program for sorting. One array will already be sorted, another will be in reverse order, and another will be in random order. The program then runs the chosen sorting method on the three arrays and stores the number of counts associated with each. The program then outputs the gathered data. The sorted arrays will not be printed, but data about the efficiency of the selected algorithm when sorting each array will be printed. Implementing heap sort will allow me to explore a new data structure, a priority queue, and implementing merge sort will give me a chance to see a famous application of recursion invented by John von Neumann.

#How to Run
1. This program is compiled with a makefile. I ran it in my Mac's' terminal, and it will also work in the virtual machine's terminal. As long as you have a terminal that uses UNIX or Linux commands, you should be able to compile and run this program. Therefore, unless you choose to do otherwise, I recommend you use the virtual machine's command line when running this code.
2. Create a folder with the files for this project.
3. In the command line, change to the directory with the program files.
4. Type "make" into the terminal.
5. Then type "./FinalProjectCSCI2270" to run the program.

#Dependencies
I do not know of any dependencies for this program.

#System	Requirements
As I said in "How to Run" you will need a terminal that uses UNIX or Linux commands. The virutal machine will work for this.

#Group Members
    William Barham

#Contributors
    There are no contributors so far.

#Open issues/bugs
The program only accepts number inputs when it requests user input. It will fail if anything else is entered. Additionally, if the user inputs too large an array size, the program may never finish. I have not added an upper bound for the acceptable array size, but it seems that only the sorts that run in nlg(n) time finish in a reasonable amount of time for array sizes of about 1,000,000. I attempted bubble sort with an array size of 1,000,000, and after about 10 minutes, the command still hadn't finished. Therefore, one enhancement my reviewer might make is to add an upper limit for the accepted user input of array size. I would also like my reviewer to check if the counters I have added to each of the sorts effectively measure how the sort scales with size. Also, I have done my best to avoid any memory leaks, but please keep an eye out for them and tell me if you find any. Thank you!
    
