#include <bits/stdc++.h>

using namespace std;

/**
	input:
	3 CDEKLMBFJNAGHI
	drawing:
2   CDE KLM	 1 loop = 3 + 3 + 1 + 1 = n+n+(n-2)+(n-2) = 4n-4
1   B F J N	 1 loop : line 0,n-1 = 3 = 1+1+(n-2) = n ; other = 2
0   A GHI
	output: ABCDEFGHIJKLMN
*/

int ceil(int a,int b) {
	return (a%b==0)?a/b:a/b+1;
}

int main() {
	ios::sync_with_stdio(false);
	int n; cin>>n;
	string s; cin>>s;

	if (n==1) {
		cout<<s; return 0;
	}

	vector<string> data(n,"");
	int loop = s.size()/(4*n-4);
	int loopr = s.size()%(4*n-4);
	vector<int> linebonus(n,0);
	for (int i = 0;i<n&&loopr>0;i++,loopr--) {
		linebonus[i]++;
	}
	linebonus[n-1] += ((loopr>n-2)?(n-2):loopr);
	loopr -= ((loopr>n-2)?(n-2):loopr);
	for (int i = n-1;i>=0&&loopr>0;i--,loopr--) {
		linebonus[i]++;
	}
	//loopr++;
	linebonus[0] += ((loopr>n-2)?n-2:loopr);
	loopr -= ((loopr>n-2)?n-2:loopr);

	string::iterator sit = s.begin();
	for (int i = 0;i<loop*n+linebonus[n-1];i++) {
		data[n-1] += *sit;
		sit++;
	}
	for (int line = n-2;line>=1;line--) {
		for (int i = 0;i<2*loop+linebonus[line];i++) {
			data[line] += *sit;
			sit++;
		}
	}
	for (int i = 0;i<loop*n+linebonus[0];i++) {
		data[0] += *sit;
		sit++;
	}

	/*for (int i = n-1;i>=0;i--) {
		cout<<data[i]<<endl;
	}*/

	string::iterator datait[n];

	for (int i = 0;i<n;i++) {
		datait[i] = data[i].begin();
	}

	string res = "";

	while (true) {
		int allend = true;
		for (int i = 0;i<n;i++) {
			if (datait[i] != data[i].end()) {
				allend = false;
			}
		}

		if (allend) break;


		for (int i = 0;i<n;i++) {
			if (datait[i] == data[i].end()) continue;
			res += *datait[i];
			datait[i]++;
		}
		for (int i = 0;i<n-2;i++) {
			if (datait[n-1] == data[n-1].end()) continue;
			res += *datait[n-1];
			datait[n-1]++;
		}
		for (int i = n-1;i>=0;i--) {
			if (datait[i] == data[i].end()) continue;
			res += *datait[i];
			datait[i]++;
		}
		for (int i = 0;i<n-2;i++) {
			if (datait[0] == data[0].end()) continue;
			res += *datait[0];
			datait[0]++;
		}
	}

	cout<<res;

	return 0;
}
