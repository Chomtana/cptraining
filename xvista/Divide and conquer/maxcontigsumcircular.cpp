/*
Circular -> consider copy input and add to front,back (equal to copy input 3 times)
1 8 16 3 -> 1 8 16 3  1 8 16 3  1 8 16 3
mai took pork select a1,a2,...,an,a1,a2,... mai dai pork select surm
-> fix by limit selection length to n
-> greedy breaker (limit is greedy breaker)
-> must use dp
*/

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

int data[300005];

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    int n; scanf("%d",&n);
    for1(i,0,n) scanf("%d",data+i);

    //normal mcs
    int normal = 0;
    int sum = 0;
    for1(i,0,n) {
        sum += data[i];
        if (sum<0) {
            sum=0;
        }
        normal=max(normal,sum);
    }
    //cerr<<normal<<endl;
    if (normal<=0) normal = *max_element(data,data+n);

    //inverse mcs
    int invall = 0;
    for1(i,0,n) {
        data[i] = -data[i];
        invall += data[i];
    }
    int inv = 0;
    sum = 0;
    for1(i,0,n) {
        sum += data[i];
        if (sum<0) {
            sum=0;
        }
        inv=max(inv,sum);
    }
    //cerr<<inv<<endl;
    inv = -(invall-inv);
    if (inv<=0) inv = -1E9; //if inv<=0 -> in kadane algorithm ; it say that if we don't choose -> best answer
                            //but this problem want to choose -> must choose one max element
                            //if normal > 0 ; it is clearly that normal is anser -> inv can be anti answer because it won't be answer
                            //if normal < 0 ; normal=max(...) but inv=max(...) same as normal -> can choose normal

    cout<<max(inv,normal);

	return 0;
}
