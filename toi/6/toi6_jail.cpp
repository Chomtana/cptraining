#include <list>
#include <iostream>
#include <stdio.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

int main() {
	int n,m; cin>>n>>m;
	list<int> data;
	for1(i,1,n+1) data.push_back(i);
	auto it = data.begin();
	int count = 0;
	while(!data.empty()) {
		for1(i,0,m-1){
			count++;
			++it;
			if (it==data.end()) it=data.begin();
		}
		printf("%d ",*it);
		//count++;
		it=data.erase(it);
		if (it==data.end()) it = data.begin();
		//++it;
	}
	//cout<<count;
	return 0;
}
