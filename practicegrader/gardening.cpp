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
    int n,m; cin>>n>>m;
    int sumwage = 0;
    int maxwage = -1;
    int minwage = 1E9;
    int maxi = -1;
    int mini = -1;
    int wage[n];
    fill(wage,wage+n,0);
    for1(i,0,m) {
        for1(j,0,n) {
            int w; cin>>w;
            if (w>=10) {
                wage[j] += 400;
            } else {
                wage[j] += w*40;
            }
        }

    }

    for1(i,0,n) {
        sumwage += wage[i];
        if (wage[i]>maxwage) {
            maxwage = wage[i];
            maxi = i;
        }
        if (wage[i]<minwage) {
            minwage = wage[i];
            mini = i;
        }
    }

    cout<<sumwage<<endl<<maxi+1<<endl<<mini+1;
	return 0;
}
