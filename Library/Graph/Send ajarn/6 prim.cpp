#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int nv,ne; cin>>nv>>ne;
    vector<vector<pii>> E(nv+1);
    for1(i,0,ne) {
        int s,e,w; cin>>s>>e>>w;
        E[s].push_back(mp(e,w));
        E[e].push_back(mp(s,w));
    }

    //do dijkstra
    //int start,end; cin>>start>>end;
    vector<pii> selected;
    int sigmaw = 0;
    vector<bool> visited(nv+1,false);
    //visited[1] = true;
    vector<int> before(nv+1,1E9);
    priority_queue<piii,vector<piii>,greater<piii>> q;
    q.push(mp(0,mp(1,1)));
    while (!q.empty()) {
        pii curr = q.top().second;
        int currdist = q.top().first;
        //cout<<curr.second<<' '<<visited[curr.second]<<endl;
        if (!visited[curr.second]) {
            selected.push_back(curr);
            sigmaw += currdist;
            visited[curr.second] = true;
            q.pop();
        } else {
            q.pop();
            continue;
        }


        for1(i,0,E[curr.second].size()) {
            int next = E[curr.second][i].first;
            int nextw = E[curr.second][i].second;
            //cout<<next<<' '<<nextw<<endl;
            q.push(mp(nextw,mp(curr.second,E[curr.second][i].first)));
        }
    }

    cout<<"Sum of MST weight : "<<sigmaw<<endl;
    for1(i,0,selected.size()) {
        cout<<selected[i].first<<' '<<selected[i].second<<endl;
    }
	return 0;
}

/*
10 11
1 5 3
5 4 1
2 6 2
6 3 6
5 6 8
7 8 3
7 9 11
8 9 9
7 10 2
2 7 8
3 8 5
*/
