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

int w2f[256];

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;

	w2f['a']=1;
	w2f['b']=4;
	w2f['c']=3;
	w2f['d']=3;
	w2f['e']=3;
	w2f['f']=4;
	w2f['g']=4;
	w2f['h']=7;
	w2f['i']=8;
	w2f['j']=7;
	w2f['k']=8;
	w2f['l']=9;
	w2f['m']=7;
	w2f['n']=7;
	w2f['o']=9;
	w2f['p']=10;
	w2f['q']=1;
	w2f['r']=4;
	w2f['s']=2;
	w2f['t']=4;
	w2f['u']=7;
	w2f['v']=4;
	w2f['w']=2;
	w2f['x']=2;
	w2f['y']=7;
	w2f['z']=1;
	w2f[',']=8;
	w2f['.']=9;
	w2f[';']=10;
	w2f['/']=10;
	//w2f[' ']=; //special case

	int n,m;
    while (cin>>n>>m) {
        bool ban[11]; for1(i,0,11) ban[i] = false;
        for1(i,0,n) {
            int in; cin>>in;
            ban[in] = true;
        }
        //cin.ignore();
        set<string> cantype;
        int maxl = 0;
        while (m--) {
            string s; cin>>s; //getline(cin,s); //jod puean mun bork wa one per line , me space tae jing jing mai me ... jua hua kuy
            bool ok = true;
            for(char &c:s) {
                if (c==' ') {
                    if (ban[5]&&ban[6]) {
                        ok = false;
                        break;
                    }
                } else {
                    if (ban[w2f[c]]) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                if (s.size()>maxl) {
                    maxl = s.size();
                    cantype.clear();
                    cantype.insert(s);
                } else if (s.size()==maxl) {
                    cantype.insert(s);
                }
            }
        }

        cout<<cantype.size()<<endl;
        for(auto &s:cantype) {
            cout<<s<<endl;
        }
    }
	return 0;
}
