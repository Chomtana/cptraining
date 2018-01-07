#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef vector<int> vi;

int n,q;
vector<piii> mo[10000];
int data[2000005];
piii Q[2000005];
int c[50005];
int ans[2000005];

bool cpush(int i) {
    if (c[data[i]]) {
        c[data[i]]++;
        return false;
    } else {
        c[data[i]]++;
        return true;
    }
}

bool cpop(int i) {
    c[data[i]]--;
    if (c[data[i]]==0) return true;
    return false;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>q;
    for1(i,0,n) {
        scanf("%d",data+i);
    }
    for1(i,0,q) {
        scanf("%d%d",&Q[i].first.first,&Q[i].first.second);
        Q[i].first.first--;
        Q[i].first.second--;
        Q[i].second = i;
    }
    sort(Q,Q+q);
    int sqrtn = sqrt(n);
    for1(i,0,q) {
        mo[Q[i].first.first/sqrtn].push_back(Q[i]);
    }

    for1(i,0,10000) {
        if (mo[i].size()==0) continue;
        sort(all(mo[i]),[](piii a,piii b) {
            return a.first.second<b.first.second;
        });
        int currs = mo[i][0].first.first;
        int curre = mo[i][0].first.first;
        int curr = cpush(currs);

        //cerr<<i<<' '<<mo[i][0].first.first<<' '<<c[data[currs]]<<' '<<endl;

        for1(j,0,mo[i].size()) {
            int s = mo[i][j].first.first;
            int e = mo[i][j].first.second;
            for1(k,currs,s) curr-=cpop(k);
            for1(k,s,currs) curr+=cpush(k);
            for1(k,curre+1,e+1) {
                curr += cpush(k);
            }
            for1(k,e+1,curre+1) {
                curr -= cpop(k);
            }
            currs = s;
            curre = e;
            ans[mo[i][j].second] = curr;
        }

        for1(k,currs,curre+1) cpop(k);
    }

    for1(i,0,q) {
        printf("%d\n",ans[i]);
    }

	return 0;
}
