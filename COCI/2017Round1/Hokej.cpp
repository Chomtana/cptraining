#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define mt make_tuple
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> piii;
typedef vector<int> vi;

int m,n;
piii data[500005];
int starter[10];
int curr[10];
vector<piii> sub;
ll res = 0;
int nextplayer = 7;

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>m>>n;
    for1(i,1,n+1) {
        int k,s; scanf("%d%d",&k,&s);
        data[i] = mt(k,s,i);
    }

    sort(data+1,data+n+1,greater<piii>());

    for1(i,1,7) {
        int k,s,j; tie(k,s,j) = data[i];
        //cerr<<"aaa "<<k<<' '<<s<<' '<<j<<endl;
        starter[i] = j;
        curr[i] = i;
        //res += (ll)k;
    }

    for1(i,1,m+1) {
        for1(j,1,7) {
            int k,s,oldi; tie(k,s,oldi) = data[curr[j]];
            res += (ll)k;
            if (i==m) continue;
            if (s==i) {
                int& news = get<1>(data[nextplayer]);
                sub.emplace_back(i,oldi,get<2>(data[nextplayer]));
                //printf("%d %d %d\n",i,oldi,get<2>(data[nextplayer]));
                news = news+i;
                //cerr<<news<<endl;
                curr[j] = nextplayer++;
            }
        }
    }

    //printf("\n");
    cout<<res<<endl;
    for1(i,1,7) {
        printf("%d ",starter[i]);
    }
    printf("\n%d\n",sub.size());
    for1(i,0,sub.size()) {
        int a,b,c; tie(a,b,c) = sub[i];
        printf("%d %d %d\n",a,b,c);
    }
	return 0;
}
