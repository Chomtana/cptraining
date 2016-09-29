#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int h,w; cin>>h>>w; //matrix dimension row x col = h x w (*ultimate very hard to find error)
	ll data1[h][w];
	ll data2[h][w];
	for (int i = 0;i<h;i++) {
		for(int j = 0;j<w;j++) {
			cin>>data1[i][j];
		}
	}
	for (int i = 0;i<h;i++) {
		for(int j = 0;j<w;j++) {
			cin>>data2[i][j];
		}
	}
	for (int i = 0;i<h;i++) {
		for(int j = 0;j<w;j++) {
			cout<<data1[i][j]+data2[i][j]<<' ';
		}
		cout<<endl;
	}
    return 0;
}
