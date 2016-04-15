#include <bits/stdc++.h>

#define for1(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define for2(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define for3(i,a,b,c) for(int (i)=(a);(i)<(b);(i)+=(c))
#define for4(i,a,b,c) for(int (i)=(a)-1;(i)>=(b);(i)-=(c))
#define debugv1(v) for1(_____,0,v.size()) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv2(v,size) for1(_____,0,size) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv3(v,s,e) for1(_____,s,e) cout<<(v)[_____]<<' '; cout<<endl;

using namespace std;

int main() {
    //cout<<fixed;
    //ios::sync_with_stdio(false);
    int t; scanf("%d",&t);
    priority_queue<int> pq;
    while (t--)  {
        //cin.clear();
        char c; scanf(" %c",&c);
        switch (c) {
            case 'P':
                int n; scanf("%d",&n);
                pq.push(n);
                break;
            case 'Q':
                if (pq.empty()) {
                    printf("-1\n"); break;
                }
                printf("%d\n",pq.top());
                pq.pop();
                break;
        }
        
    }
    return 0;
}