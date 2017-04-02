#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,double>,int> type;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int t; cin>>t; while(t--) {
        int n;double s; cin>>n>>s;
        vector<type> data(n);
        vector<double> delayarr(n);

        for1(i,0,n) {
            double v,delay; cin>>v>>delay;
            delayarr[i] = delay;
            double time = (s*1000/v)+delay;
            data[i] = make_pair(make_pair(time,delay),i+1);
        }

        sort(all(data),[](type a,type b) {
            if (a.first.first < b.first.first) return true;
            if (a.first.first > b.first.first) return false;

            return a.first.second > b.first.second;
        });

        for1(i,0,n) {
            cout<<data[i].second<<endl;
        }
	}
	return 0;
}
