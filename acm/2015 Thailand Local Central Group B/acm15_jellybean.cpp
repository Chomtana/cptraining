#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; while(t--) {
        int num,n; scanf("%d %d",&num,&n);
        priority_queue<int> data;
        for1(i,0,n) {
            int r,c; scanf("%d %d",&r,&c);
            data.push(r*c);
        }

        int sum = 0;
        int res = 0;
        while (sum<num) {
            sum += data.top();
            res++;
            data.pop();
        }
        printf("%d\n",res);
    }
	return 0;
}
