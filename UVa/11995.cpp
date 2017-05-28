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
    int t;
    while (cin>>t) {
        stack<int> st;
        queue<int> q;
        priority_queue<int> pq;
        bool isst = true;
        bool isq = true;
        bool ispq = true;
        while (t--) {
            int qu,n; scanf("%d%d",&qu,&n);
            if (qu==1) {
                if (isst) st.push(n);
                if (isq) q.push(n);
                if (ispq) pq.push(n);
            } else {
                if (isst) {
                    if (st.empty() || st.top()!=n) isst = false; else st.pop();
                }
                if (isq) {
                    if (q.empty() || q.front()!=n) isq = false; else q.pop();
                }
                if (ispq) {
                    if (pq.empty() || pq.top()!=n) ispq = false; else pq.pop();
                }
            }
        }

        int c = isst+ispq+isq;
        if (c==0) {
            printf("impossible\n");
            continue;
        } else if (c>1) {
            printf("not sure\n");
            continue;
        } else {
            if (isst) {
                printf("stack\n");
            } else if (isq) {
                printf("queue\n");
            } else {
                printf("priority queue\n");
            }
        }
    }
	return 0;
}
