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

typedef vector<int> set2;

int data[15];
vector<int> curr;
int n,t;
int sum = 0;
set<set2,greater<set2>> res;

void p(set2 p) {
    bool first = true;
    for(int i:p) {
        if (!first) {
            printf("+");
        }
        printf("%d",i);
        first = false;
    }
    printf("\n");
}

void pold() {
    bool first = true;
    for(int i:curr) {
        if (!first) {
            printf("+");
        }
        printf("%d",i);
        first = false;
    }
    printf("\n");
}

void bt(int pos) {
    if (sum>t) return;
    if (sum==t) {
        //pold();
        vector<int> v(all(curr));
        sort(all(v),greater<int>());
        res.insert(v);
        return;
    }
    if (pos>=n) {
        if (sum==t) {
            //pold();
            vector<int> v(all(curr));
            sort(all(v),greater<int>());
            res.insert(v);
        }
        return;
    }

    bt(pos+1);

    sum += data[pos];
    curr.push_back(data[pos]);
    bt(pos+1);
    sum -= data[pos];
    curr.pop_back();
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    while(cin>>t , t!=0) {
        scanf("%d",&n);
        curr.clear();
        res.clear();
        for1(i,0,n) {
            scanf("%d",data+i);
        }

        printf("Sums of %d:\n",t);
        bt(0);

        if (res.size()==0) printf("NONE\n");

        for (auto it = res.begin();it!=res.end();it++) {
            p(*it);
        }

    }
	return 0;
}
