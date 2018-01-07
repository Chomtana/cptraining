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

vector<string> s = {"Dynamic Programming (not on tree)","Greedy","Segment/Fenwick Tree","DP on Tree","SCC","MST","shortest path","divide and conquer","binary search+hash","Math","Tree traversal","Combinatoric","Binary tree","list/stack/queue"};

int main() {
	//ios::sync_with_stdio(false);

	//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(time(NULL));

    shuffle(all(s),default_random_engine(time(0)));
    //for1(i,0,s.size()) cout<<s[i]<<' ';

    for1(_,0,4) {
        int r = rand()%2+1;
        //cerr<<r<<' ';
        cout<<s.back(); s.pop_back();
        if (r==2) {
            cout<<" , "<<s.back(); s.pop_back();
        }
        cout<<endl;
    }

	cout<<fixed;

	return 0;
}
