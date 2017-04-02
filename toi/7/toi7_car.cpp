#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int m,start,nt;
vector<vector<int>> data;

#define macro(x) if (x.size()!=0) { x.push_back(thisans); dp[t][l][thisans] = x;}

vector<vector<vector<vector<int>>>> dp;
vector<vector<vector<bool>>> indp;

vector<int> recursive(int t,int l,int thisans) {
    //cout<<t<<' '<<l<<' '<<thisans<<endl;
    //if (t==3 && l==0) cout<<"aaa"<<endl;
    if (l<0 || l>=m) return vector<int>();
    if (t>=nt) {
        return vector<int>(1,thisans);
    }
    if (data[t][l]) {
        //cout<<t<<' '<<l<<endl;
        return vector<int>();
    }

    if (indp[t][l][thisans]) {
        return dp[t][l][thisans];
    }

    vector<int> a = recursive(t+1,l-1,1);
    vector<int> b = recursive(t+1,l+1,2);
    vector<int> c = recursive(t+1,l,3);

    if (a.size()==0 && b.size()==0 && c.size()==0) {
        indp[t][l][thisans] = true;
        dp[t][l][thisans] = a;
        return dp[t][l][thisans];
    }
    //if(a.size()==0) return a;
    macro(a)
    macro(b)
    macro(c)

    indp[t][l][thisans] = true;
    return dp[t][l][thisans];
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>m>>start>>nt;
    start--;
    data.resize(nt,vector<int>(m));
    for1(i,0,nt) {
        for1(j,0,m) {
            cin>>data[i][j];
        }
    }

    dp.resize(nt,vector<vector<vector<int>>>(m,vector<vector<int>>(4)));
    indp.resize(nt,vector<vector<bool>>(m,vector<bool>(4,false)));

    vector<int> a = recursive(0,start-1,1);
    vector<int> b = recursive(0,start+1,2);
    vector<int> c = recursive(0,start,3);
    //cout<<a.size()<<' '<<b.size()<<' '<<c.size()<<endl;
    if (a.size()!=0) {
        reverse(all(a));
        for1(i,0,a.size()-1) {
            cout<<a[i]<<endl;
        }
    }
    else if (b.size()!=0) {
        reverse(all(b));
        for1(i,0,b.size()-1) {
            cout<<b[i]<<endl;
        }
    }
    else if (c.size()!=0) {
        reverse(all(c));
        for1(i,0,c.size()-1) {
            cout<<c[i]<<endl;
        }
    }

	return 0;
}
