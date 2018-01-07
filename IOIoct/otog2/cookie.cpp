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

class node {
    public:
    int val;
    node* l;
    node* r;
};

int n;
int currval = 1;

node* root = new node();

//vector<string> input;
vector<node*> resptr;

void doval(node* c) {
    if (c==NULL) return;
    doval(c->l);
    c->val = currval++;
    doval(c->r);
}

int main() {
	//ios::sync_with_stdio(false);
	cout<<fixed;
    cin>>n;
    for1(i,0,n) {
        string s; cin>>s;
        //input.push_back(s);
        node* curr = root;
        for(char c:s) {
            if (c=='R') {
                if (curr->r == NULL) {
                    curr->r = new node();
                }
                curr = curr->r;
            } else if (c=='L') {
                if (curr->l == NULL) {
                    curr->l = new node();
                }
                curr = curr->l;
            }
        }
        resptr.push_back(curr);
    }

    doval(root);

    for1(i,0,n) {

        printf("%d\n",resptr[i]->val);
    }
	return 0;
}
