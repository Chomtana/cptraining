#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

vector<int> data;
vector<bool> selected;
vector<bool> result;
int ressum = 0;
int n;

void check() {
	int sum= 0;
	for1(i,0,selected.size()) {
		if (selected[i]) {
			sum += data[i];
		}
	}
	if (sum>n) return;
	if (sum>ressum) {
		copy(selected.begin(),selected.end(),result.begin());
		ressum = sum;
	}
}

void bt(int index) {
	if (index>=data.size()) return;

	selected[index] = true;
	check();
	bt(index+1);

	selected[index] = false;
	check();
	bt(index+1);
}

int main () {
	ios::sync_with_stdio(false);

	while (cin>>n) {
		int t; cin>>t;
		data.resize(t);
		selected.resize(t,false);
		result.resize(t,false);
		for1(i,0,t) {
			cin>>data[i];
		}
		bt(0);
		for1(i,0,result.size()) {
			if (result[i]) {
				cout<<data[i]<<' ';
			}
		}
		cout<<"sum:"<<ressum;
		cout<<endl;
		ressum = 0;
		data.clear();
		selected.clear();
		result.clear();
	}
	return 0;
}
