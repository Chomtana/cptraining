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

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int n,s; scanf("%d %d",&n,&s);
    vector<vector<int>> E(n+1);
    vector<bool> visited(n+1,false);
    vector<bool> VP(n+1,false);
    for1(i,0,n) {
        int ss,ee; scanf("%d %d",&ss,&ee);
        E[ss].push_back(ee);
        E[ee].push_back(ss);
        if (ss==s || ee==s) {
            VP[ss] = true;
            VP[ee] = true;
            visited[ss] = true;
            visited[ee] = true;
        }
    }

    int currmap = 0;

    vector<pii> gdata;
    vector<int> gid(n+1); //gid[V] = group id of that node

    subfunc(int,bfs,(int st)) {
        int count = 0;

        queue<int> q;
        q.push(st);
        visited[st] = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            count++;
            gid[curr] = currmap;

            for(int &next:E[curr]) {
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }

        return count;
    };

    for1(i,1,n+1) {
        if (!visited[i]) {
            gdata.push_back(mp(bfs(i),0));
            currmap++;
        }
    }

    /*for(pii &p:gdata) {
        cout<<p.first<<' ';
    }*/

    for(int &i:E[s]) {
        unordered_set<int> gidadd;
        for(int &j:E[i]) {
            if (VP[j]) continue;
            gidadd.insert(gid[j]);
        }
        for(const int &j:gidadd) {
            gdata[j].second++;
        }
    }

    int maxnode = -1;
    int maxcount = -1;

    bool allzero = true;

    for(int &i:E[s]) {
        int count = 0;
        unordered_set<int> gidadd;
        for(int &j:E[i]) {
            if (VP[j]) continue;
            if (gdata[gid[j]].second<=1) gidadd.insert(gid[j]);
        }

        for(const int &j:gidadd) {
            count += gdata[j].first;
        }

        cerr<<i<<' '<<count<<endl;

        if (count!=0) allzero = false;


        if (count>maxcount) {
            maxcount = count;
            maxnode = i;
        } else if (count==maxcount) {
            maxnode = min(maxnode,i);
        }
    }

    if (allzero) {
        if (s==1) {
            cout<<"2\n0";
        } else {
            cout<<"1\n0";
        }
        return 0;
    }

    ///mai me pon prok แหล่งสำรองข้อมูลหลักสามารถส่งไปถึงทุกแหล่งสำรองข้อมูลอื่นๆ ได้ ; ส่งได้ <-> connected ; ส่งได้หมด -> connected หมด
    /*
    //check unconnnected
    visited.clear();
    visited.resize(n+1,false);
    int conc = bfs(s); ///this operation will ruin gid and gdata so don't put code that use gid , gdata below here
    */

    cout<<maxnode<<endl<<maxcount/*+(n-conc)*/;



	return 0;
}
