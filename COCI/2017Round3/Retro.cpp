/*
This is a dag graph -> DP!!! let see ... it move only in one direction from bottom to top
Graph will be DAG if it move in one direction in all plane (dimension-1 dimension)
*/

#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

//#define max(a,b,c) max(max(a,b),c)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef vector<int> vi;

class type{
    public:
    ll s1 = 0;
    ll s2 = 0;
    ll s3 = 0;
    ll s4 = 0;
    ll s5 = 0;
    int len = -1;
    
    type(int len) {
        this->len = len;
    }
    
    type() {
        
    }
    
    type(int len,int s1,int s2,int s3,int s4) {
        this->len = len;
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        this->s4 = s4;
        this->s5 = s5;
    }
};

int nr,nc;

char data[305][305];
//int dp[305][305][305];
type dpbu[305][305];
type dpbubf[305][305];
int sr,sc;

type maxa(type a,type b) {
    if (a.len>b.len) return a;
    else if (a.len<b.len) return b;
    
    if (a.s1>b.s1) return a;
    else if (a.s1<b.s1) return b;
    
    if (a.s2>b.s2) return a;
    else if (a.s2<b.s2) return b;
    
    if (a.s3>b.s3) return a;
    else if (a.s3<b.s3) return b;
    
    if (a.s4>b.s4) return a;
    else if (a.s4<b.s4) return b;

    if (a.s5>b.s5) return a;
    else if (a.s5<b.s5) return b;

    return a;
}

type maxa(type a,type b,type c) {
    return maxa(maxa(a,b),c);
}

type add(type a,int r,int c) {
    if (a.len<0) return a;
    
    if (a.len<61) {
        if (data[r][c]=='(') {
            a.s1 |= (1<<a.len);
        } else {
            a.s1 &= ~(1<<a.len);
        }
    } else if (a.len<121) {
        if (data[r][c]=='(') {
            a.s2 |= (1<<(a.len-61));
        } else {
            a.s2 &= ~(1<<(a.len-61));
        }
    } else if (a.len<181) {
        if (data[r][c]=='(') {
            a.s3 |= (1<<(a.len-121));
        } else {
            a.s3 &= ~(1<<(a.len-121));
        }
    } else if (a.len<241) {
        if (data[r][c]=='(') {
            a.s4 |= (1<<(a.len-181));
        } else {
            a.s4 &= ~(1<<(a.len-181));
        }
    } else if (a.len<301) {
        if (data[r][c]=='(') {
            a.s5 |= (1<<(a.len-241));
        } else {
            a.s5 &= ~(1<<(a.len-241));
        }
    }
    
    a.len++;
    return a;
}

//bu must start at index 1 because it will out of border
type bu(int r,int c,int lv) {
    if (r<=0 || c<=0) {
        if (lv==0) {
            return type(0);
        } else {
            return type(-999999);
        }
    }
    if (data[r-1][c-1]=='*') {
        return type(-999999);
    }
    
    if (data[r-1][c-1]!='(' && data[r-1][c-1]!=')') {
        return maxa(dpbubf[c-1][lv],dpbubf[c+1][lv],dpbubf[c][lv]);
    } else {
        if (data[r-1][c-1]=='(') {
            return maxa(add(dpbubf[c-1][lv+1],r-1,c-1),add(dpbubf[c+1][lv+1],r-1,c-1),add(dpbubf[c][lv+1],r-1,c-1));
        } else {
            if (lv>0) {
                return maxa(add(dpbubf[c-1][lv-1],r-1,c-1),add(dpbubf[c+1][lv-1],r-1,c-1),add(dpbubf[c][lv-1],r-1,c-1));
            } else {
                return type(-999999);
            }
        }
    }
}

/*int f(int r,int c,int lv) {
    if (r<0 || c<0) {
        if (lv==0) {
            return 0;
        } else {
            return -999999;
        }
    }
    if (data[r][c]=='*') {
        return -999999;
    }
    
    if (dp[r][c][lv]!=-1) return dp[r][c][lv];
    
    if (data[r][c]!='(' && data[r][c]!=')') {
        return dp[r][c][lv] = max(f(r-1,c-1,lv),f(r-1,c+1,lv),f(r-1,c,lv));
    } else {
        if (data[r][c]=='(') {
            return dp[r][c][lv] = max(f(r-1,c-1,lv+1)+1,f(r-1,c+1,lv+1)+1,f(r-1,c,lv+1)+1);
        } else {
            if (lv>0) {
                return dp[r][c][lv] = max(f(r-1,c-1,lv-1)+1,f(r-1,c+1,lv-1)+1,f(r-1,c,lv-1)+1);
            } else {
                return dp[r][c][lv] = -999999;
            }
        }
    }
}*/

int main() {
    //ios::sync_with_stdio(false);
    //memset(dp,-1,sizeof(dp));
    memset(dpbu,-1,sizeof(dpbu));
    
    cout<<fixed;
    cin>>nr>>nc;
    for1(i,0,nr) {
        scanf("%s",data[i]);
    }
    
    for1(i,0,nr) {
        for1(j,0,nc) {
            if (data[i][j]=='M') {
                sr = i; sc=j;
            }
        }
    }
    
    for1(j,0,nc+2) {
        for1(k,0,305) {
            dpbubf[j][k] = bu(0,j,k);
            //if (k<=10) cerr<<dpbubf[j][k]<<' ';
        }
        //cerr<<endl;
    }
    //cerr<<endl;
    
    for(int i = 1;i<=sr+1;i++) {
        for1(j,0,nc+2) {
            for1(k,0,nr+1) {
                dpbu[j][k] = bu(i,j,k);
            }
        }
        
        for1(j,0,nc+2) {
            for1(k,0,nr+1) {
                //if (k<=10) cerr<<dpbu[j][k].len<<' ';
                dpbubf[j][k] = dpbu[j][k];
            }
            //cerr<<endl;
        }
        //cerr<<endl;
    }
    
    type &res = dpbu[sc+1][0];
    //int res = f(sr,sc,0);
    
    /*f(sr,sc,0);
    for(int i = 0;i<=sr;i++) {
        for1(j,0,nc) {
            for1(k,0,305) {
                if (k<=10) cerr<<dp[i][j][k]<<' ';
            }
            cerr<<endl;
        }
        cerr<<endl;
    }*/
    
    
    cout<<res.len<<endl;
    stack<char> resS;
    for1(i,0,res.len) {
        if (i<61) {
            if (res.s1&(1<<(i%61))) {
                resS.push('(');
            } else {
                resS.push(')');
            }
        } else if (i<121) {
            if (res.s2&(1<<(i%61))) {
                resS.push('(');
            } else {
                resS.push(')');
            }
        } else if (i<181) {
            if (res.s3&(1<<(i%61))) {
                resS.push('(');
            } else {
                resS.push(')');
            }
        } else if (i<241) {
            if (res.s4&(1<<(i%61))) {
                resS.push('(');
            } else {
                resS.push(')');
            }
        } else if (i<301) {
            if (res.s5&(1<<(i%61))) {
                resS.push('(');
            } else {
                resS.push(')');
            }
        }
    }
    while (!resS.empty()) {
        printf("%c",resS.top()); resS.pop();
    }
    return 0;
}
