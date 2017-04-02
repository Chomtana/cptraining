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
    string name[n]; cin.ignore();
    for1(i,0,n) getline(cin,name[i]);
    vector<int> win(n,0);
    vector<int> score(n,0);
    vector<int> dif(n,0);
    for1(i,0,n*(n-1)/2) {
        int teama,teamb; cin>>teama>>teamb;
        int setnum; cin>>setnum;
        int awin = 0;
        int bwin = 0;
        int p1a,p1b; cin>>p1a>>p1b;
        if (p1a>p1b) {
            awin++;
            dif[teama-1]++;
            dif[teamb-1]--;
        } else {
            bwin++;
            dif[teamb-1]++;
            dif[teama-1]--;
        }
        int p2a,p2b; cin>>p2a>>p2b;
        if (p2a>p2b) {
            awin++;
            dif[teama-1]++;
            dif[teamb-1]--;
        } else {
            bwin++;
            dif[teamb-1]++;
            dif[teama-1]--;
        }

        if (setnum == 3) {
            int p3a,p3b; cin>>p3a>>p3b;
            if (p3a>p3b) {
                awin++;
                dif[teama-1]++;
                dif[teamb-1]--;
            } else {
                bwin++;
                dif[teamb-1]++;
                dif[teama-1]--;
            }
        }

        if (awin >= 2) {
            win[teama-1]++;
            score[teama-1]+=2;
            if (bwin==1) {
                score[teamb-1]++;
            }
        } else {
            win[teamb-1]++;
            score[teamb-1]+=2;
            if (awin==1) {
                score[teama-1]++;
            }
        }
    }

    for1(i,0,n) {
        cout<<name[i]<<' '<<win[i]<<' '<<score[i]<<' '<<dif[i]<<endl;
    }
	return 0;
}
