// Implementation of Banker's Algorithm 
// Kaila Anderson
// Operating Systems
// December 1, 2023

// main.cpp

const int processCount = 5;
const int resourceCount = 3; 

int allocation[processCount][resourceCount] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};

int max[processCount][resourceCount] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};

int need[processCount][resourceCount];
int available[resourceCount] = {3, 3, 2};
bool safe[processCount];
int sequence[processCount];