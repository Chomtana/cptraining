#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n;
int sold[100005];
int s[100005];
int P[100005];
pii dp[2005][2005];
vector<int> E[100005];

int fil[100005];

/*bool check(int c) {
    int snemax = -1e9;
    for1(i,0,E[c].size()) {
        int ne = E[c][i];
        if (fil[ne]==2) {
            s[ne] = s[c];
        } else {
            if (fil[c]==1) {
                if (s[ne]>s[c]) {
                    return false;
                }
            }
        }
        cout<<c<<' '<<ne<<' '<<s[ne]<<' '<<s[c]<<endl;
        snemax = max(snemax,s[ne]);
        if (!check(ne)) {
            return false;
        }
    }
    
    if (fil[c]==2) {
        s[c] = snemax;
    } else {
        if (s[c]<snemax) {
            return false;
        }
    }
    
    return true;
}*/

bool check(int c,int lastsel) {
    if (fil[c]==2) {
        if (lastsel!=-1) {
            if (s[c]>s[lastsel]) return false;
        }
        lastsel = c;
    }
    
    for1(i,0,E[c].size()) {
        int ne = E[c][i];
        if (!check(ne,lastsel)) return false;
    }
    
    return true;
}

int res = 1e9;

void fbf(int c) {
    if (c>=n) {
        for1(i,0,n) {
            s[i] = sold[i];
            //cout<<fil[i]<<' ';
        }
        //cout<<"\n------------------\n";
        if (check(0,-1)) {
            //cout<<"OK\n";
            int count = 0;
            for1(i,0,n) {
                if (fil[i]==2) {
                    count++;
                }
            }
            
            res = min(res,n-count);
        } //else cout<<"F\n";
        
        return;
    }
    
    fil[c] = 1;
    f(c+1);
    fil[c] = 0;
    
    fil[c] = 2;
    f(c+1);
    fil[c] = 0;
}

int f(int c) {
    int res = 1;
    
    dp[c] = {1,-1};
    
    if (c>0) {
        int lastsel = P[c];
        int plv = 1;
        while(lastsel!=-1) {
            if (s[c]<=s[lastsel]) {
                if (dp[lastsel].first+1>dp[c].first) {
                    dp[c].first = dp[lastsel].first+1;
                    dp[c].second = lastsel;
                }
            }
            
            lastsel = P[lastsel];
            plv++;
        }
    } else {
        dp[c] = {1,-1};
    }
    
    int x = -1;
    
    for1(i,0,E[c].size()) {
        int ne = E[c][i];
        x = max(x,f(ne));
    }
}

int main() {
    cin>>n;
    for1(i,0,n) {
        scanf("%d",s+i);
        sold[i] = s[i];
    }
    for1(i,0,n-1) {
        int s,e; scanf("%d %d",&s,&e);
        E[s].push_back(e);
        P[e] = s;
    }
    P[0] = -1;
    
    f(0);
    
    cout<<res;
    return 0;
}