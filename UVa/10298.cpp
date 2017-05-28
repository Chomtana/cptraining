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

int P[1000005];

string s;

void kmpprefix() {
    int j = 0;
    for1(i,1,s.size()) {
        while (j>0 && s[i]!=s[j]) {
            j = P[j-1];
        }
        if (j==0) {
            if (s[i]==s[j]) {
                P[i] = ++j;
            } else {
                P[i] = 0;
            }
        } else {
            P[i] = ++j;
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;

    while (cin>>s,s!=".") {
        fill(P,P+s.size()+5,0);

        int n = s.size();

        kmpprefix();

        //for1(i,0,n) cerr<<P[i]<<' ';
        //cerr<<endl;

        if(n%(n-P[n-1])==0) {
            cout<<n/(n-P[n-1])<<endl;
        } else {
            cout<<1<<endl;
        }
    }
	return 0;
}
