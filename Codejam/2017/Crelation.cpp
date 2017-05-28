//small case 1 only ; n<=1000 -> O(n^2)

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
	ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; for1(_,1,t+1) {
        int n,k; cin>>n>>k;
        vector<bool> data(n+2,false);
        data[0] = true;
        data[n+1] = true;
        int turn = 0;
        while (k--) {
            turn ++;
            int maxmaxlr = -1;
            int maxminlr = -1;
            int select = -1;
            for1(s,1,n+1) {
                if (data[s]) continue;
                int l=0,r=0;
                for2(j,s-1,0) {
                    if (data[j]) break;
                    l++;
                }
                for1(j,s+1,n+2) {
                    if (data[j]) break;
                    r++;
                }
                //cerr<<s<<' '<<l<<' '<<r<<endl;
                if (min(l,r)>maxminlr) {
                    maxminlr = min(l,r);
                    select = s;
                    maxmaxlr = max(l,r);
                } else if (min(l,r)==maxminlr) {
                    if (max(l,r)>maxmaxlr) {
                        maxmaxlr = max(l,r);
                        select = s;
                    }
                }
            }

            data[select] = true;

            //cerr<<select<<' ';
            for1(i,0,data.size()) cerr<<data[i];
            //cerr<<endl;

            //cerr<<k<<endl;

            //if (k==0) {
                int l=0,r=0;
                for2(j,select-1,0) {
                    if (data[j]) break;
                    l++;
                }
                for1(j,select+1,n+2) {
                    if (data[j]) break;
                    r++;
                }
                cerr<<' '<<turn<<' '<<floor(log2(turn))<<' '<<l<<' '<<r<<endl;

                if (k==0) {
                    cout<<"Case #"<<_<<": "<<max(l,r)<<' '<<min(l,r)<<endl;
                }
            //}

        }
    }
	return 0;
}
