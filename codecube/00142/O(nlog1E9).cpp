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
int data[100005];
int ep[200005];

bool check(int h) {
    //use fast one-way greedy (ep + real time qs->get qs from 0 to before curr) (need to curr -> qs+ep[curr] -> if do befroe -> will get value before do cut)
    memset(ep,0,sizeof(ep));
    int c = 0;
    int qs = 0;
    for1(i,0,n) {
        int qsx = qs+ep[i];
        //cerr<<h<<' '<<i<<' '<<qsx;
        if (data[i]-qsx>h) {
            c+=data[i]-qsx-h;
            ep[i] += data[i]-qsx-h;
            ep[i+w] -= data[i]-qsx-h;
        }
        qs += ep[i];
        //cerr<<' '<<c<<endl;
        if (c>k) return false;
    }

    return true;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>w>>k;
    for1(i,0,n) scanf("%d",data+i);
    int l = 0,r = 1E9;
    while (l<=r) {
        int mid = (l+r)/2;
        if (check(mid)) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout<<l<<endl;
    //cerr<<check(1)<<endl;
	return 0;
}
