#include <iostream>
#include <stdio.h>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <utility>

#define for1(a,b,c) for(int  (a)=(b);(a)<(c);(a)++)

using namespace std;

typedef pair<int,int> pii;

class Hasher {
	public:
	size_t operator () (const pii &a) const {
		return a.first;
	}
};

int main() {
	int t = 5;
	while(t--) {
		int n; scanf("%d",&n);
		unordered_set<pii,Hasher> upE(1e5);
		for1(i,0,n-1) {
			pii x; scanf("%d %d",&x.first,&x.second);
			pii y(x.second,x.first);
			upE.insert(x);
			upE.insert(y);
			//cout<<x.first<< ' '<<x.second<<' '<<y.first<<' '<<y.second<<endl;
		}
		//cout<<"fuck";
		bool res=true;
		for1(i,0,n-1) {
			pii x; scanf("%d %d",&x.first,&x.second);
			if (upE.count(x)==0) {
				res = false;
			}
		}

		if (res) printf("Y"); else printf("N");

	}

	return 0;
}

/*
9
2 4 9 4 6 4 1 4 1 5 3 5 7 5 7 8
1 4 4 9 1 5 6 4 3 5 7 5 7 8 2 4
9
2 4 9 4 6 4 1 4 1 5 3 5 7 5 7 8
1 4 9 4 1 5 2 4 6 4 3 5 7 5 7 8
9
2 4 6 4 1 4 1 5 9 4 3 5 7 5 7 8
1 4 9 4 1 5 2 4 6 4 3 5 7 5 7 8
9
9 4 3 5 7 5 7 8 2 4 6 4 1 4 1 5
1 4 9 4 1 5 2 4 6 4 3 5 7 5 7 8
4
1 2 2 3 3 4
1 2 1 3 1 4
*/
