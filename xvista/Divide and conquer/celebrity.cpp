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
int data[1005][1005];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	cin>>n;
    for1(i,0,n) for1(j,0,n) scanf("%d",&data[i][j]);
    int tr = -1;
    for1(i,0,n) {
        bool find1 = false;
        for1(j,0,n) {
            if(data[i][j]==1) {
                find1=true;
                break;
            }
        }
        if (!find1) {
            if (tr==-1) {
                tr = i;
            } else {
                cout<<0;
                return 0;
            }

        }
    }

    for1(j,0,n) { //always i = row , j = col -> in loop use meaning
        bool ok = true;
        for1(i,0,n) {
            if(i!=j) {
                if(data[i][j]!=1) {
                    ok=false;
                    break;
                }
            }
        }
        if (ok) {
            cout<<1; return 0;
        }
    }

    cout<<0;

	return 0;
}
