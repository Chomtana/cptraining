#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int n; cin>>n;
	ll data[n+1];
	//rub kar index 1->n
	for1(i,1,n+1) {
	    cin>>data[i];
	    if ((i&1)==1)  data[i] = -data[i];
	}

	//quick sum from end
	ll c[n+1];
	c[n] = data[n];
	for(int i = n-1;i>=1;i--) {
		c[i] = c[i+1]+data[i];
	}

	ll res = c[1];

	//choose 0 pos such that c most
	int first0 = -1;
	int second0 = -1;
	ll currcmax = -1E17;
	for1(i,1,n+1) {
		if (c[i]>currcmax) {
			currcmax = c[i];
			first0 = i;
		}
	}

	//calculate new res
	ll res1 = 0;
	for1(i,1,first0) {
        res1 += data[i];
	}

	res1 -= c[first0];

	res = min(res,res1);
	//cerr<<first0<<endl;




	//choose first 0 pos such that c most (same as before)
	//choose next 0 pos such that c least
	ll currcmin = 1E17;
	for1(i,first0+1,n+1) {
		if (c[i]<currcmin) {
			currcmin = c[i];
			second0 = i;
		}
	}

	if (second0!=-1) {
		//calculate new res
		ll res2 = 0;
		for1(i,1,first0) {
            res2 += data[i];
		}
		for1(i,first0,second0) {
            res2 -= data[i];
		}
		for1(i,second0,n+1) {
            res2 += data[i];
		}

		res = min(res,res2);
	}

	//choose first 0 pos such that c least
	//choose previous 0 pos such that c most

    currcmin = 1E17;
    first0 = -1;
    second0 = -1;
	for(int i = n;i>=1;i--) {
		if (c[i]<currcmin) {
			currcmin = c[i];
			second0 = i;
		}
	}

	currcmax = -1E17;
	for(int i = second0-1;i>=1;i--) {
		if (c[i]>currcmax) {
			currcmax = c[i];
			first0 = i;
		}
	}

	if (first0!=-1) {
		//calculate new res
		ll res2 = 0;
		for1(i,1,first0) {
            res2 += data[i];
		}
		for1(i,first0,second0) {
            res2 -= data[i];
		}
		for1(i,second0,n+1) {
            res2 += data[i];
		}

		res = min(res,res2);
	}


	cout<<res;

	return 0;
}
