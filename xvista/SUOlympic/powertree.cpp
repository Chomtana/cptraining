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

struct node {
	int left=-1,right=-1;
	//int parent;
	int p;
	bool d = false;
};

node data[100005];
bool notroot[100005];
int root = -1;

int query_a(int curr) {
	if (curr==-1) return 0;
	if (data[curr].d) return 0;
	return data[curr].p+query_a(data[curr].left)+query_a(data[curr].right);
}

void disablenext(int curr) {
	if (curr==-1) return;
	data[curr].d=true;
	disablenext(data[curr].left);
	disablenext(data[curr].right);
}



int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	int n,k; cin>>n>>k;
	
	for1(i,0,n) {
		int p,l,r; scanf("%d%d%d",&p,&l,&r);
		l--; r--;
		data[i].p = p;
		if (l!=-1) {
			data[i].left = l;
			notroot[l] = true;
		}
		if (r!=-1) {
			data[i].right = r;
			notroot[r] = true;
		}
	}
	
	for1(i,0,n) if(!notroot[i]) {
		root = i;
		break;
	}
	
	//cerr<<root;
	
	while (k--) {
		char qtypes[3]; int target; scanf("%s %d",qtypes,&target);
		char qtype = qtypes[0];
		target--;
		if (qtype=='a') {
			if (data[target].d) {
				printf("0\n");
			} else {
				printf("%d\n",query_a(target));
			}
		} else {
			//data[target].d = true;
			disablenext(target);
		}
	}

	return 0;
}
