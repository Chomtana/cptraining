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

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	int t; cin>>t;
	
	for(int _t=1;_t<=t;_t++) {cout<<"Case #"<<_t<<": ";
		int mind = 1000000000;
		string a,b; cin>>a>>b;
		//cout<<a<<' '<<b<<endl;
		string resa,resb;
		for1(i1,0,10) {
			int x = i1;
			if (a[0]!='?' && a.size()>=1) x=a[0]-'0';
			for1(i2,0,10) {
				int y = i2;
				if (a[1]!='?' && a.size()>=2) y=a[1]-'0';
				for1(i3,0,10) {
					int z = i3;
					if (a[2]!='?' && a.size()>=3) z=a[2]-'0';
					for1(i4,0,10) {
						int l = i4;
						if (b[0]!='?' && b.size()>=1) l=b[0]-'0';
						for1(i5,0,10) {
							int m = i5;
							if (b[1]!='?' && b.size()>=2) m=b[1]-'0';
							for1(i6,0,10) {
								int n = i6;
								if (b[2]!='?' && b.size()>=3) n=b[2]-'0';
								
								string ar;
								if(a.size()>=1) ar += x+'0';
								if(a.size()>=2) ar += y+'0';
								if(a.size()>=3) ar += z+'0';
								
								string br;
								if(b.size()>=1) br+=l+'0';
								if(b.size()>=2) br+=m+'0';
								if(b.size()>=3) br+=n+'0';
								
								//stringstream ss(ar); int ai; ss>>ai;
								//stringstream ss2(br); int bi; ss2>>bi;
								//cout<<ai<<' '<<bi<<endl;
								
								int ai = atoi(ar.c_str());
								int bi = atoi(br.c_str());
								
								if (abs(ai-bi)<mind) {
									mind = abs(ai-bi);
									resa = ar;
									resb = br;
								}
							}
						}
					}
				}
			}
		}
		
		cout<<resa<<' '<<resb<<endl;
	}
	return 0;
}