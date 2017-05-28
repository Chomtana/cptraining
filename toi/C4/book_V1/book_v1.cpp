/*
Critical case:
This problem case insensitive
But c++ function case sensitive (use ascii table for compare multi case)
-> must tolower or toupper before calculate
*/

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

//fenwick tree
int n;
vector<int> ftree; //nen yum -> fenwick tree index must start at 1 ... segment tree is same index must start at 1 then [ i/2 <- i -> (2i,2i+1) ]

void add(int t,int a) {
    for(int i = t;i<=n;i+=i&(-i)) {
        ftree[i] += a;
    }
}

int query(int e) { //s==0
    int res = 0;
    for(int i = e;i>0;i-=i&(-i)) {
        res += ftree[i];
    }
    return res;
}

int query(int s,int e) {
    if (s==1) return query(e); else return query(e)-query(s-1);
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;

    cin>>n; ftree.resize(n+1,0);

    vector<string> data(n);
    vector<string> datasort(n);
    vector<int> ftsingle(n+1,0);
    for1(i,0,n) {
        char sraw[25]; scanf("%s",sraw);
        data[i] = string(sraw);
        transform(all(data[i]),data[i].begin(),::tolower);
        datasort[i] = data[i];
    }
    sort(all(datasort));

    for1(i,0,n) {
        int datasorti = lower_bound(all(datasort),data[i])-datasort.begin();
        while (ftsingle[datasorti+1]==1) {
            datasorti++;
        }
        add(datasorti+1,1);
        ftsingle[datasorti+1] = 1;
        printf("%d\n",query(datasorti+1));
    }


	return 0;
}
