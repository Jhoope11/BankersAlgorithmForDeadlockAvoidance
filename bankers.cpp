//Banker's Algorithm Lab
//Jack Hooper
#include <iostream>
using namespace std;

int main(){
	int numOfPro, numOfRes, i, j, k;//i,j, and k are all used in loops. numOfPro = number of processes, and numOfRes = Number of Resources 
	numOfPro = 5;
	numOfRes = 3;
	int alloc[5][3] = {{0,1,0}, //P0 Allocation Matrix
			   {2,0,0}, //P1
			   {3,0,2}, //P2
			   {2,1,1}, //P3
			   {0,0,2}};//P4
	int max[5][3] 	= {{7,5,3}, //P0 Max Matrix
			   {3,2,2}, //P1
			   {9,0,2}, //P2
			   {2,2,2}, //P3
			   {4,3,3}};//P4
	int avail[3] = {3,3,2}; // Available Resources

	int f[n],ans[n], ind = 0;
	

