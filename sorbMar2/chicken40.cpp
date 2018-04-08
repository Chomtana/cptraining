#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n,m,k;
int Araw[100005];
vector<int> A;

int mymax = 0;
int my = 0;
vector<pii> myp;

bool check(int mid) {
    for1(x,0,n-m+1) {
        //int xs = myp[x].first;
        //int xe = myp[x].second;
        int xs = x;
        int xe = x+m-1;
        
        int currsum = 0;
        int currk = 1;
        int sz = 0;
        bool ok = true;
        for1(i,0,n) { //n = n-m (size of A)
            if (i<xs || i>xe) {
                currsum += A[i];
                sz++;
                if (A[i]>mid) {
                    ok = false;
                    break;
                }
                if (currsum>mid || sz>m) {
                    currsum = A[i];
                    currk++;
                    sz=1;
                }
                if (currk>k) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok && currk<=k) return true;
    }
    return false;
}

int main() {
    cin>>n>>m>>k;
    for1(i,0,n) {
        scanf("%d",Araw+i);
        A.push_back(Araw[i]);
    }
    
    for1(i,0,m) {
        my += Araw[i];
    }
    mymax = my;
    for1(i,1,n-m+1) {
        my -= Araw[i-1];
        my += Araw[i+m-1];
        if (my>mymax) {
            mymax = my;
            myp.clear();
            myp.emplace_back(i,i+m-1);
        } else if (my==mymax) {
            myp.emplace_back(i,i+m-1);
        }
    }
    
    k--;
    
    /*for1(i,0,myp.size()) {
        cerr<<myp[i].first<<' '<<myp[i].second<<endl;
    }*/
    
    /*for1(i,0,n) {
        if (i<myp[0].first || i>myp[0].second) {
            A.push_back(Araw[i]);
        }
    }
    
    n -= m;*/
    
    int l = 0; int r = 1e9+5;
    while (l<=r) {
        int mid = (l+r)/2;
        if (check(mid)) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    
    /*for1(i,0,n) {
        cerr<<A[i]<<' ';
    }
    cerr<<endl;*/
    
    cout<<l;
    return 0;
}