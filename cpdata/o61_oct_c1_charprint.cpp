#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

typedef long long ll;

int mode;
string s;
string target;

deque<int> pos[300];

class fwtree {
public:
    vector<ll> a;

    fwtree() {
        a = vector<ll>(1000005);
    }

    ll operator ()(int to) {
        ll res = 0;
        for(int i = to;i>=1;i-=(i&(-i))) {
            res += a[i];
        }
        return res;
    }

    ll operator ()(int from, int to) {
        if (from == 0) return (*this)(to);
        else return (*this)(to)-(*this)(from-1);
    }

    void add(int pos,int val) {
        //cout<<pos<<endl;
        for(int i = pos;i<1000000;i+=(i&(-i))) {
            //cout<<i<<endl;
            a[i] += val;
        }
    }

    void dbg() {
        for(int i = 0;i<100;i++) {

        }
    }
};

int main() {
    cin >> mode >> s >> target;
    for(int i = 0;i<s.size();i++) {
        pos[s[i]].push_back(i+1);
    }

    if (mode == 0) {
        ll res = 0;
        for(auto &c: target) {
            if (pos[c].size() == 0) {
                cout<<-1;
                return 0;
            }
            res += pos[c][0];

            pos[c].pop_front();
        }
        cout<<res;
    } else {
        ll res = 0;

        fwtree fw;

        for1(i,1,s.size()+1) {
            fw.add(i,1);
        }

        for(auto &c: target) {
            if (pos[c].size() == 0) {
                cout<<-1;
                return 0;
            }
            ll subres = fw(pos[c][0]);
            res += subres;
            //cout<<subres<<endl;
            fw.add( pos[c][0], -1);
            pos[c].pop_front();
        }

        cout<<res;
    }

    return 0;
}
