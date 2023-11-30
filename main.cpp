// Implementation of Banker's Algorithm 
// Kaila Anderson
// Operating Systems
// December 1, 2023

// main.cpp

#include <iostream>
using namespace std;

const int processCount = 5; //amount of processes
const int resourceCount = 3;  //amount of resources

int allocation[processCount][resourceCount] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}}; //allocation matrix

int maxMatrix[processCount][resourceCount] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}}; //max matrix 

int need[processCount][resourceCount]; //for the need matrix 
int available[resourceCount] = {3, 3, 2}; //available resources
bool safe[processCount]; // shows if the process is true(added to the sequence) or false(unsafe for sequence) 
int sequence[processCount]; // holds the overall safe sequence 
bool finished = false; // tells the program whether to iterate through each process again or not 
                      // true if all processes are true, false if there is at least one false process 

int main()
{
    //first, find the need matrix
    //found by subtracting maxMatrix - allocation 

    for(int i = 0; i < processCount; ++i){
        for(int j = 0; j < resourceCount; ++j){
            need[i][j] = maxMatrix[i][j] - allocation[i][j];
        }
    }

    //next, make sure the safe array is initialized to false 
    for(int i = 0; i < processCount; ++i) safe[i] = false;

    int n = 0; //used to iterate through sequence array  
    //while there is a false value in the array, "finished" is false and program executes;
    while(!finished){
        //if need <= available, add available and allocation to get new available, set process to trye, and add process to safe sequence array
        //if need > available, go to next process and set process to false; 
        for(int i = 0; i < processCount; ++i){
            for(int j = 0; j < resourceCount; ++j){
                if(safe[i] == false && need[i][j] <= available[j] && j == resourceCount - 1){ //if process is false and iterated through the whole row and need <= available
                     safe[i] = true; 
                     sequence[n] = i; 
                     ++n; 
                     
                     //generate new available
                     for(int k = 0; k < resourceCount; ++k){
                        available[k] = available[k] + allocation[i][k]; 
                     }
                }

                else if(safe[i] == false && need[i][j] <= available[j] && j != resourceCount -1) continue; //if process is false and need is less than but the row isn't over, continue

                else{ //if process is true go to next process or if need is not less than allocation, continue to next process 
                    j = resourceCount; // exit j loop and continue to next program 
                }
            }    
        }
        //check if everything is finished
        finished = true; 
        for(int m = 0; m < processCount; ++m){
            if(safe[m] == false)
            finished = false; 
        } //change finish to false if any process is F and continue the while loop 
    }

    //once everything is finished, output result
    cout << "Safety Sequence: ";
    for(int i = 0; i < processCount; ++i)
    cout << "p" << sequence[i] << " "; 

    cout << endl;
}