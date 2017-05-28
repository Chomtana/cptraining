#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

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

pii data[15005];
int minw[15005];
vector<int> select; //xvista grader bug
bool visited[15005];

int D(pii &a,pii &b) {
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int main() {
    //vector<int> select; //declear here instead

	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n,k; cin>>n>>k;
    select.reserve(n+5);
    for1(i,0,n) {
        scanf("%d%d",&data[i].first,&data[i].second);
    }

    fill(minw,minw+n+5,1E9);
    for1(i,0,n+5) visited[i] = false;

    /// complete graph only
    int curr = 0;
    minw[curr] = 0;
    visited[curr] = true; //set visited before run
    for1(_,0,n-1) { //do v-1 times = select v-1 edge in prim
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

        if (next!=-1) { //if next==-1 it will push_back w(curr,-1) -> wrong answer
            //select.push_back(mp(curr,next)); //fail here
            select.push_back(currmin); //we want min(minw) not w(curr,next) because if we choose path not from curr ... in visualization it will add that edge (edge that has minw) -> must add min(minw)=currmin
            visited[next] = true; //set visited before run
            curr = next; //update curr for next loop (curr of next loop = next of curr loop)
        }
    }

    /*sort(all(select),[](const pii &a,const pii &b) { //g++ 4.8 cannot compile without const (start at 4.9 can compile)
        return D(data[a.first],data[a.second]) > D(data[b.first],data[b.second]); //sort by distance > -> return distance(a) > distance(b)
    });*/

    sort(all(select),greater<int>());

    int res = 0;
    int startadd = k-1;

    for1(i,startadd,select.size()) {
        //res += D(data[select[i].first],data[select[i].second]);
        res += select[i];
        //cerr<<select[i].first<<' '<<select[i].second<<endl;
    }

    cout<<res;

	return 0;
}
