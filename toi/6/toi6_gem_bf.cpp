#include <iostream>
#include <vector>
#include <stdio.h>
#include <utility>
#include <algorithm>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

typedef pair<int,int> pii;

vector<pii> need;
vector<int> banmaster;
vector<int> btarg;
vector<int> ban;
bool res= false;
int n,m;

bool findban(int x) {
	return find(ban.begin(),ban.end(),x)!=ban.end();
}

bool bt(int curri) {
//cout<<curri<<endl;
	//first
	if (!findban(need[curri].first)){
		if (curri==n-1) return true;
		btarg[curri] = need[curri].first;
		//cout<<need[curri].first;
		ban[curri] = banmaster[need[curri].first];
		if(bt(curri+1)) return true;
	}

	//second
	if (!findban(need[curri].second)){
		if (curri==n-1) return true;
		btarg[curri] = need[curri].second;
		ban[curri] = banmaster[need[curri].second];
		if(bt(curri+1)) return true;
	}

	return false;
}

int main() {
	int t=5;
	while(t--) {
		scanf("%d %d",&n,&m);

		need.resize(1000001);
		banmaster.resize(1000001);
		btarg.resize(1000001);
		ban.resize(1000001);

		for1(i,0,n) scanf("%d %d",&need[i].first,&need[i].second);
		for1(i,0,m/2) {
			int a,b; //cin>>a>>b;
			scanf("%d %d",&a,&b);
			banmaster[a] = b;
			banmaster[b] = a;
		}
		//printf("aaa");
		if (bt(0)) printf("Y"); else printf("N");

		need.clear();
		banmaster.clear();
		btarg.clear();
		ban.clear();
		res=false;
	}
	return 0;
}

/*
4
6
2 3 6 5 3 4 1 2
1 3 2 5 4 6
3
4
1 2 2 3 4 3
1 3 2 4
4
8
1 2 3 4 5 6 7 8
1 3 2 4 5 7 6 8
3
4
1 2 2 3 3 4
2 3 1 4
5
4
1 2 2 3 4 3 1 3 4 2
1 4 2 3
*/
