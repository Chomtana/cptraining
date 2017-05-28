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
	ios::sync_with_stdio(false);
	cout<<fixed;
	string raw;
	string ignore;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
    int queryt[3001];
    while (getline(cin,raw),raw!="#") {
        stringstream ss(raw);
        ss>>ignore;
        int q,t;
        ss>>q;
        ss>>t;
        pq.push(mp(t,q));
        queryt[q] = t;
    }

    int k ; cin>>k;
    while (k--) {
        int q = pq.top().second;
        int t = pq.top().first+queryt[q];

        pq.pop();

        printf("%d\n",q);

        pq.push(mp(t,q));
    }


	return 0;
}
