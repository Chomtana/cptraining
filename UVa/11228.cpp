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
typedef pair<double,int> pdi;
typedef vector<int> vi;

struct djnode {
    int parent;
    int rank = 0;
};

djnode djset[1005];

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

double dist(int deltax,int deltay) {
    double ab = deltax*deltax+deltay*deltay;
    return sqrtl(ab);
}



int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t;
    for1(_,1,t+1) {
        int n,r; scanf("%d%d",&n,&r);
        pii data[n];
        for1(i,0,n) {
            scanf("%d%d",&data[i].first,&data[i].second);
            djset[i].parent = i;
        }

        //do group
        for1(i,0,n) {
            for1(j,i+1,n) {
                double d = dist(abs(data[j].first-data[i].first),abs(data[j].second-data[i].second));
                if (d<=double(r)) {
                    un(i,j);
                }
            }
        }

        //do mst
        double road = 0;
        double rail = 0;
        double cost[n]; //cost[i] = min edge weight connect to node i
        bool visited[n];
        for1(i,0,n) {
            cost[i] = 1E9;
            visited[i] = false;
        }
        //priority_queue<pdi,vector<pdi>,greater<pdi>> q; //special case emst = complete graph can calculate min in next step
        //q.push(mp(0,0));
        double currmin = 0; //weight of curr selection
        int mini = 0;
        cost[0] = 0;
        while (mini!=-1) {
            //q.pop();

            double nextcurrmin = 1E9;
            int nextmini = -1;

            for1(i,0,n) {
                if (i!=mini) {
                    double nextw = dist(abs(data[mini].first-data[i].first),abs(data[mini].second-data[i].second));
                    if (nextw < cost[i]) {
                        cost[i] = nextw;
                    }
                }
            }

            for1(i,0,n) {
                if (!visited[i]) {
                    if (cost[i]<nextcurrmin) {
                        nextcurrmin = cost[i];
                        nextmini = i;
                    }
                }
            }


            if (nextmini==-1) break;

            if (find(mini) == find(nextmini)) {
                road += nextcurrmin;
            } else {
                rail += nextcurrmin;
            }

            currmin = nextcurrmin;
            mini = nextmini;
            visited[mini] = true;

        }

        //do count group;
        set<int> state;
        for1(i,0,n) {
            state.insert(find(i));
        }

        printf("Case #%d: %d %.lf %.lf\n", _, state.size(), road, rail);
    }
	return 0;
}
