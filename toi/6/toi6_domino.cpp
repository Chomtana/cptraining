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
    for1(i,0,(1<<n)) {
        vector<int> currselect;
        for2(j,n-1,0) {
            currselect.push_back(i&(1<<j));
        }
        currselect.push_back(0);
        bool ok = true;
        string res = "";
        for1(j,0,n) {
            if (currselect[j]) {
                if (!currselect[j+1]) {
                    ok = false;
                    break;
                } else {
                    res += "||\n";
                    j++;
                }
            } else {
                res += "--\n";
            }
        }

        if (!ok) {
            continue;
        } else {
            /*if (!currselect.back()) {
                res += "--\n";
            }*/
            printf("%s",res.c_str());
            printf("E\n");
        }
    }
    return 0;
}
