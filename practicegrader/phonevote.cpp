//#include <bits/stdc++.h>
#include <unordered_map>
#include <iostream>
#include <stdio.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
/*typedef pair<int,int> pii;
typedef vector<int> vi;*/

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int t,n,k; scanf("%d %d %d",&t,&n,&k);
    unordered_map<ll,int> count;
    int vote[n+1];
    for1(i,1,n+1) {
        vote[i] = 0;
    }

    while(t--) {
        ll tel; int v; scanf("%lld %d",&tel,&v);
        //cout<<count[tel]<<endl;
        if (count[tel]<k) {
            count[tel]++;
            if (v>=1 && v<=n) {
                vote[v]++;
            }
        }
    }

    for1(i,1,n+1) {
        printf("%d\n",vote[i]);
    }

	return 0;
}
