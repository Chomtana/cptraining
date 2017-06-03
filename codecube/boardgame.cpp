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
//typedef pair<pair<int,int>,int> statetype;
typedef vector<int> vi;

class statetype {
	public:
	int r,c,key,walk;
	
	statetype(int i,int j,int k,int l) {
		r = i;
		c = j;
		key = k;
		walk = l;
	}
};

char data[505][505];
int nr,nc;
int sr,sc,er,ec;
bool visited[505][505][1<<3]; //geb state cal next

int getwant(int i,int j) { //want index <ret val> = true
	switch(data[i][j]) {
		case 'J': return 0;
		case 'B': return 1;
		case 'P': return 2;
	}
	return -1;
}

int getset(int i,int j) { //want index <ret val> = true
	switch(data[i][j]) {
		case 'j': return 0;
		case 'b': return 1;
		case 'p': return 2;
	}
	return -1;
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
	cin>>nr>>nc;
	for1(i,0,nr) scanf("%s",data+i);
	
	for1(i,0,nr) for1(j,0,nc) if(data[i][j]=='S') {
		sr=i; sc=j;
	} else if (data[i][j]=='E') {
		er=i; ec=j;
	}
	
	//cerr<<sr<<' '<<sc<<endl;
	
	queue<statetype> q;
	q.push(statetype(sr,sc,0,0));
	while (!q.empty()) {
		int cr = q.front().r;
		int cc = q.front().c;
		int key = q.front().key;
		int walk = q.front().walk;
		
		q.pop();
		
		if (data[cr][cc]=='E') {
			cout<<walk<<endl; return 0;
		}
		
		int findkey = getset(cr,cc);
		if(findkey!=-1) {
			key |= (1<<findkey);
		}
		
		//cerr<<cr<<' '<<cc<<' '<<key<<' '<<walk<<endl;
		
		visited[cr][cc][key] = true;
		
		int dr[] = {0,0,1,-1};
		int dc[] = {1,-1,0,0};
		for1(i,0,4) {
			int ner = cr+dr[i];
			int nec = cc+dc[i];
			if (ner>=0 && nec>=0 && ner<nr && nec<nc) {
				int want = getwant(ner,nec);
				//cerr<<"--- "<<want<<' '<<ner<<' '<<nec<<endl;
				if (want==-1) {
					if (data[ner][nec]!='#' && !visited[ner][nec][key]) {
						visited[ner][nec][key] = true;
						q.push(statetype(ner,nec,key,walk+1));
					}
				} else {
					bool ok = key & (1<<want);
					//cerr<<' '<<ok;
					if (ok) {
						if (data[ner][nec]!='#' && !visited[ner][nec][key]) {
							visited[ner][nec][key] = true;
							q.push(statetype(ner,nec,key,walk+1));
						}
					}
				}
			}
		}
		
		//cerr<<endl;
	}
	
	cout<<-1<<endl;
	
	return 0;
}
