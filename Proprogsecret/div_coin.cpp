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

int data[105];
int getter[1000000]; //don't know how much sum -> make it big enough

int knapsack(int bound,int size) {
	//use special algorithm
	for1(i,0,size+5) getter[i] = 0;
	for1(i,0,bound+1) {
		for2(j,size,0) {
			int x = j+data[i];
			if (x<=size) {
				getter[x] = max(getter[x],getter[x-data[i]]+data[i]);
			}
		}
	}
	return getter[size];
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int t; cin>>t;
	while (t--) {
		int n; scanf("%d",&n);
		int sum = 0;
		
		for1(i,0,n) {
			scanf("%d",data+i);
			sum += data[i];
		}
		
		//find value that near sum/2 <= , choose in any pattern (1,5,3,8,16 is ok)
		int first = knapsack(n-1,sum/2); //knapsack w=v=data
		//cerr<<"DBG "<<first<<endl;
		int second = sum-first;
		printf("%d\n",second-first);
		
	}
	return 0;
}
