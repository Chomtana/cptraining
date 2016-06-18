#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

struct node {
	int s,e; //[s,e)
	vector<node> next;
};

node root;
string s;

bool is1(string &x) { //is (...)
	if (x[0]=='(') {
		int l = 1;
		for1(i,1,x.size()-1) {
			if (x[i]=='(') {
				l++;
			}
			if (x[i]==')') {
				l--;
			}
			if (l==0) {
				return false;
			}
		}
	} else {
		return false;
	}
	return true;
}

vector<string> split(string &x,char c) { //cheat because full version is very long
	stringstream ss(x);
	string y;
	vector<string> result;
	while(getline(ss,y,c)) {
		result.push_back(y);
	}
	return result;
}

/*void pp(node &n,string &x,char c) {
	vector<string> next = split(x,c);
	for1(i,0,next.size()) {
		node y;
		y.s = next[i];
		n.next.push_back(y);
	}
}*/

void pp(node &n,int i) {
	node y;
	y.s=(n.next.size()>0?n.next[n.next.size()-1].e+1:n.s);
	y.e=n.s+i;
	n.next.push_back(y);
}

void p(node &n) {
	string x = s.substr(n.s,n.e-n.s);

	if (is1(x)) {
		node y;
		y.s = n.s+1;
		y.e = n.e-1;
		n.next.push_back(y);

		p(n.next[0]);
		return;
	}

	int l = 0;
	int z = 3; //0:+ 1:* 2:^ 3:nothing

	for1(i,0,x.size()) {
		switch (x[i]) {
			case '(': l++; break;
			case ')': l--; break;
			case '+': if(z>0 && l==0) z=0; break;
			case '*': if(z>1 && l==0) z=1; break;
			case '^': if(z>2 && l==0) z=2; break;
		}
	}

	if (z==3) return;

	/*switch (z) {
		case 0: pp(n,x,'+'); break;
		case 1: pp(n,x,'*'); break;
		case 2: pp(n,x,'^'); break;
	}*/

	//cout<<z<<endl;
	l = 0;
	for1(i,0,x.size()) {
		switch (x[i]) {
			case '(': l++; break;
			case ')': l--; break;
			case '+': if (z==0 && l==0) {
				pp(n,i);
			} break;
			case '*': if (z==1 && l==0) {
				pp(n,i);
			}break;
			case '^': if (z==2 && l==0) {
				pp(n,i);
			}break;
		}
	}

	pp(n,x.size());

	for1(i,0,n.next.size()) {
		//cout<<n.next[i].s<<' '<<n.next[i].e<<endl;
		p(n.next[i]);
	}
}

int main() {
	getline(cin,s);

	root.s=0; root.e=s.size();
	p(root);

	int t; cin>>t;
	while (t--) {
		int in; cin>>in;
		node *n = &root;
		vector<int> v;
		bool ok=true;
		while(in!=0) {
			//cout<<n.next[in-1].s<<endl;
			if (in-1<n->next.size()) {
				n=&(n->next[in-1]);
			} else {
				if (in!=1) ok=false;
			}

			v.push_back(in);
			cin>>in;
		}

		for1(i,0,v.size()) {
			cout<<"op("<<v[v.size()-i-1]<<",";
		}
		cout<<"p";
		for1(i,0,v.size()) cout<<")";
		cout<<"=";
		if (ok) cout<<s.substr(n->s,n->e-n->s)/*<<' '<<n->s<<' '<<n->e*/<<endl; else cout<<"null"<<endl;
	}

	return 0;
}
