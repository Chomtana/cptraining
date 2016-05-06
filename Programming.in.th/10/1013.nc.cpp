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

typedef long long ll;
typedef pair<int,int> pii;

struct node {
    int start,end; //[start,end) , len=end-start
    vector<int> next;
};

vector<node> V(1);
string s;

void initG(int curr) {
    int blevel = 0; //() level
    string currs = s.substr(V[curr].start,V[curr].end-V[curr].start);
    
    int realsstart = 0;
    int realsend = currs.size();
    while (currs[realsstart]=='('&&currs[currs.size()-1-realsstart]==')') {
        realsstart++;
        realsend--;
        
        node n;
        n.start = V[curr].start+1;
        n.end = V[curr].end-1;
        V[curr].next.push_back(V.size());            
        V.push_back(n);
        
        curr = V.size()-1;
    }
    currs = currs.substr(realsstart,realsend-realsstart);
    
    int currstart = 0;
    
    for1(i,0,currs.size()) {
        if (currs[i]=='(') {
            blevel++;
        }
        if (currs[i]==')') {
            blevel--;
        }
        if (currs[i]=='+' && blevel == 0) {
            node n;
            n.start = V[curr].start+currstart;
            n.end = V[curr].start+i;
            V[curr].next.push_back(V.size());            
            V.push_back(n);
            
            currstart = i+1;
        }
    }
    
    if (currstart==0) { //no +
        for1(i,0,currs.size()) {
            if (currs[i]=='(') {
                blevel++;
            }
            if (currs[i]==')') {
                blevel--;
            }
            if (currs[i]=='*' && blevel == 0) {
                node n;
                n.start = V[curr].start+currstart;
                n.end = V[curr].start+i;
                V[curr].next.push_back(V.size());            
                V.push_back(n);
                
                currstart = i+1;
            }
        }
        if (currstart==0) { //no *
            for1(i,0,currs.size()) {
                if (currs[i]=='(') {
                    blevel++;
                }
                if (currs[i]==')') {
                    blevel--;
                }
                if (currs[i]=='^' && blevel == 0) {
                    node n;
                    n.start = V[curr].start+currstart;
                    n.end = V[curr].start+i;
                    V[curr].next.push_back(V.size());            
                    V.push_back(n);
                    
                    currstart = i+1;
                }
            }
            if (currstart==0) { //no ^
                //()
                for1(i,0,currs.size()) {
                    if (currs[i]=='(') {
                        if (blevel==0) {
                            node n;
                            n.start = V[curr].start+currstart;
                            n.end = V[curr].start+i;
                            V[curr].next.push_back(V.size());            
                            V.push_back(n);
                            
                            currstart=i;
                        }
                        blevel++;
                    }
                    if (currs[i]==')') {
                        blevel--;
                        if (blevel==0) {
                            node n;
                            n.start = V[curr].start+currstart;
                            n.end = V[curr].start+i+1;
                            V[curr].next.push_back(V.size());            
                            V.push_back(n);
                            
                            currstart = i+1;
                        }
                    }
                    /*if (currs[i]=='^' && blevel == 0) {
                        node n;
                        n.start = V[curr].start+currstart;
                        n.end = V[curr].start+i;
                        V[curr].next.push_back(V.size());            
                        V.push_back(n);
                        
                        currstart = i+1;
                    }*/
                }
                if (currstart==0) { //no () = no everything
                    return;
                } else {
                    node n;
                    n.start = V[curr].start+currstart;
                    n.end = V[curr].start+currs.size();
                    V[curr].next.push_back(V.size());            
                    V.push_back(n);
                }
            } else {
                node n;
                n.start = V[curr].start+currstart;
                n.end = V[curr].start+currs.size();
                V[curr].next.push_back(V.size());            
                V.push_back(n);
            }
        } else {
            node n;
            n.start = V[curr].start+currstart;
            n.end = V[curr].start+currs.size();
            V[curr].next.push_back(V.size());            
            V.push_back(n);
        }
    } else {
        node n;
        n.start = V[curr].start+currstart;
        n.end = V[curr].start+currs.size();
        V[curr].next.push_back(V.size());            
        V.push_back(n);
    }
    
    for1(i,0,V[curr].next.size()) {
        initG(V[curr].next[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout<<fixed;
    cin>>s;
    //root.s=s;
    
    V[0].start = 0;
    V[0].end = s.size();
    initG(0);
    
    int t; cin>>t;
    while (t--) {
        vector<int> get;
        
        int in; cin>>in;
        while (in!=0) {
            get.push_back(in);
            
            
            cin>>in;
        }
        
        int curr = 0;
        string res = "null";
        bool donext = true;
        for1(i,0,get.size()) {
            //cout<<"op("<<get[i]<<",";
            bool dosetcurr = true;
            if (get[i]>V[curr].next.size()) {
                if (get[i]==1) {
                    dosetcurr = false;
                } else {
                    donext = false;
                
                    break;
                }
            }
            if (dosetcurr) {
                curr=V[curr].next[get[i]-1];
            }
            
        }
        
        if (donext) {
            res = s.substr(V[curr].start,V[curr].end-V[curr].start);
        }
        
        print:
        for2(i,get.size(),0) {
            cout<<"op("<<get[i]<<",";
        }
        cout<<"p";
        for1(i,0,get.size()) {
            cout<<')';
        }
        cout<<'=';
        cout<<res;
        cout<<endl;
        
        
    }
    
    //cout<<V[0].next.size();
    
    return 0;
}