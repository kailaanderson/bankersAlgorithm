# bankersAlgorithm

This code implementation evaluates the banker's algorithm and determines a safety sequence based on the data.
The code can be compiled and executed with these commands:

g++ main.cpp -o output
./output

Conclusion:
The system is in a safe state and the sequence is: p1, p3, p4, p0, p2

Variables and Starting Values: 

The initial values of the allocation, max, and available arrays are based on this table:
Constant integers "processCount" and "resourceCount" were declared and initialized to represent the number of processes and resources available. There are 5 processes and 3 resources. These variables are used in 2D array declaration as well.
The int array "Need" is declared to hold the need matrix.
Boolean array "safe" was implemented to keep track of which processes are already counted in the safety sequence. When a process's need array is less than or equal to the available array, it's spot in the safe array is set to true. Otherwise, it is false. 
The last array "sequence" holds the process number once it is declared safe. 
Boolean "finished" was added in order to keep track of whether or not each process was added to the safety sequence. If any value in the safe array is false, finish is set to false and the code under the while loop is executed again. Otherwise, finished is set to true and the safety sequence is outputted. 


Main():

The first step in the Banker's algorithm is to find the need matrix. This is found by iterating through the max and allocation arrays, subtracting max - allocation. 

The next step is to compare the need array with the available array. 
If each value of need <= available and the process is not already stored in the safe array the program will add each individual value of the allocation array to the available array to produce the new available values.
However, if any value in the process' need array is greater than the value in the available array, the safe index for that process is set to false and the program continues to the next process. 
Variable "n" is used to keep track of the index for the sequence array. It starts at zero and once a process is added, the value is incremented. 
Once the comparison is complete for all processes, the program has to check if all processes are set to true. If there is a process that is false, finish is set to false and the code under the while loop executes again. If there are no false processes, finish remains true and the program exits the while loop. 

Once the while loop is complete, the safety sequence is sent to the console as output. 
