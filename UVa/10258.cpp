#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    int _; cin>>_;
    //bt(0,0);
    cin.ignore();
    cin.ignore();
    while (_--) {
        string _s;
        ll time[101][10];
        bool correct[101][10];
        for1(i,0,101) for1(j,0,10) time[i][j] = 0;
        for1(i,0,101) for1(j,0,10) correct[i][j] = false;
        bool display[101];
        fill(display,display+101,false);
        while (getline(cin,_s) && _s!="") {
            stringstream ss(_s);
            ll x; ss>>x;
            ll p; ss>>p;
            ll t; ss>>t;
            char l; ss>>l;
            if (l=='I') {
                if (!correct[x][p]) {
                    time[x][p] += 20;
                }
            } else if (l=='C') {
                if (!correct[x][p]) {
                    correct[x][p] = true;
                    time[x][p] += t;
                }
            }
            display[x] = true;
        }

        ll numsolve[101];
        ll totaltime[101];
        fill(numsolve,numsolve+101,0);
        fill(totaltime,totaltime+101,0);
        for1(i,0,101) {
            for1(j,0,10) {
                numsolve[i] += correct[i][j];
                if (correct[i][j]) {
                    totaltime[i] += time[i][j];
                }
            }
        }

        ll rank[101];
        for1(i,0,101) rank[i]=i;
        sort(rank,rank+101,[&numsolve,&totaltime](ll a,ll b) {
            if (numsolve[a]>numsolve[b]) return true;
            if (numsolve[a]<numsolve[b]) return false;

            if (totaltime[a]<totaltime[b]) return true;
            if (totaltime[a]>totaltime[b]) return false;

            return a<b;
        });

        for1(i,0,101) {
            if (display[rank[i]]) {
                cout<<rank[i]<<' '<<numsolve[rank[i]]<<' '<<totaltime[rank[i]]<<endl;
            }
        }
        if (_) cout<<endl;
    }
    return 0;
}
