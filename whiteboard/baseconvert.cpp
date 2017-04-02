#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

vector<int> chartonum(256);
vector<char> numtochar(17);

int tobase10(string n,int s) {
    int res = 0;
    for1(i,0,n.size()) {
        int ire = n.size()-i-1;
        //cout<<pow(s,i)<<endl;
        res += chartonum[n[ire]]*round(pow(s,i));
    }
    return res;
}

string tobase(int n,int base) {
    stack<int> s;
    while (n>0) {
        s.push(n%base);
        n /= base;
    }
    string res = "";
    while (!s.empty()) {
        //cout<<s.top()<<endl;
        res += numtochar[s.top()];
        s.pop();
    }
    return res;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;

    numtochar[0] = '0';
    numtochar[1] = '1';
    numtochar[2] = '2';
    numtochar[3] = '3';
    numtochar[4] = '4';
    numtochar[5] = '5';
    numtochar[6] = '6';
    numtochar[7] = '7';
    numtochar[8] = '8';
    numtochar[9] = '9';
    numtochar[10] = 'a';
    numtochar[11] = 'b';
    numtochar[12] = 'c';
    numtochar[13] = 'd';
    numtochar[14] = 'e';
    numtochar[15] = 'f';

    chartonum['0'] = 0;
    chartonum['1'] = 1;
    chartonum['2'] = 2;
    chartonum['3'] = 3;
    chartonum['4'] = 4;
    chartonum['5'] = 5;
    chartonum['6'] = 6;
    chartonum['7'] = 7;
    chartonum['8'] = 8;
    chartonum['9'] = 9;
    chartonum['a'] = 10;
    chartonum['b'] = 11;
    chartonum['c'] = 12;
    chartonum['d'] = 13;
    chartonum['e'] = 14;
    chartonum['f'] = 15;

    string _n; int s,d;

    while (cin>>_n>>s>>d,s!=0) {
        int n = tobase10(_n,s);
        //cout<<n<<endl;
        cout<<tobase(n,d)<<endl;
    }

	return 0;
}
