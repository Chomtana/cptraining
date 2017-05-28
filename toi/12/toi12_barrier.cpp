/*
each point has two way to do with it
- add
    - it can make greedy breaker case (select > limit)
        -> it add a case where we do greedy breaker every times we add
    - if greedy breaker then you must do anything to make it not greedy breaker
    - by remove first element (cannot remove middle/end because it will not consecutive)
- add with greedy breaker everytime
- start new (erase all)
*/

#include <bits/stdc++.h>

#define for1(a,b,c) for(ll (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	//ios::sync_with_stdio(false);
	//cout<<fixed;
    ll n,l; cin>>n>>l;
    ll maxsum = 0;
    ll minl = 1E15;
    ll sum = 0;
    ll currl = 0;
    ll data[n];
    for1(i,0,n) {
        ll x; scanf("%lld",&x);
        data[i] = x;
        ll addres = sum;
        ll gbaddres = sum+x-data[i-currl];
        if (currl<l) {
            //not greedy breaker
            addres += x;
        } else {
            //greedy breaker
            addres += x;
            addres -= data[i-l];
        }
        ll checkmax[] = {x,gbaddres,addres};
        ll maxvar = max_element(checkmax,checkmax+3)-checkmax;
        if (maxvar==0) {
            sum = x;
            currl = 1;
        } else if (maxvar==1) {
            sum = gbaddres;
        } else {
            sum = addres;
            currl++;
        }
        /*if (addres>x) {
            if (currl<l) {
                //not greedy breaker
                sum = addres;
                currl++;
            } else {
                //greedy breaker
                sum = addres;
            }
        } else {
            //if addres==x select start new because     if we select addres then it will found greedy breaker easier and make it need to minus
            //                                          and if multiple ans -> this problem need lower length
            sum = x;
            currl = 1;
        }*/

        if (sum>maxsum) {
            maxsum = sum;
            minl = currl;
        } else if (sum==maxsum) {
            minl = min(minl,currl);
        }
    }
    if (maxsum<=0) {
        cout<<0<<endl<<0;
        return 0;
    }
    cout<<maxsum<<endl<<minl;
	return 0;
}
