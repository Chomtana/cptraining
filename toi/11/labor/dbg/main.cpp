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

ll m,n;
ll data[1000005];

ll isok(ll s) {
    ll curr = 0;
    ll currmax = 0;
    for1(i,0,m) {
        ll add = s/data[i];
        //ll add = 1000;
        if (add == 0) break;
        curr += add;
        if (curr>n) {
            ll exceed = curr-n;
            currmax = max(currmax,add*data[i]-data[i]*exceed);
            curr = n;
            break;
        }
        currmax = max(currmax,add*data[i]);
    }
    //cerr<<s<<' '<<curr<<' '<<currmax<<endl;
    if(curr==n) return currmax; else return -1;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    //srand(time(0));
    cin>>m>>n;


    for1(i,0,m) {
        scanf("%lld",&data[i]);
        //data[i] = rand()%1000000+10;
    }

    sort(data,data+m);

    ll res = 2E18;

    //cout<<res<<endl;

    //binary search
    ll l = 0;
    ll h = 1E18;
    while (l<=h) {
        ll mid = (l+h)/2;
        ll curr = isok(mid);
        //ll curr = -1;

        //cerr<<mid<<endl;

        if (curr != -1) {
            if (curr!=-2) res = min(res,curr);
            h = mid-1;
        } else {
            l = mid+1;
        }
    }

    cout<<res;
	return 0;
}
