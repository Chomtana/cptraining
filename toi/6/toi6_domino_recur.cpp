#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;


vector<int> res;
int n;

void check() {
    string s = "";
    for1(i,0,n) {
        if (res[i]==1) {
            if (res[i+1]==0) {
                return;
            } else {
                s+="||\n";
                i++;
            }
        } else {
            s+="--\n";
        }
    }
    //printf("%sE\n",s.c_str());
    //for1(i,0,n) cout<<res[i]<<' ';
    //cout<<endl;
}

void bt(int resi) {
    if (resi>=n) {
        check();
        return;
    }
    //fill 0
    res[resi] = 0;
    bt(resi+1);
    //fill 1
    res[resi] = 1;
    bt(resi+1);
    //reset (reset to init val ... here we use init val = 0 it is danger but pass this question
    res[resi] = 0;
}


int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;

	cin>>n;
	res.resize(n+1);

    bt(0);

	return 0;
}
