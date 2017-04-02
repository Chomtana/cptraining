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
    int val;

    Node() {}
    Node(int v) {val = v;}
};

//BSTree_multiset_weak (unbalanced set BSTree (allow duplicate element))
class BSTree {
    public:

    Node* root = NULL;

    BSTree() {

    }

    void insert(Node*& curr,int x) {
        if (root==NULL) {
            root = new Node(x);
            return;
        }

        if (x<curr->val) {
            if (curr->left == NULL) {
                curr->left = new Node(x);
                curr->left->parent = curr;
            } else {
                insert(curr->left,x);
            }
        } else { //>= -> = keb darn right
            if (curr->right==NULL) {
                curr->right = new Node(x);
                curr->right->parent = curr;
            } else {
                insert(curr->right,x);
            }
        }
    }

    void insert(int x) {
        insert(root,x);
    }

    int count(Node* curr,int x) {
        if (curr==NULL) return 0;

        if (curr->parent!=NULL && curr->val!=x && curr->parent->val == x) return 0;

        if (x<curr->val) {
            return count(curr->left,x);
        } else if (x>curr->val) {
            return count(curr->right,x);
        } else {
            return 1+count(curr->right,x);
        }
    }

    int count(int x) {return count(root,x);}

    void preorder(Node* curr) {
        if (curr==NULL) return;
        cout<<curr->val<<' ';
        preorder(curr->left);
        preorder(curr->right);
    }

    void inorder(Node* curr) {
        if (curr==NULL) return;

        inorder(curr->left);
        cout<<curr->val<<' ';
        inorder(curr->right);
    }

    void postorder(Node* curr) {
        if (curr==NULL) return;

        postorder(curr->left);
        postorder(curr->right);
        cout<<curr->val<<' ';
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
        if (x<curr->val) {
            return find(curr->left,x);
        } else if (x>curr->val) {
            return find(curr->right,x);
        } else {
            return curr;
        }
    }

    Node* find(int x) {return find(root,x);}

    int findmax(Node* curr) {
        if (root==NULL) return -1;
        if (curr->right == NULL) {
            return curr->val;
        }
        return findmax(curr->right);
    }

    void remove(Node*& curr,int x) {
        if (curr==NULL) return;

        if (x<curr->val) {
            remove(curr->left,x);
        } else if (x>curr->val) {
            remove(curr->right,x);
        } else if (curr->left!=NULL && curr->right!=NULL) {
            int y = findmax(curr->left);
            curr->val = y;
            remove(curr->left,y);
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
        switch (s[0]) {
        case 'I':
            tree.insert(arg);
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
            cout<<(tree.find(arg)?"Y":"N")<<endl;
            break;
        case 'R':
            tree.remove(arg);
            break;
        case 'C':
            cout<<tree.count(arg)<<endl;
            break;
        }
    }
	return 0;
}

/*
I 5
I 7
I 3
I 2
I 1
I 4
F 8
I 6
I 8
R 7
R 5
I 9
F 8
P 3
*/
