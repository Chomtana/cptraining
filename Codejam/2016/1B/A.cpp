#include <bits/stdc++.h>

#define for1(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define for2(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)-=(res[3]>0?res[3]:0))
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

#define aaa(i) if(res[i]>0) {res[i]=1; end=false; v[i]++;}

typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int t; cin>>t;
	for(int _t=1;_t<=t;_t++) {
		string s; cin>>s;
		sort(s.begin(),s.end());
		//cout<<s<<endl;
		vector<int> c(256);
		for1(i,0,s.size()) {
			c[s[i]]++;
		}
		cout<<"Case #"<<_t<<": ";
		vector<int> v(10);
		vector<int> res(10);
		//while (1) {
			//bool end = true;
			res[0] = min(c['Z'],min(c['E'],min(c['R'],c['O'])));
			c['Z']-=(res[0]>0?res[0]:0);c['E']-=(res[0]>0?res[0]:0);c['R']-=(res[0]>0?res[0]:0);c['O']-=(res[0]>0?res[0]:0);
			res[1] = min(c['O'],min(c['N'],c['E']));
			c['O']-=(res[1]>0?res[1]:0);c['N']-=(res[1]>0?res[1]:0);c['E']-=(res[1]>0?res[1]:0);
			res[2] = min(c['T'],min(c['W'],c['O']));
			c['T']-=(res[2]>0?res[2]:0);c['W']-=(res[2]>0?res[2]:0);c['O']-=(res[2]>0?res[2]:0);
			res[3] = min(c['T'],min(c['H'],min(c['R'],c['E']/2)));
			c['T']-=(res[3]>0?res[3]:0);c['H']-=(res[3]>0?res[3]:0);c['R']-=(res[3]>0?res[3]:0);c['E']-=(res[3]>0?res[3]*2:0);
			res[4] = min(c['F'],min(c['O'],min(c['U'],c['R'])));
			c['F']-=(res[4]>0?res[4]:0);c['O']-=(res[4]>0?res[4]:0);c['U']-=(res[4]>0?res[4]:0);c['R']-=(res[4]>0?res[4]:0);
			res[5] = min(c['F'],min(c['I'],min(c['V'],c['E'])));
			c['F']-=(res[5]>0?res[5]:0);c['I']-=(res[5]>0?res[5]:0);c['V']-=(res[5]>0?res[5]:0);c['E']-=(res[5]>0?res[5]:0);
			res[6] = min(c['S'],min(c['I'],c['X']));
			c['S']-=(res[6]>0?res[6]:0);c['I']-=(res[6]>0?res[6]:0);c['X']-=(res[6]>0?res[6]:0);
			res[7] = min(c['S'],min(c['E']/2,min(c['V'],c['N'])));
			c['S']-=(res[7]>0?res[7]:0);c['E']-=(res[7]>0?res[7]*2:0);c['V']-=(res[7]>0?res[7]:0);/*c['E']-=(res[7]>0?res[7]:0);*/c['N']-=(res[7]>0?res[7]:0);
			res[8] = min(c['E'],min(c['I'],min(c['G'],min(c['H'],c['T']))));
			c['E']-=(res[8]>0?res[8]:0);c['I']-=(res[8]>0?res[8]:0);c['G']-=(res[8]>0?res[8]:0);c['H']-=(res[8]>0?res[8]:0);c['T']-=(res[8]>0?res[8]:0);
			res[9] = min(c['N']/2,min(c['I'],c['E']));
			c['N']-=(res[9]>0?res[9]*2:0);c['I']-=(res[9]>0?res[9]:0);c['E']-=(res[9]>0?res[9]:0);
			//if (end) break;
		//}
		for (int i = 0;i<10;i++) {
			for1(j,0,v[i]){
				cout<<i;
			}
		}
		cout<<endl;
		
	}
	return 0;
}