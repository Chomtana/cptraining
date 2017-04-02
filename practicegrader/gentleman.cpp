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
	int n; cin>>n;
	string s; cin>>s;
    int swapcount = 0;
    int round = 0;
    do {
        swapcount = 0;
        for1(i,0,n-1) {
            if (s[i]=='M') {
                if (s[i+1]=='F') {
                    swap(s[i],s[i+1]);
                    i++;
                    swapcount++;
                }
            }
        }
        if (swapcount>0) round++;
    } while (swapcount > 0);

    cout<<round;
	return 0;
}
