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

int n;
string data[20005];
ll res = 0;

bool comp(string& big,string& small,int bigstart) {
    for1(i,bigstart,bigstart+small.size()) {
        if (big[i] != small[i-bigstart]) return false;
    }
    return true;
}

bool dofind(string& big,string& small) {
    ll baseh = 0;
    ll powh1 = 1;
    for1(i,0,small.size()) {
        baseh *= 53;
        baseh += small[i]-'a';
        if (i>0) powh1 *= 53;
    }

    ll h = 0;
    for1(i,0,small.size()) {
        h *= 53;
        h += big[i]-'a';
    }

    if (h==baseh && comp(big,small,0)) return true;

    for1(i,1,big.size()-small.size()+1) {
        h -= (big[i-1]-'a')*powh1;
        h *= 53;
        h += big[i+small.size()-1]-'a';
        if (h==baseh && comp(big,small,i)) return true;
    }

    return false;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n;
    for1(i,0,n) {
        cin>>data[i];
    }

    for1(i,0,n) {
        for1(j,0,n) {
            if(i==j || data[i].size()<data[j].size()) continue;
            bool subres = dofind(data[i],data[j]);
            //cerr<<data[i]<<' '<<data[j]<<' '<<subres<<endl;
            if (subres) {

                res++;
            }
        }
    }

    cout<<res;
	return 0;
}
