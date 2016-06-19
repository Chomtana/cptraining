#include <bits/stdc++.h>
#include <csignal>
#include <string.h>

using namespace std;

void handler(int a) {
    cout << "Signal " << a << " here!" << endl;
}

void re() {
	re();
}

int main() {
	signal(1,handler);
	signal(2,handler);
	signal(3,handler);
	signal(4,handler);
	signal(5,handler);
	signal(6,handler);
	signal(7,handler);
	signal(8,handler);
	signal(9,handler);
	signal(10,handler);
	signal(11,handler);
	signal(12,handler);
	signal(13,handler);
	signal(14,handler);
	signal(15,handler);
	signal(16,handler);
	signal(17,handler);
	signal(18,handler);
	signal(19,handler);
	signal(20,handler);
	signal(21,handler);
	signal(22,handler);
	signal(23,handler);
	signal(24,handler);
	signal(25,handler);
	signal(26,handler);
	signal(27,handler);
	signal(28,handler);
	signal(29,handler);
	signal(30,handler);
	signal(31,handler);
	int x = 1/0;
	re();
	cout<<"aaa";
	return 0;
}
