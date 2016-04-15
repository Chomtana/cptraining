#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
    int l,n;
    cin >> l;
    cin >> n;
    bool end = false;
    char before[l];
	//string result;
    for (int i = 0;i<n;i++) {
        char in[l];
		scanf("%s",in);
		int found = 0;
		if (i > 0 && !end) {
			for (int i2 = 0;i2<l;i2++) {
				//cout << i2 << endl;
				//cout << before[i2] << " " << in[i2] << endl;
				if (before[i2] != in[i2]) {
					//cout << "aaa" << endl;
					found++;
				}
			}
			if (found > 2) {
				cout << before;
				end = true;
			}
			//cout << before << endl;
		}
		strcpy(before,in);
		
    }
    if (!end) {
    	cout << before;
    }
    return 0;
}

