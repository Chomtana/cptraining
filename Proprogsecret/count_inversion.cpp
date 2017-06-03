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

int data[500005];
ll res = 0;

void mergesort(int s,int e) { //all include
	int mid = (s+e)/2;
	if (s<e) {
		mergesort(s,mid);
		mergesort(mid+1,e);
	}
	
	vector<int> temp;
	temp.reserve(e-s+5);
	
	int i=s,j=mid+1;
	while (i<=mid&&j<=e) {
		if (data[i]<=data[j]) {
			temp.push_back(data[i]);
			i++;
		} else {
			res += mid-i+1;
			temp.push_back(data[j]);
			j++;
		}
	}
	
	while (i<=mid) {
		temp.push_back(data[i]);
		i++;
	}
	
	while (j<=e) {
		temp.push_back(data[j]);
		j++;
	}
	
	for1(i,0,temp.size()) {
		data[s+i] = temp[i];
	}
	
	
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int n;
	while (scanf("%d",&n),n!=0) {
		for1(i,0,n) scanf("%d",data+i);
		mergesort(0,n-1);
		printf("%lld\n",res);
		res = 0;
	}
	return 0;
}
