#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

class edge {
    public:
    string need;
    string res;
    int s,e;

    bool isok(char needa,char needb) {
        return (need[0]==needa && need[1]==needb);
    }

    edge(){}

    edge(int start,int end,string n,string r) {
        s = start;
        e = end;
        need = n;
        res = r;
    }
};

vector<edge> E[5];
int curr = 1;

string res = "";
string ressub = "";
int n;

void process(string &s) {
    //reverse(all(s));
    for(int i = s.size()-1;i>=0;i-=2) {
        //cout<<s[i-1]<<s[i]<<' ';
        if (E[curr][0].isok(s[i-1],s[i])) {
            ressub += E[curr][0].res;
            curr = E[curr][0].e;
        } else {
            ressub += E[curr][1].res;
            curr = E[curr][1].e;
        }
    }
    //cout<<endl<<ressub<<endl;
    reverse(all(ressub));
    res += strtol(ressub.c_str(),NULL,2);
    ressub = "";
}

void docurrmove(string &s) {
    //reverse(all(s));
    for(int i = s.size()-1;i>=0;i-=2) {
        if (E[curr][0].isok(s[i-1],s[i])) {
            curr = E[curr][0].e;
        } else {
            curr = E[curr][1].e;
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    E[1].push_back(edge(1,1,"00","0"));
    E[1].push_back(edge(1,3,"11","0"));
    E[3].push_back(edge(3,2,"10","0"));
    E[3].push_back(edge(3,4,"01","0"));
    E[4].push_back(edge(4,4,"10","1"));
    E[4].push_back(edge(4,2,"01","1"));
    E[2].push_back(edge(2,3,"00","1"));
    E[2].push_back(edge(2,1,"11","1"));
     cin>>n;
    string data[n];
    for1(i,0,n) cin>>data[i];
    reverse(data,data+n);
    if (data[0].size()!=16) {
        docurrmove(data[0]);
        //cout<<curr<<endl;
    } else {
        process(data[0]);
    }

    for1(i,1,n) {
        process(data[i]);
    }

    reverse(all(res));

    cout<<res;

	return 0;
}
