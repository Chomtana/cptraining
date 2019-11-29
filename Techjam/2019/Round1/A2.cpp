#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define for3(i,a,b,c) for(int (i)=(a);(i)<(b);(i)+=(c))
#define for4(i,a,b,c) for(int (i)=(a)-1;(i)>=(b);(i)-=(c))
#define debugv1(v) for1(_____,0,v.size()) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv2(v,size) for1(_____,0,size) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv3(v,s,e) for1(_____,s,e) cout<<(v)[_____]<<' '; cout<<endl;
#define debug1(a) cout<<(a)<<endl;
#define debug2(a,b) cout<<(a)<<' '<<(b)<<endl;
#define debug3(a,b,c) cout<<(a)<<' '<<(b)<<' '<<(c)<<endl;
#define debug4(a,b,c,d) cout<<(a)<<' '<<(b)<<' '<<(c)<<' '<<(d)<<endl;
#define debug5(a,b,c,d,e) cout<<(a)<<' '<<(b)<<' '<<(c)<<' '<<(d)<<' '<<(e)<<endl;
#define until(x) while(!x)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n,m;
deque<int> P;
vector<pii> interval;

int main() {
	//ios::sync_with_stdio(false);
	//cout<<fixed;
	cin>>n>>m;

	for1(i,0,n) {
		int x; scanf("%d", &x);
		P.push_back(x);
	}

	sort(all(P));

	for1(i,0,m) {
		int x,t; scanf("%d %d", &x, &t);
		interval.push_back({x-t,x+t});
	}

	sort(all(interval), [](pii a, pii b) {
		if (a.first == b.first) {
			return a.second < b.second;
		}
		return a.first > b.first;
	});

	int res = 0;

	for1(i,0,m) {
		if (P.size() == 0) break;

		auto it = upper_bound(all(P), interval[i].second);
		if (it == P.begin()) {
			continue;
		}
		it--;

		if (*it >= interval[i].first) {
			res++;
			P.erase(it);
		}
	}

	cout<<res;
	return 0;
}

/*
3 5
1
3
5
-6 7
10 6
11 3
-2 2
-4 5
*/