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

int n,m;
int data[100005];
int deleted[100005];
pii data2[100005];
int data2end;

vector<int> tempdel;

int del(int pos) {
	int res = 0;
	if (!deleted[pos]) {
		deleted[pos] = 1;
		tempdel.push_back(pos);
		res++;

		if (pos-1>=0 && !deleted[pos-1]) {
			deleted[pos-1] = 1;
			tempdel.push_back(pos-1);
			res++;
		}
		if (pos+1<n && !deleted[pos+1]) {
			deleted[pos+1] = 1;
			tempdel.push_back(pos+1);
			res++;
		}
	}
	if (deleted[pos]==1) {
		if (pos-1>=0 && !deleted[pos-1]) {
			deleted[pos-1] = 1;
			tempdel.push_back(pos-1);
			res++;
		}
		if (pos+1<n && !deleted[pos+1]) {
			deleted[pos+1] = 1;
			tempdel.push_back(pos+1);
			res++;
		}
	}
	return res;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	cin>>n>>m;
	data2end = n;
	for1(i,0,n) {
		scanf("%d",data+i);
		data2[i] = mp(data[i],i);
	}

	sort(data2,data2+n);

	while(m--) {
		int h; scanf("%d",&h);
		int s = upper_bound(data2,data2+n,mp(h,0))-data2;
		//beware of magic of pair search -> cannot do > / < only >= , <= because of second pair make it no equal state
		int res = 0;
		for1(i,s,data2end) {
			if (data2[i].first<=h) {
				s++;
				continue;
			} //fix like this
			res += del(data2[i].second);
			//cerr<<data2[i].second<<' ';
		}
		data2end = s;
		for(int i:tempdel) deleted[i]=2;
		tempdel.clear();
		printf("%d\n",res);
	}

	return 0;
}
