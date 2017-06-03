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

int data[1000005];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	//int n; cin>>n;
	int n;
	
	vector<int> getter;
	vector<int> getteri; //index of getter[i] in data
	vector<int> prev(n); //previous element of index i in data
	
	int i = 0;
	while (scanf("%d",&n)!=EOF) {
		auto it = lower_bound(all(getter),n);
		if (it==getter.end()) {
			getter.push_back(n);
			prev[i] = getteri.back();
			getteri.push_back(i);
			
		} else {
			int x = it-getter.begin();
			*it = n;
			getteri[x] = i;
			if (x-1<0) {
				prev[i] = -1;
			} else {
				prev[i] = getteri[x-1];
			}
		}
		data[i] = n;
		i++;
	}
	
	printf("%d\n-\n",int(getter.size()));
	return 0;
}
