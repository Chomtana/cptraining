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
int a[20];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n;
    for1(i,0,20) a[i]=4;
    a[10] = 16;

    int sum = 0;
    for1(i,0,n) {
        int x; scanf("%d",&x);
        a[x]--;
        sum += x;

    }

    int d = 21-sum;

    int gt = 0;
    for1(i,d+1,12) gt+=a[i];
    int lt = 0;
    for1(i,2,d+1) lt+=a[i];

    //cerr<<d<<' '<<gt<<' '<<lt<<endl;

    if (gt>=lt) cout<<"DOSTA"; else cout<<"VUCI";
	return 0;
}
