#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(a,b,c) for(int (a)=(b);((b)<(c)?(a)<(c):(a)>=(c));a+=((b)<(c)?1:-1))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
    int t; cin>>t;
    while (t--) {
        int n,m; scanf("%d %d",&n,&m);
        priority_queue<int> getter;
        priority_queue<int,vector<int>,greater<int>> q;
        int data[n]; for1(i,0,n) scanf("%d",data+i);
        int curr = 0;
        int cg = 1;
        while (m--) {
            int pos; scanf("%d",&pos);
            pos--;
            while (curr<=pos) {
                q.push(data[curr]);
                curr++;
            }

            stack<int> temp;
            while (!q.empty()) {
                int c = q.top();
                q.pop();

                if (getter.size()<cg) {
                    getter.push(c);
                } else {
                    if (c>=getter.top()) {
                        temp.push(c);
                    } else {
                        temp.push(getter.top());
                        getter.pop();
                        getter.push(c);
                    }
                }
            }

            while (!temp.empty()) {
                q.push(temp.top());
                temp.pop();
            }

            printf("%d\n",getter.top());

            cg++;
        }

        printf("\n");
    }

    return 0;
}
