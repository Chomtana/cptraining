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

int n;

ll res = 0;

vector<int> state;

ll sum = 0;

bool check(int c) { //return true if <tum tor leaw me o kard took> else return false (return false is as same as return ... in dp base case (ta tum tor leaw mai me tung dai kum tob / kum tob mai de kuean -> return))
                    //if need more resolution then return more value
    sum += state[c];
    if (c>0) {
        if (state[c]<state[c-1]) return false;
    }
    /*for1(i,1,state.size()) {
        if (state[i]<state[i-1]) return false;
        sum += state[i];
    }*/
    return sum<=n;
}

bool isend() {
    /*int sum = 0;
    for1(i,0,state.size()) sum+=state[i];*/
    return sum==n; //sum cached in check step
}

void decache(int c) {
    sum -= state[c];
}

void recur(int c) {

    //check
    if (c>0 && !check(c-1)) return;

    //ending (this case is not overflow because size is not known -> need to use other condition to check end)
    if (isend()) {
        res++;
        return; //overflow tong return sa mae ... jum wai
    }

    for1(i,1,(n-sum)+1) {
        state.push_back(i);
        recur(c+1);
        decache(c);
        state.pop_back();
    }
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n;
    state.reserve(1000000);
    recur(0);
    cout<<res;
	return 0;
}
