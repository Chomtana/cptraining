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
	vector<int> data;
	int n;
	//int t = 8;
    while (scanf("%d",&n)!=EOF/*,t--*/) {
        //cerr<<n<<endl;
        data.push_back(n);
    }

    //for1(i,0,data.size()) cout<<data[i]<<endl;

    int bf[data.size()];
    int l[data.size()]; //LIS(0,...) force end
    l[0] = 1;
    bf[0] = -1;

    for1(i,1,data.size()) {
        int currmax = 0;
        bf[i] = -1;
        for1(j,0,i) {
            if (data[j]<data[i]) {
                if (l[j]>=currmax) {
                    currmax = l[j];
                    bf[i] = j;
                }
            }
        }
        l[i] = currmax+1;
    }

    int maxi = 0;
    int currmax = 0;
    for1(i,0,data.size()) if ( l[i]>=currmax) {
        currmax= l[i]; maxi=i;
    }

    int curr = maxi;
    stack<int> res;
    while (curr>=0) {
        res.push(data[curr]);
        curr = bf[curr];
    }
    //res.push(data[0]);

    printf("%d\n-\n",res.size());

    while (!res.empty()) {
        printf("%d\n",res.top());
        res.pop();
    }

	return 0;
}
