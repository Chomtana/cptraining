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

bool isdif1(string& a,string& b) {
    if (a.size()!=b.size()) return false;
    int difcount = 0;
    for1(i,0,a.size()) {
        difcount += a[i]!=b[i];
        if (difcount>1) return false;
    }
    return difcount==1;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; cin.ignore(); cin.ignore(); while(t--) {
        string inraw;
        vector<string> dict;
        while(getline(cin,inraw)&&inraw!="*") {
            dict.push_back(inraw);
        }
        /*for1(i,0,dict.size()) {
            cerr<<"DBG "<<dict[i]<<endl;
        }*/


        vector<vector<int>> E(dict.size());

        for1(i,0,dict.size()) {
            for1(j,i+1,dict.size()) {
                if (isdif1(dict[i],dict[j])) {
                    E[i].push_back(j);
                    E[j].push_back(i);
                }
            }
        }


        while(getline(cin,inraw)&&inraw!="") {
            stringstream inss(inraw);
            string froms;
            string tos;
            inss>>froms>>tos;
            //cerr<<"DBG "<<froms<<' '<<tos<<endl;

            int from,to;
            for1(i,0,dict.size()) {
                if (dict[i]==froms) {
                    from = i;
                }
                if (dict[i]==tos) {
                    to = i;
                }
            }

            vector<int> dist(dict.size(),1E9);
            queue<int> q;
            q.push(from);
            dist[from] = 0;
            while (!q.empty()) {
                if (dist[to]!=1E9) break;
                int curr = q.front();
                q.pop();
                for1(i,0,E[curr].size()) {
                    int next = E[curr][i];
                    if (dist[next]==1E9) {
                        dist[next] = dist[curr]+1;
                        q.push(next);
                    }
                }
            }

            cout<<froms<<' '<<tos<<' '<<dist[to]<<endl;


        }

        if(t != 0)
          cout<<endl;
    }
	return 0;
}
