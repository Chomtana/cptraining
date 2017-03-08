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
	cout<<setprecision(4);
	int t; cin>>t; cin.ignore();
	string s; getline(cin,s);

	while (t--) {
        map<string,int> count;
        while (getline(cin,s)) {
            if (s=="") break;
            count[s]++;
        }
        int sum = 0;
        for(auto it = count.begin();it!=count.end();it++) {
            sum += it->second;
            //cout<<it->first<<' '<<it->second<<endl;
        }
        //sum++;
        for(auto it = count.begin();it!=count.end();it++) {
            cout<<it->first<<' '<<(double)it->second/(double)sum*100.0<<endl;
        }
        if (t>0) {
            cout<<endl;
        }
	}
	return 0;
}
