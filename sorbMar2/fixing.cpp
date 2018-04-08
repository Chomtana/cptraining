#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n,m,k;
int ss,ee;
int A[100005];
deque<int> S;
int Ssum = 0;

int main() {
    cin>>n>>m>>k;
    k--;
    for1(i,0,m) {
        scanf("%d",A+i);
        ss = min(ss,A[i]);
        ee = max(ee,A[i]);
    }
    for1(i,1,m) {
        int space = A[i]-A[i-1]-1;
        Ssum += space;
        if (space>0) {
            S.push_back(space);
        }
    }
    
    sort(all(S),greater<int>());
    while(S.size()>0 && k--) {
        Ssum -= S[0];
        S.pop_front();
    }
    
    cout<<Ssum;
    return 0;
}