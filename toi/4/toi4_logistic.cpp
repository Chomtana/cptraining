#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define mt make_tuple


using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char,int> pci;
typedef pair<char,char> pcc;
typedef vector<int> vi;

double findmed(vi &v) {
    if (v.size()%2==0) {
        return double(v[v.size()/2]+v[v.size()/2-1])/2.0;
    } else {
        return v[v.size()/2];
    }
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int n; scanf("%d",&n);
    vector<vector<pci>> E(256);
    map<pcc,vi> W;
    for1(i,0,n){
        char s,e; int w; scanf(" %c %c %d",&s,&e,&w);
        E[s].push_back(mp(e,w));
        E[e].push_back(mp(s,w));
        W[mp(s,e)].push_back(w);
        W[mp(e,s)].push_back(w);
    }

    queue<char> q;
    vector<bool> visited(256,false);
    q.push('X');
    visited['X'] = true;
    bool notbroken = false;
    while (!q.empty()) {
        char curr = q.front();
        if (curr=='Y') {
            notbroken = true;
            break;
        }
        q.pop();
        for1(i,0,E[curr].size()) {
            char next = E[curr][i].first;
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }

    }

    if (!notbroken) {
        cout<<"broken"; return 0;
    }

    map<pcc,double> res;
    double sum = 0;

    for(map<pcc,vi>::iterator it = W.begin();it!=W.end();it++) {
        vi &w = it->second;
        sort(all(w));
        double med = findmed(w);
        //char mini = min(it->first.first,it->first.second);
        //char maxi = max(it->first.first,it->first.second);
        res[it->first] = med;
        sum += med;
    }

    visited.clear();

    while (!q.empty()) q.pop();

    visited.resize(256,false);
    q.push('X');
    visited['X'] = true;
    while (!q.empty()) {
        char curr = q.front();
        if (curr=='Y') {
            break;
        }
        q.pop();
        for1(i,0,E[curr].size()) {
            char next = E[curr][i].first;
            if (!visited[next]) {
                printf("%c %c %.1f\n",curr,next,res[mp(curr,next)]);
                q.push(next);
                visited[next] = true;
            }
        }

    }



    printf("%.1f",sum/2.0);


	return 0;
}
