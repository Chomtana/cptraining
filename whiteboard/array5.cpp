#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    cout<<"Input master : "; string master; cin>>master;
    cout<<"Input target : "; string target; cin>>target;
    int res = 0;
    for1(i,0,master.size()-target.size()+1) {
        string sub = master.substr(i,target.size());
        res += (sub==target);

    }
    cout<<"master found in target : "<<res<<(res!=1?" times":" time");
	return 0;
}
