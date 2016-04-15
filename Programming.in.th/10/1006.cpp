#include <stdio.h>
#include <iostream>

using namespace std;

void rotate(int* result,char dir) {
	int resultold[7] = {*(result),*(result+1),*(result+2),*(result+3),*(result+4),*(result+5)};
	switch (dir) {
		case 'F':
			*(result) = resultold[3];
			*(result+1) = resultold[0];
			//*(result+2) = resultold[3];
			*(result+3) = resultold[5];
			//*(result+4) = resultold[3];
			*(result+5) = resultold[1];
			break;
		case 'B':
			*(result) = resultold[1];
			*(result+1) = resultold[5];
			//*(result+2) = resultold[3];
			*(result+3) = resultold[0];
			//*(result+4) = resultold[3];
			*(result+5) = resultold[3];
			break;
		case 'L':
			*(result) = resultold[4];
			//*(result+1) = resultold[3];
			*(result+2) = resultold[0];
			//*(result+3) = resultold[3];
			*(result+4) = resultold[5];
			*(result+5) = resultold[2];
			break;
		case 'R':
			*(result) = resultold[2];
			//*(result+1) = resultold[3];
			*(result+2) = resultold[5];
			//*(result+3) = resultold[3];
			*(result+4) = resultold[0];
			*(result+5) = resultold[4];
			break;
		case 'C':
			//*(result) = resultold[3];
			*(result+1) = resultold[4];
			*(result+2) = resultold[1];
			*(result+3) = resultold[2];
			*(result+4) = resultold[3];
			//*(result+5) = resultold[3];
			break;
		case 'D':
			//*(result) = resultold[3];
			*(result+1) = resultold[2];
			*(result+2) = resultold[3];
			*(result+3) = resultold[4];
			*(result+4) = resultold[1];
			//*(result+5) = resultold[3];
			break;
	}
}

int main() {
	int n; cin >> n;
	for (int i = 0;i<n;i++) {
		string in; cin >> in;
		int result[6] = {1,2,3,5,4,6};
		for (int i = 0;i<in.length();i++) {
			rotate(result,in[i]);
		}
		cout << result[1] << " ";
	}
	return 0;
}

