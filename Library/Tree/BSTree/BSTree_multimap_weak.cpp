#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

//map<int,int> tree;
//critical case found: integer overflow ;       if build binary tree like linked list then it can only hold up to 63 tua
                                            //  (if use long long) because it has index 2^63
                                            //  useful it it is balanced binary tree

//max 100 element each node because c++ oop is weak ; cannot do dynamic oop resize
class Node {
    public:
    Node* left = NULL;
    Node* right = NULL;
    Node* parent = NULL;
    int key;
    string val[100];
    int insptr = 0;
    int size = 0;

    Node() {}
    Node(int k) {key = k;}
    Node(int k,string v) {key = k; val[insptr] = v; insptr++; size++;}

    void insert(string v) {
        val[insptr] = v;
        insptr++;
        size++;
    }

    void remove(string v) {
        for1(i,0,insptr) {
            if (val[i]==v) {
                val[i]="";
                size--;
            }
        }
        //insptr--;

    }

    //int size() {return insptr;}
};

ostream& operator << (ostream& os,Node* n) {
    sort(n->val,n->val+n->insptr);
    for1(i,0,n->insptr) {
        if (n->val[i]!="") os << n->val[i] << ' ';
    }
    return os;
}

//BSTree_multimap_weak (unbalanced multimap BSTree (allow duplicate element))
//max 100 element each node because c++ oop is weak ; cannot do dynamic oop resize
class BSTree {
    public:

    Node* root = NULL;

    BSTree() {

    }

    void insert(Node*& curr,int x,string val) {
        if (root==NULL) {
            root = new Node(x,val);
            return;
        }

        if (x<curr->key) {
            if (curr->left == NULL) {
                curr->left = new Node(x,val);
                curr->left->parent = curr;
            } else {
                insert(curr->left,x,val);
            }
        } else if (x>curr->key) {
            if (curr->right==NULL) {
                curr->right = new Node(x,val);
                curr->right->parent = curr;
            } else {
                insert(curr->right,x,val);
            }
        } else {
            curr->insert(val);
        }
    }

    void insert(int x,string val) {
        insert(root,x,val);
    }

    void preorder(Node* curr) {
        if (curr==NULL) return;
        cout<<curr->key<<'('<<curr->size<<')'<<' ';
        preorder(curr->left);
        preorder(curr->right);
    }

    void inorder(Node* curr) {
        if (curr==NULL) return;

        inorder(curr->left);
        cout<<curr->key<<'('<<curr->size<<')'<<' ';
        inorder(curr->right);
    }

    void postorder(Node* curr) {
        if (curr==NULL) return;

        postorder(curr->left);
        postorder(curr->right);
        cout<<curr->key<<'('<<curr->size<<')'<<' ';
    }

    void preorder() {
        preorder(root);
    }

    void inorder() {
        inorder(root);
    }

    void postorder() {
        postorder(root);
    }

    Node* find(Node* curr,int x) {
        if (curr==NULL) return NULL;
        if (x<curr->key) {
            return find(curr->left,x);
        } else if (x>curr->key) {
            return find(curr->right,x);
        } else {
            return curr;
        }
    }

    Node* find(int x) {return find(root,x);}

    Node* findmax(Node* curr) {
        if (root==NULL) return NULL;
        if (curr->right == NULL) {
            return curr;
        }
        return findmax(curr->right);
    }

    void remove(Node*& curr,int x,string val) {
        if (curr==NULL) return;

        if (curr==root) {
            Node *n = find(root,x);
            if (n) {
                n->remove(val);
                if (n->size>0) return;
            }
        }

        if (x<curr->key) {
            remove(curr->left,x,val);
        } else if (x>curr->key) {
            remove(curr->right,x,val);
        } else if (curr->left!=NULL && curr->right!=NULL) {
            Node* y = findmax(curr->left);
            curr->key = y->key;
            for1(i,0,100) {
                curr->val[i] = y->val[i];
            }
            curr->insptr = y->insptr;
            curr->size = y->size;
            remove(curr->left,y->key,val);
        } else {
            Node* temp = curr;
            if (curr->left == NULL) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }

            delete temp;
        }

    }

    void remove(int x,string val) {remove(root,x,val);}
};





int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
    string s;
    BSTree tree;
    while (cin>>s,s!="X") {
        int arg; cin>>arg;
        string arg2;
        Node* n;
        switch (s[0]) {
        case 'I':
            cin>>arg2;
            tree.insert(arg,arg2);
            //cout<<"aaa"<<N[0].val<<endl;
            break;
        case 'P':
            if (arg==1) {
                tree.inorder();
            } else if (arg==2) {
                tree.preorder();
            } else {
                tree.postorder();
            }
            cout<<endl;
            break;
        case 'F':
            n = tree.find(arg);
            if (n) {
                cout<<"Y "<<n->size<<' '<<n<<endl;
            } else {
                cout<<"N";
            }
            cout<<endl;
            break;
        case 'R':
            cin>>arg2;
            tree.remove(arg,arg2);
            break;
        }
    }
	return 0;
}

/*
I 5
zheng
I 3
oliver
I 8
puma
I 9
xi
I 3
dang
I 8
sammy
I 8
kong
F 8
R 8
vivian
F 8
P 1
R 8
puma
F 8
P 1
R 8
sammy
F 8
R 8
kong
F 8
P 1
R 3
sport
F 3
P 1
R 3
dang
F 3
R 3
dang
F 3
P 1
X 0
*/
