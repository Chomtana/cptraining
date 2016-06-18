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

string s1,s2;

vector< string > dp;

//manual do form end but we can do from start and it is much more easy
/*string dodp(int i1,int i2) {
	if (i1>=s1.size() || i2>=s2.size()) return "";
	
	string result="";
	if (s1[i1]!=s2[i2]) {
		string way1 = dodp(i1+1,i2);
		string way2 = dodp(i1,i2+1);
		if (way1.size()>=way2.size()) {
			result = way1;
		} else {
			result = way2;
		}
	} else {
		result = s1[i1]+dodp(i1+1,i2+1);
	}
	
	return result;
}*/
//read problem again not common subsequence but maximum size of contiguous string

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	cin>>s1>>s2;
	
	string result = "";
	
	for1(i,0,s1.size()) {
		for1(j,0,s2.size()) {
			if (s2[j]==s1[i]) { //boss do first thing of work
				string s = "";
				s += s2[j];
				int k = 1;
				while (i+k<s1.size() && j+k<s2.size() && s1[i+k]==s2[j+k]) {
					s+=s2[j+k];
					k++;
				}
				if (s.size()>result.size()) {
					result = s;
				}
			}
		}
	}
	
	cout<<result;
	//cout << dodp(0,0);
	return 0;
}