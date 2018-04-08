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

int n;
int data[20010];
//bool marked[10005];

ll h1b = 12777;
ll h1bp[10005];

bool check(int size) {
    if (size==0) return false;
    
    //cerr<<size<<" : ";
    
    ll h1 = 0;
    
    for1(i,0,size) {
        h1 *= h1b;
        h1 += data[i];   
    }
    
    //cerr<<h1<<' ';
    
    set<ll> ht;
    ht.insert(h1);
    
    for1(i,1,n) {
        h1 -= data[i-1]*h1bp[size-1];
        h1 *= h1b;
        h1 += data[i+size-1];
        
        //cerr<<h1<<' ';
        
        if (ht.find(h1) != ht.end()) {
            return false;
        }
        ht.insert(h1);
    }
    //cerr<<endl;
    return true;
}

int main() {
    //ios::sync_with_stdio(false);
    cout<<fixed;
    cin>>n;
    for1(i,0,n) scanf("%d",data+i);
    for1(i,n,2*n) {
        data[i] = data[i-n];
    }
    
    bool hasans = false;
    for1(i,1,n) if (data[i]!=data[i-1]) {
        hasans = true;
        break;
    }
    if (!hasans) {
        cout<<-1; return 0;
    }
    
    h1bp[0] = 1;
    for1(i,1,10005) {
        h1bp[i] = h1bp[i-1]*h1b;
    }

    int l = 0; int r = n;
    while (l<=r) {
        int mid = (l+r)/2;
        
        if (check(mid)) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    //cerr<<"aaa "<<check(1)<<endl;
    if (l>=n) {
        cout<<-1; return 0;
    }
    cout<<l-1;
    return 0;
}

/*
(Not this) Read problem again it say in some point we don't need exactly <size> (OK Correct)
Edge case : no ans case (case that need to go exactly n has no ans ... it has other than 1 1 1 1)
Train : very few case but all part then no ans edge case ... fix by determine other way to see if it has no ans
*/