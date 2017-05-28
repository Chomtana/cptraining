#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n; scanf("%d",&n);
    pii data[n];
    for1(i,0,n) {
        scanf("%d%d",&data[i].first,&data[i].second);
    }
    sort(data,data+n);
    int minres = 1E9;
    do {
        int startbath[n];
        int toilet = 0;
        for1(i,0,n) {
            toilet += data[i].first;
            startbath[i] = toilet;
        }
        int bath = 0;
        for1(i,0,n) {
            if (startbath[i]>bath) {
                bath = startbath[i]+data[i].second;
            } else {
                bath += data[i].second;
            }
        }

        /*cout<<bath<<endl;
        minres = min(minres,bath);
        for1(i,0,n) {
            cout<<data[i].first<<' '<<data[i].second<<' '<<data[i].first+data[i].second<<endl;
        }
        cout<<endl;*/
    } while (next_permutation(data,data+n));

    cout<<minres;
	return 0;
}
