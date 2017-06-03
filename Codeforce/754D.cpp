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
typedef pair<pii,int> piii;
typedef vector<int> vi;

piii data[500005];

pii getpush(piii &p) {
	return mp(p.first.second,p.second);
}

void process() {

}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int n,k; cin>>n>>k;
	for1(i,0,n) {
		scanf("%d%d",&data[i].first.first,&data[i].first.second);
		data[i].second = i+1;
	}
	
	//kow rung mai tong mark -> write leoi
	//crit case k=1
	if (k==1) {
		vector<int> x(n);
		for1(i,0,n) {
			x[i] = abs(data[i].first.second-data[i].first.first+1);
		}
		auto it = max_element(all(x));
		cout<<*it<<endl<<it-x.begin()+1;
		return 0;
	}
	
	sort(data,data+n);
	

	
	int res = -1;
	int resi = -1;
	
	{
		priority_queue<pii,vector<pii>,greater<pii>> getter;
		priority_queue<pii> fail;
		for1(i,1,n) {
			fail.push(getpush(data[i-1]));
			
			while(!fail.empty() && getter.size()<k-1) {
				getter.push(fail.top());
				fail.pop();
			}
			
			while(!fail.empty() && fail.top()>getter.top()) {
				pii f = fail.top();
				pii g = getter.top();
				fail.pop();
				getter.pop();
				fail.push(g);
				getter.push(f);
			}
			
			if (getter.size()==k-1) {
				int mine = getter.top().first;
				mine = min(mine,data[i].first.second);
				int subres = mine-data[i].first.first+1;
				if (subres<0) {
					subres = 0;
				}
				if (subres>res) {
					res = subres;
					resi = i;
				}
			}
		}
	}
	
	cout<<res<<endl;
	
	{
		priority_queue<pii,vector<pii>,greater<pii>> getter;
		priority_queue<pii> fail;
		for1(i,1,n) {
			fail.push(getpush(data[i-1]));
			
			while(!fail.empty() && getter.size()<k-1) {
				getter.push(fail.top());
				fail.pop();
			}
			
			while(!fail.empty() && fail.top()>getter.top()) {
				pii f = fail.top();
				pii g = getter.top();
				fail.pop();
				getter.pop();
				fail.push(g);
				getter.push(f);
			}
			
			if (i==resi) {
				while (!getter.empty()) {
					printf("%d ",getter.top().second);
					getter.pop();
				}
				printf("%d",data[i].second);
				break;
			}
			
			/*if (getter.size()==k-1) {
				int mine = getter.top().first;
				mine = min(mine,data[i].first.second);
				int subres = mine-data[i].first.first+1;
				if (subres<0) {
					subres = 0;
				}
				if (subres>res) {
					res = subres;
					resi = i;
				}
			}*/
		}
	}
	
	//crit case k=1
	return 0;
}
