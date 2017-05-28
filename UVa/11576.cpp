/*
kmpmiddle(s,p)
s CAT       (me peek left)
p   TAE     (me peek right)
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

int P[10005];

void kmpprefix(string &s) {
    for1(i,0,s.size()) P[i] = 0;
    int j = 0;
    for1(i,1,s.size()) {
        while (j>0 && s[i]!=s[j]) {
            j = P[j-1];
        }
        if (s[i]==s[j]) P[i] = ++j;

    }
}

int kmp(string &s,string &p) { //longest middle matching mode ... s -> me peek left , p -> me peek right
    kmpprefix(p);

    int j = 0;
    for1(i,0,s.size()) {
        while (j>0 && s[i]!=p[j]) { //prefix .. s[i],s[j] ....... kmp .. s[i],p[j]
            j = P[j-1];
        }
        if (s[i]==p[j]) j++;
    }

    return j; //middle mode change here -> return length of longest middle match

}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	/*string s1 = "CAT";
	string s2 = "TED";
    cerr<<kmp(s1,s2);*/
    int t; cin>>t;
    while (t--) {
        int k,n; cin>>k>>n;
        string data[n];
        for1(i,0,n) cin>>data[i];
        string curr = data[0];
        for1(i,1,n) {
            int len = kmp(curr,data[i]);
            //cerr<<len<<' '<<data[i]<<' '<<curr<<endl;
            curr += data[i].substr(len);
        }
        cout<<curr.size()<<endl;
    }
	return 0;
}
