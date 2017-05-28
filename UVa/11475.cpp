/*
Secret algorithm:
Longest middle match -> return length of match

abxyzbc
xyza
= 0 (don't match)

abxyz
xyzb
...
abxyz
  xyzb
= 3 (match len 3)

... Only maximum one wing in each string ... no two wing

!!! This style is not middle match !!!
abxyz
  xy
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

int P[100005];

void kmpprefix(string &s) {
    for1(i,0,s.size()) P[i] = 0;

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

int kmp(string &s,string &p) { //longest middle mode return length of longest middle match
    kmpprefix(p);

    int i=0,j=0;
    while (i<s.size()) {
        while (j>0 && s[i]!=p[j]) {
            j = P[j-1];
        }
        if (j==0) {
            if (s[i]==p[j]) {
                i++; j++;
            } else {
                i++;
            }
        } else {
            i++; j++;
        }
    }

    return j; //middle mode add return j;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    string s;
    while(cin>>s) {
        string re(s.rbegin(),s.rend());
        cout<<s+re.substr(kmp(s,re))<<endl;
    }
	return 0;
}
