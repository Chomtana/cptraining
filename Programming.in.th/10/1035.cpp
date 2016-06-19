#include <bits/stdc++.h>
#include <stdlib.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

typedef long long ll;

bool ispal(ll n) {
	char s[20];
	sprintf(s,"%ld",n);
	int len = strlen(s);
	for1(i,0,len) {
		if (s[i]!=s[len-1-i]) return false;
	}
	return true;
}

vector<ll> p;
bool isp[1000000];

bool isprime(ll n) {
	if (n<1000000) return isp[n];
	if (n&1==0) return false; //n%2 = n&1 (n%(2^m) = n&(2^m-1))
	for1(i,0,p.size()) {
		if (p[i]*p[i]>n) {
			return true;
		}
		if (n%p[i]==0) return false;
	}
	return true;
}


int main() {


	fill(isp,isp+1000000,true);
	isp[0]=false; isp[1]=false;
	for (long long i = 0;i<1000000;i++) {
		if (!isp[i]) continue;
		for(long long j=i*i;j<1000000;j+=i) {
			isp[j] = false;
		}
	}
	for1(i,0,1000000) if(isp[i]) p.push_back(i);

	ll n; cin>>n;
	vector<ll>::iterator it = lower_bound(p.begin(),p.end(),n);
	if (it!=p.end()) n = *it;
	while (!(ispal(n)&&isprime(n))) {
		if (it!=p.end()) {
			it++;
			if (it==p.end()) goto itend;
			n = *it;
		} else {
			itend:
			n++;
		}
	}

	cout<<n;
	return 0;
}
