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
    int n;
    bool End = false;
    while (cin>>n,n!=0) {
        if (End) printf("\n");
        End = true;
        int data[n];
        for1(i,0,n) {
            scanf("%d",&data[i]);
        }
        sort(data,data+n);
        int j = 0;
        vector<vector<int>> res(n);
        res[j].push_back(data[0]); j++;
        int maxj = 1;
        for1(i,1,n) {
            if (data[i]==data[i-1]) {
                res[j].push_back(data[i]);
                j++;
                maxj = max(maxj,j);
            } else {
                j = 0;
                res[j].push_back(data[i]);
                j++;
            }
        }

        // I think
        printf("%d\n",maxj);
        for1(i,0,maxj) {
            for1(k,0,res[i].size()) {
                printf("%d ",res[i][k]);
            }
            printf("\n");
        }

        //sol think
        /*for1(i,0,maxj) {
            for(int k = i;k<n;k+=maxj) {
                printf("%d ",data[k]);
            }
            printf("\n");
        }*/
        //printf("\n");
    }
	return 0;
}
