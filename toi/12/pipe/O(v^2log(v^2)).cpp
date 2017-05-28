#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>

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
typedef pair<int,pii> piii;

pii data[15005];
int minw[15005];
//vector<int> select; //xvista grader bug
bool visited[15005];

int D(pii &a,pii &b) {
    return abs(a.first-b.first)+abs(a.second-b.second);
}

struct djnode {
    int parent;
    int rank = 0;
};

djnode djset[15005];

int find(int i) {
    if (djset[i].parent==i) return i;
    return djset[i].parent = find(djset[i].parent);
}

void un(int a,int b) {
    a = find(a);
    b = find(b);
    if (djset[a].rank<djset[b].rank) {
        djset[a].parent = b;
        djset[b].rank++;
    } else {
        djset[b].parent = a;
        djset[a].rank++;
    }
}

int main() {
    vector<int> select; //declear here instead
    priority_queue<piii,vector<piii>,greater<piii>> pq;

	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n,k; cin>>n>>k;
    select.reserve(n+5);
    for1(i,0,n) {
        scanf("%d%d",&data[i].first,&data[i].second);
    }

    for1(i,0,n+5) djset[i].parent = i;

    for1(i,0,n) {
        for1(j,0,n) {
            pq.push(mp(D(data[i],data[j]),mp(i,j)));
        }
    }

    fill(minw,minw+n+5,1E9);
    for1(i,0,n+5) visited[i] = false;

    while(!pq.empty()) {
        int currs = pq.top().second.first;
        int curre = pq.top().second.second;
        int w = pq.top().first;
        pq.pop();

        if (find(currs)!=find(curre)) {
            select.push_back(w);
            un(currs,curre);
        }
    }

    /// complete graph only
    /*int curr = 0;
    minw[curr] = 0;
    visited[curr] = true; //set visited before run
    for1(_,0,n-1) { //do v-1 times
        int next = -1; //next=curr for next loop = index of node that has min weight and not visited
        int currmin = 1E9;
        for1(i,0,n) {
            int w = D(data[curr],data[i]); //w of (curr,next)
            if (!visited[i]) { //if next not visited and w(curr,next) < w(next) that current cached (from loop before)
                if (w<minw[i]) {
                    minw[i] = w; //update weight to better weight
                }
                if (minw[i]<currmin) {
                    currmin = minw[i];
                    next = i;
                }
            }
        }

        select.push_back(mp(curr,next)); //we select (curr,next)
        visited[next] = true; //set visited before run
        curr = next; //update curr for next loop (curr of next loop = next of curr loop)
    }*/

    /*sort(all(select),[](const pii &a,const pii &b) { //g++ 4.8 cannot compile without const (start at 4.9 can compile)
        return D(data[a.first],data[a.second]) > D(data[b.first],data[b.second]); //sort by distance > -> return distance(a) > distance(b)
    });*/

    sort(all(select),greater<int>());

    int res = 0;
    int startadd = k-1;

    for1(i,startadd,select.size()) {
        res += select[i];
        //cerr<<select[i].first<<' '<<select[i].second<<endl;
    }

    cout<<res;

	return 0;
}
