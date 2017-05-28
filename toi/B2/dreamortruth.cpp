#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

string a,b,c;

string p(string xx,string yy) { //dereference for decrease bug ... but speed decrease
    deque<int> x;
    deque<int> y;
    deque<int> res;
    for1(i,0,xx.size()) x.push_back(xx[i]-'0');
    for1(i,0,yy.size()) y.push_back(yy[i]-'0');
    int maxsize = max(xx.size(),yy.size());
    while (x.size()<maxsize+1) {
        x.push_front(0);
    }
    while (y.size()<maxsize+1) {
        y.push_front(0);
    }

    bool add = false;
    for2(i,maxsize,0) {
        int sum = x[i]+y[i]+add;
        add = false;
        if (sum>9) {
            add = true;
            sum -= 10;
        }
        res.push_front(sum);
    }

    while (res[0]==0) {
        res.pop_front();
    }

    string ress = "";
    for1(i,0,res.size()) {
        ress += res[i]+'0';
    }

    return ress;
}

string mul(string x,int y) { //dereference for decrease bug ... but speed decrease
    //int is single (0,...,9)

    deque<int> res;


    int add = 0;
    for2(i,x.size()-1,0) {
        int sum = (x[i]-'0')*y+add;
        add = 0;
        if (sum>9) {
            add = sum/10;
            sum %= 10;
        }
        res.push_front(sum);
    }
    if (add>0) {
        res.push_front(add);
    }

    string ress = "";
    for1(i,0,res.size()) {
        ress += res[i]+'0';
    }

    return ress;
}

string mul(string x,string y) {
    if (y.size()==1) {
        return mul(x,y[0]-'0');
    } else {
        string mul1 = mul(x,y.back()-'0');
        x.push_back('0');
        y.pop_back();
        return p(mul1,mul(x,y));
    }

}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>a>>b>>c;
    //cout<<p(a,b);
    bool res = mul(a,b)==c;
    if (res) cout<<"truth"; else cout<<"dream";
	return 0;
}
