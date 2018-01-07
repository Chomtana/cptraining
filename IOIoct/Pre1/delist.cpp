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

int n,m;

struct node {
    int val;
    node* next;
    list<int> del;
    list<int> dedel;
};

node* root[100005];
node* tail[100005];

void print(node* c) {
    if (c==NULL) return;
    while (c!=NULL) {
        if (c->val<2E9) printf("%d\n",c->val);
        c = c->next;
    }
    //puts("");
}

void delbr(node* c,int val) {
    if (c==NULL) return;
    while (c!=NULL) {
        if (c->val==val) c->val=2E9;
        c = c->next;
    }
}

void del(int i,int val) {
    node* r = root[i];
    node* t = tail[i];
    r->del.push_back(val);
    t->dedel.push_back(val);
}

void dodel(node* c) {
    if (c==NULL) return;
    multiset<int> currdel;
    while (c!=NULL) {
        //cerr<<c->val<<" : ";
        for(auto i:c->del) {
            currdel.insert(i);
            //cerr<<i<<' ';
        }
        //cerr<<" | ";
        if (currdel.find(c->val)!=currdel.end()) c->val = 2E9;
        for(auto i:c->dedel) {
            currdel.erase(currdel.find(i));
            //cerr<<i<<' ';
        }
        //cerr<<endl;
        c = c->next;
    }
}

void mer(int i,int j) {
    if (tail[i]!=NULL) {
        tail[i]->next = root[j];
        tail[i] = tail[j];
    } else {
        root[i] = root[j];
        tail[i] = tail[j];
    }
    root[j] = NULL;
    tail[j] = NULL;

}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n>>m;

    for1(i,1,n+1) {
        int k; scanf("%d",&k);
        node* c = (root[i]=new node());
        scanf("%d",&c->val);
        for1(j,1,k) {
            c = (c->next = new node());
            scanf("%d",&c->val);
        }
        tail[i] = c;
    }

    while (m--) {
        int type,a,b; scanf("%d%d%d",&type,&a,&b);
        if (type==2) {
            mer(a,b);
        } else {
            //delbr(root[a],b);
            del(a,b);
        }
    }



    for1(i,1,n+1) {
        dodel(root[i]);
        print(root[i]);
    }
	return 0;
}
