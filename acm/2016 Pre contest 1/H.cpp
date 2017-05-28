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

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    int n; cin>>n;
    vector<string> ne;
    vector<string> po;
    for1(i,0,n) {
        string s; cin>>s;
        /*char schange[102];
        for1(i,0,102) schange[i] = '0';*/
        if (s[0]=='-') {
            s = s.substr(1);
            /*for1(i,0,s.size()) {
                schange[101-i] = s[s.size()-1-i];
            }
            ne.push_back(string(schange,schange+102));*/
            ne.push_back(s);
        } else {
            /*for1(i,0,s.size()) {
                schange[101-i] = s[s.size()-1-i];
            }
            po.push_back(string(schange,schange+102));*/
            po.push_back(s);
        }
    }

    /*for1(i,0,ne.size()) {
        cerr<<ne[i]<<endl;
    }
        for1(i,0,po.size()) {
            cerr<<po[i]<<endl;
        }*/

    vector<deque<string>> radix(10);

    for1(i,0,100) {

        //do ne
        radix.clear();
        radix.resize(10);
        for1(j,0,ne.size()) {
            if (int(ne[j].size()-1-i)<0) {
                radix[0].push_back(ne[j]);
            } else {
                radix[ne[j][ne[j].size()-1-i]-'0'].push_back(ne[j]);
            }
        }
        vector<string> netemp;
        netemp.reserve(ne.size());
        for1(j,0,10) {
            while (!radix[j].empty()) {
                netemp.push_back(radix[j][0]);
                radix[j].pop_front();
            }
        }
        ne = netemp;

        //do po
        radix.clear();
        radix.resize(10);
        for1(j,0,po.size()) {
            if (int(po[j].size()-1-i)<0) {
                radix[0].push_back(po[j]);
            } else {
                radix[po[j][po[j].size()-1-i]-'0'].push_back(po[j]);
            }
        }
        vector<string> potemp;
        potemp.reserve(po.size());
        for1(j,0,10) {
            while (!radix[j].empty()) {
                potemp.push_back(radix[j][0]);
                radix[j].pop_front();
            }
        }
        po = potemp;
    }

    reverse(all(ne));

    for1(i,0,ne.size()) {
        cout<<'-'<<ne[i]<<endl;
    }
    for1(i,0,po.size()) {
        cout<<po[i]<<endl;
    }
	return 0;
}
