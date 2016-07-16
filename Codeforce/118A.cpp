#include <bits/stdc++.h>
#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

int main() {
	string s; cin>>s;
	transform(s.begin(),s.end(),s.begin(),::tolower);
	for1(i,0,s.size()) {
		switch (s[i]) {
			case 'a': case 'e': case 'i': case 'o': case 'u': case 'y': continue;
			default: {
				cout<<'.'<<s[i];
			}
		}
	}
}
