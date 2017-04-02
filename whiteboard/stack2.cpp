#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int doublei = 0;
int singlei = 0;

bool isopen(char c) {
    if(c=='(' || c=='{' || c=='<' || c=='[') return true;
    if(c=='\'' && singlei%2==0) return true;
    if(c=='"' && doublei%2==0) return true;
    return false;
}

bool isclose(char c) {
    if(c==')' || c=='}' || c=='>' || c==']') return true;
    if(c=='\'' && singlei%2==1) return true;
    if(c=='"' && doublei%2==1) return true;
    return false;
}

bool main2() {
    stack<char> data;
    string s; getline(cin,s);
    for1(i,0,s.size()) {
        if (isopen(s[i])) {
            data.push(s[i]);
        } else if (isclose(s[i])) {
            char c = data.top();
            if (s[i]==')') if(c!='(') return false;
            if (s[i]=='}') if(c!='{') return false;
            if (s[i]==']') if(c!='[') return false;
            if (s[i]=='>') if(c!='<') return false;
            if (s[i]=='"') if(c!='"') return false;
            if (s[i]=='\'') if(c!='\'') return false;

            data.pop();
        }
        if (s[i]=='\'') singlei++;
        if (s[i]=='"') doublei++;
    }
    return (data.size()==0);
}

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    if (main2()) {
        cout<<"Balance!";
    } else cout<<"Not Balance!";
	return 0;
}
