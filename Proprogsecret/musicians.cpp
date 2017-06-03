#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

int t,n;

pii T[505];
int S[505];
int res[505];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	cin>>t>>n;
	for1(i,0,n) {
		scanf("%d",&T[i].first);
		T[i].second = i;
	}
	sort(T,T+n,greater<pii>());
	if (n==1) {
		cout<<0;
		return 0;
	}
	priority_queue<int,vector<int>,greater<int>> pq;
	S[0] = S[1] = 0;
	pq.push(T[0].first);
	pq.push(T[1].first);
	for1(i,2,n) {
		S[i] = pq.top();
		pq.pop();
		pq.push(S[i]+T[i].first);
	}
	
	for1(i,0,n) {
		res[T[i].second] = S[i];
	}
	
	for1(i,0,n) {
		printf("%d ",res[i]);
		
	}
	
	return 0;
}
