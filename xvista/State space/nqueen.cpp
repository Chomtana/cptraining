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

vector<int> board;
int n;
ll res = 0;

bool check(int c) { //c = index of last insert
    for1(i,1,n) {
        if (c-i<0 && c+i>=n) break;
        if (c-i>=0 && board[c-i]!=-1 && abs(board[c-i]-board[c])==i) {
            return false;
        }
        if (c+i<n && board[c+i]!=-1 && abs(board[c+i]-board[c])==i) return false;
        if (c-i>=0 && board[c-i]!=-1 && board[c-i]==board[c]) return false;
        if (c+i<n && board[c+i]!=-1 && board[c+i]==board[c]) return false;
    }
    return true;

}

void recur(int c) {

    if (c>0 && !check(c-1)) return;

    if (c>=n) {
        res++;
        return;
    }

    for1(i,0,n) {
        board[c] = i; //set pai
        recur(c+1); //do next
        board[c] = -1; //reset kub
        //tong tum kob 3 step
    }

}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n;
    board.resize(n,-1);
    recur(0);
    cout<<res;
	return 0;
}
