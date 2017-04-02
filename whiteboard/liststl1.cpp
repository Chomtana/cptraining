#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()
#define until(x) while(!(x))

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	srand(time(0));
	list<int> l1;
	list<int> l2;
	list<int> l3;
    for1(i,0,10) {
        int ins = rand()%(100-1+1)+1;
        l1.push_back(ins);
    }
    l1.sort();
    for1(i,0,10) {
        int ins = rand()%(100-1+1)+1;
        l2.push_back(ins);
    }
    l2.sort();
    for1(i,0,10) {
        int ins = rand()%(100-1+1)+1;
        l3.push_back(ins);
    }
    l3.sort();

    list<int> l;

    until(l1.empty() && l2.empty() && l3.empty()) {
        int l1val = (l1.empty()?1E9:*l1.begin());
        int l2val = (l2.empty()?1E9:*l2.begin());
        int l3val = (l3.empty()?1E9:*l3.begin());

        if (l1val<l2val) {
            if (l1val<l3val) {
                l.push_front(l1val);
                l1.pop_front();
            } else {
                l.push_front(l3val);
                l3.pop_front();
            }

        } else {
            if (l2val<l3val) {
                l.push_front(l2val);
                l2.pop_front();
            } else {
                l.push_front(l3val);
                l3.pop_front();
            }
        }


    }

    for(list<int>::iterator it = l.begin();it!=l.end();it++) {
        cout<<*it<<" --> ";
    }
    cout<<"NULL";


	return 0;
}
