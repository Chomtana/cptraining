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

#define maxn 10
#define minn 10

int rand(int a,int b) {
	if (a>b) swap(a,b);
	return (rand()%(b-a+1))+a;
}

int lv = 0;


vector<vector<int>> dogenold(int n) {
	srand(time(0));
	int add = 2;
	int curr = 1;
	vector<vector<int>> E(n+5);
	vector<int> P(n+5);
	P[1] = -1;
	
	while(add<=n) {
		/*
		we point at node curr and try to build <add> from node curr or move node curr
		a = 0 -> go up
		a = 1 -> build as child
		a = ... -> go down to edge a-2
		*/
		int a = rand(0,E[curr].size()+1);
		if (a==0) {
			if (P[curr]!=-1) {
				curr = P[curr];
			}
		} else if (a==1) {
			E[curr].push_back(add);
			P[add] = curr;
			add++;
		} else {
			curr = E[curr][a-2];
		}
	}
	
	return E;
}

//better (all case) , easier
//use select parent (do action by using something that has only one)
vector<vector<int>> dogen(int n) {
	srand(time(0));
	vector<vector<int>> E(n+5);
	for1(i,2,n+1) {
		E[rand(1,i-1)].push_back(i);
	}
	return E;
}

class print {
	public:
	vector<bool> visited;

	void doprint(vector<vector<int>>& E,int curr,int lv) {
		if (visited[curr]) return;
		visited[curr] = true;
		
		for1(i,0,lv) printf("--");
		printf("%d\n",curr);
		for1(i,0,E[curr].size()) {
			doprint(E,E[curr][i],lv+1);
		}
	}
	
	void operator()(vector<vector<int>>& E) {
		visited.resize(E.size(),false);
		doprint(E,1,0);
	}

};

void printEL(vector<vector<int>>& E) {
	for1(i,1,E.size()) {
		for1(j,0,E[i].size()) if (i<=E[i][j]) cout<<i<<' '<<E[i][j]<<endl;
	}
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;

	srand(time(0));
	int n = rand(minn,maxn);
	vector<vector<int>> E = dogen(n);
	
	cerr<<"n : "<<n<<endl;
	
	print()(E);
	//cout<<endl;
	printEL(E);
	
	//vector<int> kuy("dasasdsd");
	/*for1(i,0,E.size()) {
	
		cout<<i<<" : ";
		for1(j,0,E[i].size()) cout<<E[i][j]<<' ';
		cout<<endl;
	}*/
	return 0;
}
