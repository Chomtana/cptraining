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
typedef vector<int> vi;

int n,m;
//map<int,vector<pair<pii,int>>> Trem;
//map<int,vector<pair<pii,pii>>> Tchange;
vector<int> Trem[200005];
vector<pii> Tchange[200005];
bool removed[100005];
pii i2v[200005];

multiset<pair<pii,int>> data;

void dochange(int t) {

    //if (Trem.find(t)!=Trem.end()) {
        for1(i,0,Trem[t].size()) {
            if (!removed[Trem[t][i]]) {
                //cerr<<"t "<<t<<' '<<Trem[t][i].second<<" removed"<<endl;
                data.erase(data.find(mp(i2v[Trem[t][i]],Trem[t][i])));
            }
        }
    //}

    //if (Tchange.find(t)!=Tchange.end()) {
        for1(i,0,Tchange[t].size()) {
            if (!removed[Tchange[t][i].second]) {
                //cerr<<"t "<<t<<' '<<Tchange[t][i].second.second<<" changed"<<endl;
                data.erase(data.find(mp(i2v[Tchange[t][i].second],Tchange[t][i].second)));
                data.insert(mp(mp(Tchange[t][i].first,i2v[Tchange[t][i].second].second),Tchange[t][i].second));
                i2v[Tchange[t][i].second] = mp(Tchange[t][i].first,i2v[Tchange[t][i].second].second);
            }
        }
    //}

    Trem[t].clear();
    Tchange[t].clear();
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>m;
    for1(i,0,n+m) {
        dochange(i);

        int roottype; scanf("%d",&roottype);
        if(roottype==1) {
            int type; scanf("%d",&type);
            int a,b; scanf("%d%d",&a,&b);
            data.insert(mp(mp(a,b),i));
            i2v[i] = mp(a,b);
            if (type==1) {

            } else if (type==2) {

                int t; scanf("%d",&t);
                if (t<200005) {
                    Trem[t].push_back(i);
                }
            } else {

                int t; scanf("%d",&t);
                int w; scanf("%d",&w);
                if (t<200005) {
                    Tchange[t].push_back(mp(w,i));
                }
            }
        } else {
            if (data.size()!=0) {
                printf("%d\n",data.begin()->first.second);
                removed[data.begin()->second] = true;
                data.erase(data.begin());
            } else {
                printf("0\n");
            }
        }
    }
	return 0;
}
