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

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n; cin>>n;
    int data[n]; for1(i,0,n) scanf("%d",data+i);

    int dist[n];
    fill(dist,dist+n,1E9);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        int c = q.front();
        q.pop();

        int ne1 = c+1;
        int ne2 = c+data[c];
        if(ne1<n&&dist[ne1]==1E9) {
            dist[ne1] = dist[c]+1;
            q.push(ne1);
        }
        if(ne2<n&&dist[ne2]==1E9) {
            dist[ne2] = dist[c]+1;
            q.push(ne2);
        }
    }

    //if (dist[er][ec]==1E9) cout<<-1; else
    cout<<dist[n-1];
	return 0;
}
