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
    int n; cin>>n;
    ll team1[n]; for1(i,0,n) cin>>team1[i];
    ll team2[n]; for1(i,0,n) cin>>team2[i];
    sort(team1,team1+n);
    sort(team2,team2+n);
    ll minsum = 1E16;
    vector<vector<int>> team1res;
    vector<vector<int>> team2res;
    do {
        do {
            ll sum = 0;
            for1(i,0,n) {
                sum += abs(team1[i]-team2[i]);
            }
            if (sum<minsum) {
                minsum = sum;
                team1res.clear(); team2res.clear();
                vector<int> team1r(team1,team1+n);
                vector<int> team2r(team2,team2+n);
                team1res.push_back(team1r);
                team2res.push_back(team2r);
            } else if (sum==minsum) {
                vector<int> team1r(team1,team1+n);
                vector<int> team2r(team2,team2+n);
                team1res.push_back(team1r);
                team2res.push_back(team2r);
            }
        } while (next_permutation(team2,team2+n));
    } while (next_permutation(team1,team1+n));

    cout<<minsum<<endl;

    for1(i,0,team1res.size()) {
        cout<<endl;
        for1(j,0,team1res[i].size()) {
            cout<<team1res[i][j]<<' ';
        }
        cout<<endl;
        for1(j,0,team2res[i].size()) {
            cout<<team2res[i][j]<<' ';
        }
        cout<<endl;
    }


	return 0;
}
