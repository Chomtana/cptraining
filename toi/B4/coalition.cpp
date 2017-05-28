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
    int n; cin>>n;
    int data[n];
    int datasort[n];
    int need = 0;
    for1(i,0,n) {
        scanf("%d",data+i);
        datasort[i] = data[i];
        need += data[i];
    }
    need/=2;
    sort(datasort,datasort+n,greater<int>());
    /*for1(i,0,n) {
        cerr<<datasort[i]<<' ';
    }
    cerr<<endl;*/
    int qs[n];
    qs[0] = datasort[0];
    for1(i,1,n) qs[i]=qs[i-1]+datasort[i];
    for1(i,0,n) {
        //printf("%d\n",upper_bound(qs,qs+n,need-data[i])-qs+1);
        // fail because need to exclude running item

        int si = lower_bound(datasort,datasort+n,data[i],greater<int>())-datasort;

        //cerr<<data[i]<<' '<<si<<endl;

        int res = 1E9;

        int l=0,r=n-1;
        while (l<=r) {
            int mid = (l+r)/2;
            int cal = qs[mid];
            if (mid>=si) {
                cal -= data[i];
            }

            if (data[i]+cal>need) {
                if (mid>=si) {
                    res = min(res,mid-1);
                } else {
                    res = min(res,mid);
                }
            }

            if (data[i]+cal>need) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        printf("%d\n",res+1);
    }
	return 0;
}
