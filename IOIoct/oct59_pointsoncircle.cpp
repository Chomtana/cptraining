//test case kak (mai dai include case te mun hung > 1 round kor dai tem)
//torn ne include leaw

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

int n,k;
ll d[1005][1005];
ll p[1005];
bool doans = false;

void printans() {
	for1(i,0,k) {
		printf("%d\n",((p[i]%n)+n)%n);
	}
	//printf("\n");
	doans = true;
}

void recur(int c) {
	//cerr<<c<<" : ";printans();
	//bug : tong won

	//cerr<<c;

	if (c>=k) {
		printans();
		return;
	}

	if (doans) return;

	//do cc
	p[c] = (p[c-1]+d[c-1][c])%n;
	/*cerr<<" : ";
    for1(i,0,c+1) {
        cerr<<p[i]<<' ';
    }
    cerr<<" , ";*/
	//if ok (must include last do (c) in all step of check ... must choose c) -> recur next
	bool ok = true;
	for1(i,0,c) {
	    if (p[i]==p[c]) {
            ok = false;
            break;
	    }
		if (d[i][c]%n!=abs(p[i]-p[c]) && d[i][c]%n!=(n-abs(p[i]-p[c]))%n) {
			ok = false;
			break;
		}
	}
	//cerr<<ok<<endl;
	if (ok) recur(c+1);
	p[c] = 1E9;

	//do ccw
	p[c] = ((p[c-1]-d[c-1][c])+n)%n;
    /*for1(i,0,c+1) {
        cerr<<p[i]<<' ';
    }
    cerr<<endl;*/
	ok = true;
	for1(i,0,c) {
	    if (p[i]==p[c]) {
            ok = false;
            break;
	    }
		if (d[i][c]%n!=abs(p[i]-p[c]) && d[i][c]%n!=(n-abs(p[i]-p[c]))%n) {
			ok = false;
			break;
		}
	}
	if (ok) recur(c+1);
	p[c] = 1E17L;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	cin>>n>>k;
	fill(p,p+1005,1E17L);
	for1(i,0,k) {
		for1(j,0,k) {
			ll x; scanf("%lld",&x);
			//x %= n;
			d[i][j] = x;
			d[j][i] = x;
		}
	}
	p[0]=0;
	recur(1);
	return 0;
}
