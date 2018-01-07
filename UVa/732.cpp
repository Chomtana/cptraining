#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

vector<int> data;
stack<char> st;
string s,t;
string::iterator it;
string res = "";


void recur(int c) {
	if (c>=2*s.size()) {
		//cerr<<res<<endl;
		if (res==t) {
			for1(i,0,2*s.size()) {
				printf("%c",(data[i]==1?'i':'o'));
				if (i!=2*s.size()-1) printf(" ");
			}
			printf("\n");
		}
		return;
	}
	if (it!=s.end()) {
		data.push_back(1);
		/*for1(i,0,2*s.size()) {
			printf("%d ",data[i]);
		}
		printf("\n");*/
		st.push(*it);
		//cerr<<*it<<endl;
		it++;
		recur(c+1);
		data.pop_back();
		st.pop();
		it--;
	}

	if (st.size()>0) {
		data.push_back(2);
		char olddata = st.top();
		st.pop();
		res += olddata;
		if (res[res.size()-1]==t[res.size()-1]) {
			recur(c+1);
		}
		data.pop_back();
		st.push(olddata);
		res.pop_back();

	}
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;

    while (cin>>s>>t) {
		//data.resize(s.size()*2+5);
		//cerr<<s<<endl;
		puts("[");
		it = s.begin();
		recur(0);
		puts("]");
    }
	return 0;
}
