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
int data[100005];
int qs[100005];

int query(int s,int e) {
    return qs[e]-(s>0?qs[s-1]:0);
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	cin>>n;
    for1(i,0,n) {
        scanf("%d",data+i);
        if(i==0) qs[i]=data[i]; else qs[i]=qs[i-1]+data[i];
    }

    //2 part
    for1(i,0,n-1) {
        if (query(0,i)==query(i+1,n-1)) {
            cout<<i+1<<endl;
            return 0;
        }
    }

    //3part
    for1(i,0,n-1) {
        int sum = query(0,i);

        int l = 0;int r = n-2;
        int res = 1E9;
        while(l<=r) {
            int mid = (l+r)/2;

            int sum2 = query(i+1,mid);

            if (sum2==sum+query(mid+1,n-1)) {
                res = mid;
                break;
            } else if (sum2<sum+query(mid+1,n-1)) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        //cerr<<sum<<' '<<res<<endl;
        if (res!=1E9) {
            cout<<i+1<<' '<<res+1<<endl;
            return 0;
        }
    }

    cout<<"NO";
	return 0;
}
