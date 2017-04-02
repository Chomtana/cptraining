#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

string base;

class Node {
    public:
    int s,e; //[s,e)
    Node* next[100] = {NULL};
    int insptr = 0;

    Node() {}

    Node(int ss,int ee) {
        s = ss;
        e = ee;
    }

    void addnext(int ss,int ee) {
        Node* n = new Node(ss,ee);
        next[insptr] = n;
        insptr++;
        //next.push_back(N.size());

    }

    void processnext(char c) {
        int ps = s;
        int braclv = 0;
        for1(i,s,e) {
            if (base[i]=='(') braclv++; else if (base[i]==')') braclv--;
            if (base[i]==c && braclv == 0) {
                addnext(ps,i);
                //cout<<ps<<' '<<i<<' ';
                ps = i+1;
            }
        }
        addnext(ps,e);
    }

    Node* operator [](int i) {
        //return (i>=insptr?NULL:next[i]);
        return next[i];
    }

    int size() {return insptr;}

};

void process(Node* n) {
    bool hasbrac = true;
    bool hassum = false;
    bool hasmul = false;
    bool haspow = false;

    int braclv = 0;

    int s = n->s,e = n->e;
    int len = e-s;

    for1(i,s,e) {
        if (base[i]=='(') braclv++; else if (base[i]==')') braclv--;
        if (braclv==0) {
            if (i != e-1 || len==1) {
                hasbrac = false;
            }
            if (base[i]=='+') {
                hassum = true;
            } else if (base[i] == '*') {
                hasmul = true;
            } else if (base[i] == '^') {
                haspow = true;
            }
        }
    }

    if (hasbrac) {
        n->addnext(s+1,e-1);
    } else if (hassum) {
        n->processnext('+');
    } else if (hasmul) {
        n->processnext('*');
    } else if (haspow) {
        n->processnext('^');
    }

    for1(i,0,n->size()) {
        process((*n)[i]);
    }
}

int main() {
	//ios::sync_with_stdio(false);
	//cout<<fixed;
	cin>>base;

	Node *head = new Node(0,base.size());

	process(head);

    int t; scanf("%d",&t);
    while (t--) {
        int in;
        Node* curr = head;
        stack<int> inarr;
        while(scanf("%d",&in),in!=0) {
            inarr.push(in);
            if (curr == NULL) continue;
            if (curr->size()==0 && in==1) continue;
            in--;
            //if (in<curr->size()) {
            curr = (*curr)[in];
            //} else curr=NULL;
        }
        int inarrsize = inarr.size();
        while (!inarr.empty()) {
            printf("op(%d,",inarr.top());
            inarr.pop();
        }
        printf("p");
        for1(i,0,inarrsize) printf(")");
        printf("=");
        if (curr==NULL) {
            printf("null");
        } else {
            for1(i,curr->s,curr->e) {
                printf("%c",base[i]);
            }
        }
        printf("\n");
    }

	return 0;
}
