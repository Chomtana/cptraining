#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
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
    int start,end; cin>>start>>end;
    vector<int> dist(nv+1,1E9);
    dist[start] = 0;
    vector<int> before(nv+1,1E9);
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push(mp(0,start));
    while (!q.empty()) {
        int curr = q.top().second;
        int currdist = q.top().first;
        q.pop();
        for1(i,0,E[curr].size()) {
            int next = E[curr][i].first;
            int nextw = E[curr][i].second;
            //cout<<next<<' '<<nextw<<endl;
            if (currdist+nextw<dist[next]) {
                dist[next] = currdist+nextw;
                before[next] = curr;
                q.push(mp(dist[next],next));
            }
        }
    }

    if (dist[end]==1E9) cout<<"Cannot go to end"; else {
        cout<<"Distance : "<<dist[end]<<endl;
        //do print path from end
        //use pointer moving from end to start
        int curr = end;
        while (curr!=start) {
            cout<<curr<<' ';
            curr = before[curr];
        }
        cout<<curr<<' ';
    }
	return 0;
}

/*
10 9
1 5 3
5 4 1
2 6 2
6 3 6
5 6 8
7 8 3
7 9 11
8 9 9
7 10 2
1 6
*/
