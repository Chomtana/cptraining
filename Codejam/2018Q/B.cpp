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

/*void tsort(vector<int> &L) {
    bool done = false;
    while (!done) {
        done = true;
        for(int i = 0;i<L.size()-2;i++) {
            if (L[i]>L[i+2]) {
                done = false;
                swap(L[i],L[i+2]);
            }
        }
    }
}*/

int check(vector<int> &a) {
    int res = 0;
    for1(i,0,a.size()-1) {
        if (a[i]>a[i+1]) {
            return i;
        }
    }
    return -1;
}

int ceil2(int n) {
    return (n%2==0?n/2:n/2+1);
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int t; cin>>t; for1(_,1,t+1) {
        printf("Case #%d: ",_);
        int n; scanf("%d",&n);
        vector<int> a1;
        vector<int> a2;
        for1(i,0,n) {
            int x;
            scanf("%d",&x);
            if (i%2==0) a1.push_back(x); else a2.push_back(x);
        }
        sort(all(a1)); sort(all(a2));


        vector<int> a(n,0);
        for1(i,0,a1.size()) {
            a[2*i] = a1[i];
        } 
        for1(i,0,a2.size()) {
            a[2*i+1] = a2[i];
        } 

        //for1(i,0,a.size()) printf("%d ",a[i]); printf("\n");


        //(not correct) observe fail: if it not ok -> check(a) = check(tsort(a)) (index of error in tsort array is as same as index of error in original array)
        //observe : it will split into 2 array : because bubble sort swap a[i],a[i+1] a[i+1],a[i+2] ... but this swap a[i],a[i+2] then a[i],a[i+2] a[i+2],a[i+4] belong to same array
        //above observe is picture reforming technique (illustrate in B.jpg)
        int res = check(a);
        if (res==-1) printf("OK\n"); else printf("%d\n",res);
    }
	return 0;
}
