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
typedef pair<bool,bool> type; //pos,isstart,isend

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int n,m,t,l; scanf("%d %d %d %d",&n,&m,&t,&l);
    vector<int> bomb(n);
    for1(i,0,n) scanf("%d",&bomb[i]);
    sort(all(bomb));
    while (t--) {
        map<int,type> data;
        for1(i,0,m) {
            int x; scanf("%d",&x);
            if (!data.count(x-l)) {
                data[x-l] = mp(true,false);
            } else {
                data[x-l].first = true;
            }
            if (!data.count(x+l)) {
                data[x+l] = mp(false,true);
            } else {
                data[x+l].second = true;
            }
        }

        vector<int> rw; //rw = [1,5,6,8,10,11] ; (1,5) , (6,8) , (10,11)

        int startc = 0;

        for(auto &it:data) {
            if (it.second.first && it.second.second) continue;
            if (it.second.first) {
                if (startc == 0) {
                    rw.push_back(it.first);
                }
                startc++;
            }
            else if (it.second.second) {
                startc--;
                if (startc == 0) {
                    rw.push_back(it.first);
                }
            }
        }

        /*for(int &i:rw) cerr<<i<<' ';
        cerr<<endl;*/

        int res = 0;

        for(int i = 0;i<rw.size();i+=2) {
            //>= <=
            int s = lower_bound(all(bomb),rw[i])-bomb.begin();
            int e = upper_bound(all(bomb),rw[i+1])-bomb.begin();
            e--;
            if (s==bomb.size()) continue;
            if (e==-1) continue;
            if (s<=e) {
                res += e-s+1;
            }
        }

        printf("%d\n",res);

    }
	return 0;
}
