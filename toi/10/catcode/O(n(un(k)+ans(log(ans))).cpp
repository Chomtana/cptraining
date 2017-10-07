/**
hashing data structure unordered is best
custom write take time but wrose than unordered -> must use unordered in TOI13 don't use custom write
*/

//#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <utility>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define until(x) while(!(x))
#define all(x) x.begin(),x.end()
#define mp make_pair
#define subfunc(ret,name,args) function<ret args> name; name = [&] args

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
//typedef vector<int> vi;

int k,m,n;
char temp[1000005];

unordered_map<int,int> P(2100005);

//vector<pii> P[2100005];

/*int find(int key) { //P[hkey] mai chai P[key] ... hkey = key te mod leaw or aow key ma cal tarm sood dai sood nueng leaw
    //int res = -1;
    int hkey = key;
    if (hkey>=(1<<21)) {
        hkey >>= 9;
    }
    for1(i,0,P[hkey].size()) {
        if (P[hkey][i].first==key) return P[hkey][i].second;
    }
    return -1;
}*/

void parseP(int curr) {
    int h = 0;
    for1(i,0,m) {
        h <<= 1;
        h += temp[i]-'0';
    }
    //cerr<<(h==0b11100)<<endl;
    /*int hh = h;
    if (hh>=(1<<21)) {
        hh >>= 9;
    }*/
    P[h] = curr+1;
    //P[hh].push_back(mp(h,curr+1));
}

void check() {
    vector<int> res; //if only do sort,unique at end using vector is best

    int h = 0;
    for1(i,0,m) {
        h <<= 1;
        h += temp[i]-'0';
    }

    auto it = P.find(h);
    if (it!=P.end()) {
        res.push_back(it->second);
    }

    /*int subres = find(h);
    if(subres!=-1) res.push_back(subres);*/

    for1(i,1,n-m+1) {
        h -= (temp[i-1]-'0') * (1<<(m-1));
        h <<= 1;
        h += temp[i+m-1]-'0';
        it = P.find(h);
        if (it!=P.end()) {
            res.push_back(it->second);
        }

        /*int subres = find(h);
        if(subres!=-1) res.push_back(subres);*/
    }

    if (res.size()==0) {
        printf("OK\n");
        return;
    }

    sort(all(res));
    auto resend = unique(all(res));
    for(auto i = res.begin();i!=resend;i++) {
        printf("%d ",*i);
    }
    printf("\n");
}


int main() {
	//ios::sync_with_stdio(false);
	//cout<<fixed;
    scanf("%d%d",&k,&m);
    for1(i,0,k) {
        scanf("%s",temp);
        parseP(i);
    }

    //cerr<<(P.find(0b11100)!=P.end())<<endl;

    int t; scanf("%d",&t); while(t--) {
        scanf("%d",&n); scanf("%s",temp);
        check();
    }
	return 0;
}
