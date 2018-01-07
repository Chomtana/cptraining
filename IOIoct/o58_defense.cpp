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

int n,k;
int data[3005];

int recur(int curr,int last,int last2) {
    int res = 1E9;

    res = min(res,recur(curr+1,last));
    res = min(res,recur(curr+1,curr));
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>k;
    for1(i,0,n) scanf("%d",data+i);
    cout<<recur(0,-1);
	return 0;
}
