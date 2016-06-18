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

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int b,m;

int countway(vector < vector<bool> > &data, int i) {
	if (i==b-1) return 1;
	int count = 0;
	for1(j,0,b) {
		if (data[i][j]) count+=countway(data,j);
	}
	return count;
}

vector < vector<bool> > data;

bool bt(int i,int j) {
	if (i>=b || j>=b) return false;
	data[i][j] = true;
	if (countway(data,0) == m) return true;
	if (j+1<b) {
		if(!bt(i,j+1)) {
			data[i][j] = false;
			if (countway(data,0) == m) return true;
			return false;
		} else {
			return true;
		}
	} else {
		if(!bt(i+1,i+2)) {
			data[i][j] = false;
			if (countway(data,0) == m) return true;
			return false;
		} else {
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int t; cin>>t;
	for1(_t,1,t+1) {
		cout<<"Case #"<<_t<<": ";
		 cin>>b>>m;
		//vector < vector<bool> > data(b,vector<bool>(b,0));
		data.resize(b,vector<bool>(b,0));
		//first always 0
		int curr = 0;
		//data[0]=b-1;
		for (int i = 0;i<m&&i<b-1;i++) {
			data[i][b-1]=true;
		}
		
		/*int count = m-1; //count (0,b-1)
		//if (count==0) goto print;
		
		if (countway(data,0)==m) {
			goto print;
		}
		
		for(int i = 0;i<b-1;i++) {
			//data[i][b-1]=true;
			for(int j = i+1;j<b-1;j++) {
				data[i][j]=true;
				//count--;
				//if (count==0) goto print;
				
				//cout<<i<<' '<<j<<endl;
				
				if (countway(data,0)==m) {
					goto print;
				}
				
			}
		}*/
		
		bool bbb = bt(0,1);
		
		if (!bbb) {cout<<"IMPOSSIBLE"<<endl; continue;}
		
		
		print:
		
		cout<<"POSSIBLE"<<endl;
		for1(i,0,b) {
			for1(j,0,b) {
				cout<<data[i][j];
			}
			cout<<endl;
		}
		
		//cout<<countway(data,0)<<endl;
	}
	return 0;
}

/*
1 5
1 2 5
1 3 5
1 4 5
1 2 3 5
1 2 4 5

0 4
0 1 4
0 2 4
0 3 4
0 1 2 4
0 1 3 4
*/