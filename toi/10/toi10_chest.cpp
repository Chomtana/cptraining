#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef unsigned long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int m,n;

map<int,vector<int>> data; //eparr[...] = {power of prime factor at that point (1-9)}

vector<int> dosum(vector<int> &a,vector<int> &b) {
    vector<int> res(10);
    for1(i,0,10) res[i] = a[i]+b[i];
    return res;
}

void epop(bool add,int pos,int val) {
    int s = (add?1:-1);
    if (data.find(pos)==data.end()) data[pos].resize(10);
    if(val==2) {
        data[pos][2]+=s*1;
    } else if (val==3) {
        data[pos][3]+=s*1;
    } else if (val==4) {
        data[pos][2]+=s*2;
    } else if (val==5) {
        data[pos][5]+=s*1;
    } else if (val==6) {
        data[pos][2]+=s*1;
        data[pos][3]+=s*1;
    } else if (val==7) {
        data[pos][7]+=s*1;
    } else if (val==8) {
        data[pos][2]+=s*3;
    } else if (val==9) {
        data[pos][3]+=s*2;
    } else if (val==10) {
        data[pos][2]+=s*1;
        data[pos][5]+=s*1;
    }
}

ll query(vector<int> &curr) {
    ll res = 1;
    for1(i,0,10) {
        res *= curr[i]+1;
    }
    return res;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>m>>n;
    for1(i,0,m) {
        int x,s,e; scanf("%d%d%d",&x,&s,&e);
        epop(true,s,x);
        epop(false,e+1,x);
    }

    ll res = 1;
    ll size = n;
    vector<int> curr(10);
    for(auto it = data.begin();it!=data.end();++it) {
        curr = dosum(curr,it->second);
        ll subres = query(curr);
        if (subres>res) {
            res = subres;
            int ci = it->first;
            it++;
            if (it==data.end()) {
                size = n-ci;
            } else {
                size = it->first - ci;
            }
            it--;
        } else if (subres==res) {
            int ci = it->first;
            it++;
            if (it==data.end()) {
                size += n-ci;
            } else {
                size += it->first - ci;
            }
            it--;
        }
    }
    cout<<res<<' '<<size;
	return 0;
}
