#include <bits/stdc++.h>

#define for1(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define for2(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define for3(i,a,b,c) for(int (i)=(a);(i)<(b);(i)+=(c))
#define for4(i,a,b,c) for(int (i)=(a)-1;(i)>=(b);(i)-=(c))
#define debugv1(v) for1(_____,0,v.size()) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv2(v,size) for1(_____,0,size) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv3(v,s,e) for1(_____,s,e) cout<<(v)[_____]<<' '; cout<<endl;
#define debug1(a) cout<<(a)<<endl;
#define debug2(a,b) cout<<(a)<<' '<<(b)<<endl;
#define debug3(a,b,c) cout<<(a)<<' '<<(b)<<' '<<(c)<<endl;
#define debug4(a,b,c,d) cout<<(a)<<' '<<(b)<<' '<<(c)<<' '<<(d)<<endl;
#define debug5(a,b,c,d,e) cout<<(a)<<' '<<(b)<<' '<<(c)<<' '<<(d)<<' '<<(e)<<endl;

typedef long long ll;

using namespace std;

#define _mirror(x,y) case x: if(b==y) return true; else break;

bool mirror(char a,char b) {
	switch (a) {
		_mirror('A','A')
		_mirror('E','3')
		_mirror('H','H')
		_mirror('I','I')
		_mirror('J','L')
		_mirror('L','J')
		_mirror('M','M')
		_mirror('O','O')
		_mirror('S','2')
		_mirror('T','T')
		_mirror('U','U')
		_mirror('V','V')
		_mirror('W','W')
		_mirror('X','X')
		_mirror('Y','Y')
		_mirror('Z','5')
		_mirror('1','1')
		_mirror('2','S')
		_mirror('3','E')
		_mirror('5','Z')
		_mirror('8','8')
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	string s;
	while (cin>>s) {
		bool pa = true;
		bool mir = true;
		for1(i,0,s.size()/2) {
			if (s[i]!=s[s.size()-1-i]) pa = false;
			if (!mirror(s[i],s[s.size()-1-i])) mir = false;
		}
		if (s.size()%2==1) if(!mirror(s[s.size()/2],s[s.size()/2])) mir = false;
		cout<<s<<" -- ";
		if (pa && mir) cout<<"is a mirrored palindrome.";
		else if (pa) cout<<"is a regular palindrome.";
		else if (mir) cout<<"is a mirrored string.";
		else cout<<"is not a palindrome.";		
		cout<<endl<<endl;
	}
	return 0;
}