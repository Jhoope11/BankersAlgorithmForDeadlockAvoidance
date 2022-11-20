//Banker's Algorithm Lab
//Jack Hooper


int main() {
	const int numOfProConst = 5;
	const int numOfResConst = 3;
	int numOfPro, numOfRes, i, j, k;//i,j, and k are all used in loops. numOfPro = number of processes, and numOfRes = Number of Resources 
	numOfPro = 5;
	numOfRes = 3;
	int alloc[5][3] = { {0,1,0}, //P0 Allocation Matrix
					   {2,0,0}, //P1
					   {3,0,2}, //P2
					   {2,1,1}, //P3
					   {0,0,2} };//P4
	int max[5][3] = { {7,5,3}, //P0 Max Matrix
					   {3,2,2}, //P1
					   {9,0,2}, //P2
					   {2,2,2}, //P3
					   {4,3,3} };//P4
	int avail[3] = { 3,3,2 }; // Available Resources

	int f[numOfProConst], ans[numOfProConst], ind = 0;
	for (k = 0; k < numOfPro; k++) { f[k] = 0; }
	int need[numOfProConst][numOfResConst];
	for (i = 0; i < numOfPro; i++) {
		for (j = 0; i < numOfRes; j++) {
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	int y = 0;
	for (k = 0; k < 5; k++) {
		for (i = 0; i < numOfPro; i++) {
			if (f[i] == 0) {
				int flag = 0;
				for (j = 0; j < numOfRes; j++) {
					if (need[i][j] > avail[j]) {
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < numOfRes; y++) {
						avail[y] += alloc[i][y];
					}
					f[i] = i;
				}
			}
		}
	}
	int flag = 1;

	//Checks if sequence is safe
	for (int i = 0; i < numOfPro; i++) {
		if (f[i] == 0) {
			flag = 0;
			printf("The given sequence is not safe");
			break;
		}
	}
	if (flag == 1) {
		printf("Following is the Safe sequence\n");
		for (i = 0; i < numOfPro - 1; i++) {
			printf(" P" + ans[i] + "=");
			printf(" P" + ans[numOfPro - 1] + "\n");
		}
		return(0);
	}
}
