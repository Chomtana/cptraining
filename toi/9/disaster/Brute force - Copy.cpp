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

vector<vector<int>> E(26);
vector<pii> Elist;

stack<int> res;
bool instack[301]; //auto init
bool visited[301];
int stackcount = 0;
int n;

bool dfs(int curr) {
    bool hasnext = false;

    for1(i,0,E[curr].size()) {
        int next = E[curr][i];
        if (!instack[next]) {
            hasnext = true;
            int nextv = (Elist[next].first==curr?Elist[next].second:Elist[next].first);
            stackcount++;
            instack[next] = true;
            if (dfs(nextv)) {
                res.push(curr);
                return true;
            }
            instack[next] = false;
            stackcount--;
        }
    }

    int judgecount = stackcount;

    if (!hasnext) {
        if (judgecount == n) {
            res.push(curr);
            return true;
        } else {
            return false;
        }
    }

    return false;

}

void dfs2(int curr) {
    for1(i,0,E[curr].size()) {
        int next = E[curr][i];
        if (!visited[next]) {
            dfs2(next);
            visited[next] = true;
        }
    }


}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n;
    int start = 0;
    for1(i,0,n) {
        char in[4];
        scanf("%s",in);
        Elist.push_back(mp(in[0]-'A',in[1]-'A'));
        E[in[0]-'A'].push_back(Elist.size()-1);
        E[in[1]-'A'].push_back(Elist.size()-1);
        start = in[0]-'A';
    }

    for1(i,0,26) {
        if(E[i].size()%2==1) {
            start = i;
            break;
        }
    }

    dfs(start);

    while (!res.empty()) {
        printf("%c ",res.top()+'A');
        res.pop();
    }

    dfs2(0);


	return 0;
}
