#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int a,b,c,d;
	while (cin>>a>>b>>c>>d) {
		if (a==0 && b==0 && c==0 && d==0) break;
		int res = 1080;
		res += (b>a?360-(b-a)*9:(a-b)*9);
		res += (c>b?(c-b)*9:360-(b-c)*9);
		res += (d>c?360-(d-c)*9:(c-d)*9);
		cout<<res<<endl;
	}
	
	
	return 0;
}