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

int n,w,k;
int H[100005];
int backup[100005];

bool check(int size) {
    int totalrem = 0;
    //use greedy one direction -> next only
    for1(i,0,n) {
        if (H[i]>size) {
            int rem = H[i]-size;
            totalrem += rem;
            if (totalrem>k) {
                return false;
            }
            
            for1(j,0,w) {
                if (i+j>=n) break;
                H[i+j] -= rem;
                if (H[i+j]<0) {
                    H[i+j] = 0;
                }
            }
            
        }
    }
    return true;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    scanf("%d%d%d",&n,&w,&k);
    for1(i,0,n) {
        scanf("%d",H+i);
        backup[i] = H[i];
    }
    
    int l = 0; int r = 1E9;
    while (l<=r) {
        int mid = (l+r)/2;
        for1(i,0,n) H[i] = backup[i];
        //cerr<<mid<<' '<<check(mid)<<endl; //cannot run two time without reset
        for1(i,0,n) H[i] = backup[i];
        if (check(mid)) {
            r = mid-1;
        } else {
            l = mid+1;
        }
        //cerr<<l<<endl;
    }
    cout<<l;
	return 0;
}
