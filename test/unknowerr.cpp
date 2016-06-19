/*
Exit code format
0xC0000xx

xx  error
05  segmentation fault (null pointer)
94  divide by zero (.../0)
FD  stack overflow (endless recursive)
*/

#include <bits/stdc++.h>
#include <cerrno>

using namespace std;

void re() {
    re();
}

int main() {
	//read error from exit code
    //int x = 1/0;
    //re();
    int *p;
    *p = 8;
	return 0;
}
