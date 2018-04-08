#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

int n,m,k;
int Araw[100005];
vector<int> A;

int mymax = 0;
int my = 0;
vector<pii> myp;

bool check(int mid) {
    //for1(x,0,myp.size()) {
        //int xs = myp[x].first;
        //int xe = myp[x].second;
        //int xs = x;
        //int xe = x+m-1;
        int xs = 1e9;
        int xe = -1;
        
        vector<pii> G;
        vector<int> Gc;
        
        int currsum = 0;
        int currk = 1;
        int sz = 0;
        bool ok = true;
        int cheat = 0;
        int totalcheat = 0;
        for1(i,0,n) { //n = n-m (size of A)
            if (i<xs || i>xe) {
                currsum += A[i];
                sz++;
                /*if (A[i]>mid) {
                    ok = false;
                    break;
                }*/
                if (currsum>mid || sz>m) {
                    currsum = A[i];
                    G.emplace_back(i-sz+1,i-1);
                    Gc.push_back(cheat);
                    cheat = 0;
                    currk++;
                    sz=1;
                    
                }
                if (A[i]>mid) {
                    cheat++;
                    totalcheat++;
                }
                /*if (currk>k) {
                    ok = false;
                    break;
                }*/
            }
        }
        G.emplace_back(n-sz,n-1);
        
        printf("%d : ",mid);
        for1(i,0,G.size()) {
            printf("(%d,%d) %d ",G[i].first,G[i].second,Gc[i]);
        }
        
        
        if (currk<=k && totalcheat==0) return true;
        
        currk++;

        int currsz = 0;
        int i = 0;
        while(i<G.size() && currsz<=m) {
            currsz += G[i].second-G[i].first+1;
            totalcheat -= Gc[i];
            currk--;
            i++;
        }
        i--;
        currsz -= G[i].second-G[i].first+1;
        totalcheat += Gc[i];
        currk++;
        if (totalcheat==0 && currk<=k) return true;
        
        printf("currsz=%d currk=%d totalcheat=%d",currsz,currk);
        printf("\n");
        
        for1(j,1,G.size()) {
            currsz -= G[j-1].second-G[j-1].first+1;
            totalcheat += Gc[j-1];
            currk++;
            
            if (j>i) return false;
            
            while(currsz<=m) {
                currsz += G[i].second-G[i].first+1;
                totalcheat -= Gc[i];
                currk--;
                if (j>i) return false;
                i++;
                if (j>i) return false;
            }
            i--;
            if (j>i) return false;
            currsz -= G[i].second-G[i].first+1;
            totalcheat += Gc[i];
            currk++;
            if (totalcheat==0 && currk<=k) return true;
        }

        if (ok && currk<=k) return true;
    //}
    return false;
}

int main() {
    cin>>n>>m>>k;
    for1(i,0,n) {
        scanf("%d",Araw+i);
        A.push_back(Araw[i]);
    }
    
    //vector<piii> S;
    
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
    
    //k--;
    
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