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

pii inv[3][5]; //inv[1] = {pair that have answer 1}
int invsize[3];

int n; string data;

char dp[260][260][260][3][3];

///3 main meaning point , multisection dp
bool f(int s,int p,int e,int wl,int wr) { //is [s,p),[p,e) can have answer [s,p) = wl , [p,e) = wr
    bool l = false; ///left section answer
    bool r = false; ///right section answer
    bool lbc = false; ///is left hit base case step (if it hit base case step -> mustn't do next step)
    bool rbc = false; ///is right hit base case step (if it hit base case step -> mustn't do next step)

    ///left section base case
    if (p-s==1) {
        l = data[s]-'0'==wl;
        if(l==false) return false; //optimize : special case of fusion section , if l=false or r=false -> l&&r=false
        lbc = true; //instead of return , set hit base case status = true
    }

    ///right section base case
    if (e-p==1) {
        r = data[p]-'0'==wr;
        if(r==false) return false;
        rbc = true; //instead of return , set hit base case status = true
    }

    if (dp[s][p][e][wl][wr]!=2) return dp[s][p][e][wl][wr];


    ///left section next
    if (!lbc) { //if not hit base case -> do next
        for1(i,s+1,p) {
            for1(j,0,invsize[wl]) {
                l = l | f(s,i,p,inv[wl][j].first,inv[wl][j].second);
                if (l) break;
            }
            if (l) break;
        }
    }

    if (l==false) return dp[s][p][e][wl][wr]=false; ///if 100% sure whether do or don't do next section it will get same answer

    ///right section next
    if (!rbc) { //if not hit base case -> do next
        for1(i,p+1,e) {
            for1(j,0,invsize[wr]) {
                r = r | f(p,i,e,inv[wr][j].first,inv[wr][j].second);
                if (r) break;
            }
            if (r) break;
        }
    }

    //if(r==false) return false; //very near fusion step

    return dp[s][p][e][wl][wr] = l&&r;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;

	inv[0][0] = mp(0,2);
    inv[1][0] = mp(0,1);
    inv[1][1] = mp(1,1);
    inv[1][2] = mp(1,2);
    inv[1][3] = mp(2,0);
    inv[1][4] = mp(2,2);
    inv[2][0] = mp(0,0);
    inv[2][1] = mp(1,0);
    inv[2][2] = mp(2,1);
    invsize[0] = 1;
    invsize[1] = 5;
    invsize[2] = 3;


    int t = 20; while(t--) {
        for1(i,0,n+5) for1(j,0,n+5) for1(k,0,n+5) for1(l,0,3) for1(m,0,3) dp[i][j][k][l][m] = 2;
        cin>>n>>data;
        if (data[0]!='0') {
            cout<<"no"<<endl;
            continue;
        }
        bool res = false;
        for1(p,1,n) {
            res = res | f(0,p,n,0,2);
            if (res) break;
        }
        if (res) cout<<"yes"<<endl; else cout<<"no"<<endl;
    }
	return 0;
}
