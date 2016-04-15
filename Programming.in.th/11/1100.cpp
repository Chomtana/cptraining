#include <iostream>

using namespace std;

long long int commutationr2 (long long int n) {
	return (n*(n-1))/2;
}

int main() {
	long long int onedigit[3][10] = {0};
	long long int twodigit[3][100] = {0};
	long long int threedigit[1000] = {0};
	int n;
	long long int result = 0;
	cin >> n;
	for (int i=0;i<n;i++) {
		int curr;
		cin >> curr;
		int currdigit1 = curr/100;
		int currdigit2 = curr/10%10;
		int currdigit3 = curr%10;
		int currdigit12 = curr/10;
		int currdigit23 = curr%100;
		int currdigit13 = currdigit1*10+currdigit3;
		onedigit[0][currdigit1]++;
		onedigit[1][currdigit2]++;
		onedigit[2][currdigit3]++;
		twodigit[0][currdigit12]++;
		twodigit[1][currdigit23]++;
		twodigit[2][currdigit13]++;
		threedigit[curr]++;
	}
	for (int i = 0;i<10;i++) {
		result += commutationr2(onedigit[0][i]);
		result += commutationr2(onedigit[1][i]);
		result += commutationr2(onedigit[2][i]);
	}
	for (int i = 0;i<100;i++) {
		result -= commutationr2(twodigit[0][i]);
		result -= commutationr2(twodigit[1][i]);
		result -= commutationr2(twodigit[2][i]);
	}
	for (int i = 0;i<1000;i++) {
		result += commutationr2(threedigit[i]);
	}
	cout << result;
	
	return 0;
}

