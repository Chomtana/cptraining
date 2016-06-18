#include <bits/stdc++.h>

using namespace std;

int r,c,x;

void pn(string s,int n) {
	while(n--)cout<<s;
}

void pp(int pos,bool re) {
	for (int i = 0;i<c;i++) {
		pn(".",pos);
		cout<<(re?'\\':'/');
		pn(".",x-pos-1);
		//cout<<endl;

		//int post = pos;
		pos = x-pos-1;

		pn(".",pos);
		cout<<(re?'/':'\\');
		pn(".",x-pos-1);
		//cout<<endl;

		//pos = post; //cheat coding ... useful in contest but not wroth in pratice
		pos = x-pos-1;
	}
	cout<<endl;
}

void p() {
	for(int i = x-1;i>=0;i--) {
		pp(i,false);
	}
	for(int i = 0;i<x;i++) {
		pp(i,true);
	}
}

int main() {
	int t; cin>>t;
	while (t--) {
		cin>>r>>c>>x;
		while(r--) {
			p();
		}
		cout<<endl;
	}
	return 0;
}
