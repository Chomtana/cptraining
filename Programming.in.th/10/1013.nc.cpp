#include <bits/stdc++.h>

#define for1(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define for2(i,a,b) for(int (i)=(a)-1;(i)>=(b);(i)--)
#define for3(i,a,b,c) for(int (i)=(a);(i)<(b);(i)+=(c))
#define for4(i,a,b,c) for(int (i)=(a)-1;(i)>=(b);(i)-=(c))
#define debugv1(v) for1(_____,0,v.size()) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv2(v,size) for1(_____,0,size) cout<<(v)[_____]<<' '; cout<<endl;
#define debugv3(v,s,e) for1(_____,s,e) cout<<(v)[_____]<<' '; cout<<endl;

#define pcopy(type,from,to) to=(type*)malloc(sizeof(*from)); memcpy(to,from,sizeof(*from));

using namespace std;

struct node {
    string s;
    vector<node*> next;
}

node root;

void initG(node* n) {
    string s = n->s;
    string curr = "";
    for1(i,0,s.size()) {
        if (s[i]=='+') {
            n->next.push_back(NULL);
            node x;
            x.s = curr;
            pcopy(node,x,n->next[n->next.size()-1])
        } else {
            curr+=s[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout<<fixed;
    string s; cin>>s;
    root.s=s;
    initG(&root);
    int t; cin>>t;
    while (t--) {
        int in; cin>>in;
        while (in!=0) {
            
            
            
            cin>>in;
        }
    }
    
    return 0;
}