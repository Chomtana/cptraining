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
deque<int> data;

int res = 0;

void recur() {
    /*if (data.size()==2) {
        res = max(res,(data[0]&data[1]));
        return;
    }*/
    sort(all(data),greater<int>());

    bool all0 = true;
    for1(i,0,data.size()) {
        if (data[i]!=0) {all0 = false; break;}
    }

    if (all0) return;

    int delcount = 0;
    if (floor(log2(data[0]))==floor(log2(data[1]))) {

        int d = floor(log2(data[0]));
        //cerr<<"aaa "<<d<<endl;
        while (floor(log2(data.back()))!=d) {
            data.pop_back();
            delcount++;
        }
        //cerr<<data.size()<<endl;
        //if (delcount==0) return;
        res += 1<<d;
        for1(i,0,data.size()) {
            data[i] -= 1<<d;
            //cerr<<(1<<d)<<' '<<data[i]<<endl;
        }
        //cerr<<"aaa"<<endl;
        recur();
    } else {
        //data.pop_front();
        int d = floor(log2(data[0]));
        //cerr<<"bbb "<<data[0]<<endl;
        data[0] -= 1<<d;

        recur();
        return;
    }

}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n;
    data.resize(n+5);
    for1(i,0,n) scanf("%d",&data[i]);
    /*sort(all(data),[](int a,int b) {
        return log2(a)>log2(b);
    });*/
    //cout<<(data[n-1]&data[n-2]);
    recur();
    cout<<res;
	return 0;
}
