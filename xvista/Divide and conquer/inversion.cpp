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

int data[100005];

int n;

int res = 0;

/**
1 2 3 8 13 14
4 6 7 8 10 11

(8,13,14) -> (4) -> 3
(8,13,14) -> (6) -> 3
(8,13,14) -> (7) -> 3
(13,14) -> 8 -> 2
(13,14) -> 10 -> 2
(13,14) -> 11 -> 2
... j out of bound
result = 15
*/
void ms(int s,int e) { //aow,aow -> [s,mid],[mid+1,e]
    int mid = (s+e)/2;
    if (s<e) {
        ms(s,mid);
        ms(mid+1,e);
    }

    vector<int> v;

    int i = s;
    int j = mid+1;
    while (i<=mid && j<=e) { //not out of bound
        if (data[i]<=data[j]) {
            v.push_back(data[i]);
            i++;
        } else {
            //if data[i](index noi) > data[j](index mark) -> nub
            v.push_back(data[j]);
            res += mid+1-i;
            j++;
        }
    }

    while (i<=mid) {
        v.push_back(data[i]);
        i++;
    }

    while (j<=e) {
        v.push_back(data[j]);
        j++;
    }

    for1(i,s,e+1) {
        data[i] = v[i-s];
    }
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n;
    for1(i,0,n) scanf("%d",data+i);
    ms(0,n-1);
    cout<<res;
	return 0;
}
