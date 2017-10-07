#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll dp[100][100];
bool visited[100][100];

//ll c;
ll trib(int n, unsigned int back)
{
    ll sum=0;
    int i;
    //c++;
    if(n<=0) return 1;
    if(n==1) return 1;
    if(visited[n][back]) return dp[n][back];
    visited[n][back] = true;
    for(i=1;i<=back;i++)
    sum+=trib(n-i,back);
    return dp[n][back] = sum+1;
}
int main()
{
    int n,m;
    int _=1;
    while (cin>>n>>m,n<=60) {
        memset(dp,0,sizeof(dp));
        memset(visited,false,sizeof(visited));
        //c=0;
        ll c=trib(n,m);
        printf("Case %d: %I64u\n",_++,c);
    }
    return 0;
}
