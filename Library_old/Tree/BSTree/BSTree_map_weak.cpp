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

class Node {
    public:
    Node* left = NULL;
    Node* right = NULL;
    Node* parent = NULL;
    int key;
    string val;

    Node() {}
    Node(int k) {key = k;}
    Node(int k,string v) {key = k; val = v;}
};

//BSTree_map_weak (unbalanced map BSTree (no duplicate element))
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
        }
    }

    void insert(int x,string val) {
        insert(root,x,val);
    }

    void preorder(Node* curr) {
        if (curr==NULL) return;
        cout<<curr->key<<':'<<curr->val<<' ';
        preorder(curr->left);
        preorder(curr->right);
    }

    void inorder(Node* curr) {
        if (curr==NULL) return;

        inorder(curr->left);
        cout<<curr->key<<':'<<curr->val<<' ';
        inorder(curr->right);
    }

    void postorder(Node* curr) {
        if (curr==NULL) return;

        postorder(curr->left);
        postorder(curr->right);
        cout<<curr->key<<':'<<curr->val<<' ';
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

    void remove(Node*& curr,int x) {
        if (curr==NULL) return;

        if (x<curr->key) {
            remove(curr->left,x);
        } else if (x>curr->key) {
            remove(curr->right,x);
        } else if (curr->left!=NULL && curr->right!=NULL) {
            Node* y = findmax(curr->left);
            curr->key = y->key;
            curr->val = y->val;
            remove(curr->left,y->key);
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

    void remove(int x) {remove(root,x);}
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
            cout<<(n?n->val:"N")<<endl;
            break;
        case 'R':
            tree.remove(arg);
            break;
        }
    }
	return 0;
}

/*
I 5
Jame
I 9
Adam
I 3
Namtan
I 4
Anna
F 4
P 1
I 8
Furier
F 7
P 2
I 10
Vanisa
F 5
P 3
R 3
F 3
P 1
X 0
*/
