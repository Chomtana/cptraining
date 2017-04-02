#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int w,h,n; scanf("%d %d %d",&w,&h,&n);
    int data[w];
    for1(i,0,w) data[i] = 0;
    for1(i,0,n) {
        int start,len; scanf("%d %d",&start,&len);
        for1(i,start,start+len) {
            if (i>=w) break;
            data[i]++;
        }

    }

    int count50 = 0;
    int count100 = 0;
    for1(i,0,w) {
        count50 += (data[i]==1);
        count100 += (data[i]==0);
    }

    cout<<count100*h<<' '<<count50*h;

	return 0;
}
