#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args
#define mn(a,b,c) mp(a,mp(b,c))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<bool,pair<int,int>> nodetype; //T = L,F = R

ll k,n;

nodetype data[500005];
vector<string> cache;

void docache() {
    string s = "";
    for1(i,1,n+1) {
        s += (data[i].first?'L':'R');
    }
    cache.push_back(s);
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>k>>n;
    for1(i,0,n) {
        char cs[3]; int l,r; scanf("%s%d%d",cs,&l,&r);
        char c = cs[0];
        data[i+1] = mn((c=='L'?true:false),l,r);
    }

    /*for1(i,1,n+1) {
        printf("%c",(data[i].first?'L':'R'));
    }
    printf("\n");*/

    docache();

    //bf
    for1(_,0,k) {

        int curr = 1;
        while (curr!=0) {
            if (data[curr].first) {
                data[curr].first = !data[curr].first;
                curr = data[curr].second.first;
            } else {
                data[curr].first = !data[curr].first;
                curr = data[curr].second.second;
            }


        }

        docache();
        if (cache.back()==cache[0]) {

        }

        for1(i,1,n+1) {
            printf("%c",(data[i].first?'L':'R'));
        }
        printf("\n");
    }

    for1(i,1,n+1) {
        printf("%c",(data[i].first?'L':'R'));
    }
	return 0;
}
