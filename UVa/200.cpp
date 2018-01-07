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

vector<string> data;
int maxlen = 0;

vector<int> E[30];
bool visited[30];
bool has[30];

//stack<int> topo;

void process(int c) {
    if(c>=maxlen) return;
    for1(i,0,data.size()) {
        if (data[i].size()<=c) continue;
        for1(j,i+1,data.size()) {
            if (data[i].size()<=c || data[j].size()<=c) continue;
            if (c>0 && (data[i].substr(0,c)!=data[j].substr(0,c))) break;
            if (data[i][c]!=data[j][c]) {
                E[data[j][c]-'A'].push_back(data[i][c]-'A');
            }

        }
        if (data[i].size()>c) {
            has[data[i][c]-'A'] = true;
        }
    }

    process(c+1);
}

void dotopo(int c) {
    if (visited[c]) return;
    visited[c] = true;
    for1(i,0,E[c].size()) {
        int ne = E[c][i];
        dotopo(ne);
    }

    printf("%c",c+'A');
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    string s = "";
    while(cin>>s&&s!="#") {
            //cerr<<"aaa"<<endl;
        data.push_back(s);
        maxlen = max(maxlen,int(s.size()));
    }

    //cerr<<"bbb "<<s<<endl;

    if (s!="#") return 0;

    process(0);

    for1(i,0,30) {
        if (!visited[i] && has[i]) {
            dotopo(i);
        }
    }

    printf("\n");

    for1(i,0,30) {
        E[i].clear();
        data.clear();
        has[i] = false;
        visited[i] = false;
    }
    main();


	return 0;
}
