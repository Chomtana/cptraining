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

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t;
    for1(_,1,t+1) {
        int n; scanf("%d",&n);
        char data[n+10]; scanf("%s",data);
        int res = 0;
        for1(i,0,n) {
            if (data[i]=='.') {
                data[i]='@';
                data[i+1]='@';
                data[i+2]='@';
                res++;
            }
        }

        printf("Case %d: %d\n",_,res);
    }
	return 0;
}
