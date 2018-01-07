#include <stdio.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef long double ld;
//typedef pair<int,int> pii;
//typedef vector<int> vi;

const int fwsize = 1<<20;

int data[(1<<20)+5];

void update(int p,int val) {
    for(int i = p;i<=fwsize;i+=(i&-i)) {
        data[i] += val;
    }
}

int query(int p) {
    int res = 0;
    for(int i = p;i>=1;i-=(i&-i)) {
        res += data[i];
    }
    return res;
}

int bs(int val) {
    int l = 1,r= fwsize;
    int cache = 0;
    while (l<=r) {
        int mid = (l+r)/2;
        //cerr<<mid<<' '<<data[mid]<<endl;
        //if (cache+data[mid]==val) return mid;
        if (cache+data[mid]<val) {
            cache += data[mid];
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    if (l>1000000) return -1;
    return l;
}

int bs(int s,int val) {
    return bs(query(s-1)+val);
}

int n,k;

int main() {
	//ios::sync_with_stdio(false);
	//cout<<fixed;
	//cout<<(1<<20);
    //cin>>n>>k;
    scanf("%d%d",&n,&k);
    int c = 1;
    int remaink = k;

    for1(i,1,n+1) {
        update(i,1);
    }

    //cerr<<bs(10,2)<<endl;

    for1(_,0,n-1) {
        int oldc = c;
        c = bs(c,remaink);
        //cerr<<c<<' ';
        if (c==-1) {
            int queryn = query(n);
            if (oldc==1 && remaink>queryn) {
                remaink %= queryn;
                if (remaink==0) remaink=queryn;
                _--;
                continue;
            }
            c = oldc;
            remaink -= queryn-query(c-1);
            _--;
            c = 1;
            continue;
        }

        update(c,-1);
        c++;
        remaink = k;
    }

    //cerr<<endl;

    printf("%d",bs(1));
	return 0;
}
