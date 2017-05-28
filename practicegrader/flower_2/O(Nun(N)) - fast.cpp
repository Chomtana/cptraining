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

pii data[1000001];
//bool visitedr[1000001];
int g[1000001]; //keep group id of column c (row r always has same gid because loop will run through r and set gid of all same r to same gid)

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; while(t--) {
        int n; scanf("%d",&n);

        /*for1(i,0,1000001) {
            visitedr[i] = false;
            visitedc[i] = false;
        }*/

        for1(i,0,n) {
            int r, c; scanf("%d %d",&r,&c);
            data[i] = mp(r,c);
            //visitedr[r] = false;
            g[c] = 0;
        }

        sort(data,data+n);

        int currmap = 1;
        int res = 0;

        vector<int> gg(1); //map group id to another group id

        for1(i,0,n) {
            int fillg = currmap;
            int j = i;
            unordered_set<int> fillfound;
            while (j<n and data[j].first == data[i].first) {
                if (gg[g[data[j].second]]!=0) {
                    fillfound.insert(gg[g[data[j].second]]);
                    fillg = gg[g[data[j].second]];
                }
                j++;
            }
            if (fillfound.size()==0) {
                gg.push_back(currmap);
                currmap++;
                res++;
            } else {
                res -= fillfound.size()-1;
                for(const int &k:fillfound) {
                    gg[k] = fillg;
                }
            }
            j = i;
            while (j<n and data[j].first == data[i].first) {
                g[data[j].second] = fillg;
                j++;
            }
            i = j-1;
        }



        //printf("DBG%d\n",res);
        printf("%d\n",(res%2==0?res/2:res/2+1));

    }
	return 0;
}
