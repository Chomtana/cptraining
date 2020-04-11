#include <iostream>
#include <vector>

using namespace std;

class avl {
    class node {
        friend class avl;

    public:

        int data;
        node* left;
        node* right;
        node* parent;
        int height;

        node(): data(0), left(NULL), right(NULL), parent(NULL), height(0) {}
        node(int data, node* left, node* right, node* parent): data(data), left(left), right(right), parent(parent), height(0) {
            set_height();
        }

    protected:

        int get_height(node* n) {
            if (n==NULL) return -1;
            return n->height;
        }

        void set_height() {
            height = max(get_height(left), get_height(right)) + 1;
        }

        int balance_value() {
            return get_height(right) - get_height(left);
        }

        void set_left(node* n) {
            left = n;
            if (left != NULL) left->parent = this;
        }

        void set_right(node* n) {
            right = n;
            if (right != NULL) right->parent = this;
        }
    };

    node* successor(node* n) {
        if (n == NULL) return NULL;
        if (n->right == NULL) {
            node* curr = n->parent;
            while (curr != NULL) {
                if (curr->data > n->data) {
                    return curr;
                }

                curr = curr->parent;
            }
            return NULL;
        } else {
            node* curr = n->right;
            while(curr->left != NULL) {
                curr = curr->left;
            }
            return curr;
        }
    }

public:
    node* root;

    avl() {
        root = new node();
    }

    void print(node* n) {
        if (n==NULL) return;
        print(n->left);
        cout<<n->data<<' ';
        print(n->right);
    }

    void print() {
        print(root);
        cout<<endl;
    }

    node* insert(int val) {
        node* curr = root;
        node* prev = NULL;
        if (curr == NULL) return root = new node(val, NULL, NULL, NULL);
        while (curr != NULL) {
            prev = curr;

            if (curr->data == val) return curr;
            if (curr->data < val) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }

        if (val > prev->data) {
            prev->right = new node(val, NULL, NULL, prev);
            return prev->right;
        } else {
            prev->left = new node(val, NULL, NULL, prev);
            return prev->left;
        }

    }

    void erase(int val) {
        node* curr = root;
        if (curr == NULL) return;
        while (curr != NULL) {
            if (val == curr->data) {
                if (curr->left == NULL || curr->right == NULL) {
                    if (curr == curr->parent->left) {
                        curr->parent->left = (curr->left == NULL ? curr->right : curr->left);
                    } else {
                        curr->parent->right = (curr->left == NULL ? curr->right : curr->left);
                    }
                    delete curr;
                } else {
                    node* succ = successor(curr);
                    int temp = succ->data;
                    erase(temp);
                    curr->data = temp;
                }
                return;
            }
            if (val > curr->data) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }



        return;
    }

    node* rotate_left_child(node* n) {
        node* lr = n->left->right;
        node* l = n->left;
        node* p = n->parent;

        l->set_right(n);
        n->set_left(lr);

        n->set_height();
        l->set_height();

        l->parent = p;

        return l;
    }

    node* rotate_right_child(node* n) {
        node* r = n->right;
        node* rl = n->right->left;
        node* p = n->parent;

        r->set_left(n);
        n->set_right(rl);

        n->set_height();
        r->set_height();

        r->parent = p;

        return r;
    }

    node* rebalance(node* n) {
        int bv = n->balance_value();
        if (bv>1) {
            if (n->right->balance_value()<0) {
                rotate_left_child(n->right);
                rotate_right_child(n);
            } else {
                return rotate_right_child(n);
            }
        } else if (bv<-1) {
            if (n->left->balance_value()>0) {
                rotate_right_child(n->left);
                rotate_left_child(n);
            } else {
                return rotate_left_child(n);
            }
        }
    }


};

class linklist {
    public:
    class node {
        friend class linklist;

        int data;
        node* next;
        node* prev;

        node(): data(0), next(this), prev(this) {}
        node(int data, node* next, node* prev): data(data), next(next), prev(prev) {}
    };

    class iterator {
        friend class linklist;

    protected:
        node* ptr;

    public:

        iterator(): ptr(NULL) {}
        iterator(node* n): ptr(n) {}

        iterator& operator ++() {
            ptr = ptr->next;
            return *this;
        }

        iterator& operator --() {
            ptr = ptr->prev;
            return *this;
        }

        iterator operator ++(int) {
            iterator tmp(*this);
            operator++();
            return tmp;
        }

        iterator operator --(int) {
            iterator tmp(*this);
            operator--();
            return tmp;
        }

        int& operator*() { return ptr->data; }
        int* operator->() { return &(ptr->data); }

        bool operator ==(iterator& other) { return this->ptr == other.ptr; }
        bool operator !=(iterator& other) { return this->ptr != other.ptr; }
    };

    node* mHeader;
    size_t mSize;

    linklist(): mHeader(new node()), mSize(0) {}

    bool empty() const {
        return mSize == 0;
    }

    iterator begin() {
        return iterator(mHeader->next);
    }

    iterator end() {
        return iterator(mHeader);
    }

    iterator find(int val) {
        node* curr = mHeader->next;
        while (curr != mHeader) {
            if (curr->data == val) return iterator(curr);
            curr = curr->next;
        }
    }

    iterator insert(iterator it, int val) {
        node* n = new node(val, it.ptr, it.ptr->prev);
        it.ptr->prev->next = n;
        it.ptr->prev = n;

        mSize++;

        return n;
    }

    iterator insert(int val) {
        insert(end(), val);
    }

    iterator erase(iterator it) {
        node* prev = it.ptr->prev;
        node* next = it.ptr->next;

        it.ptr->prev->next = next;
        it.ptr->next->prev = prev;

        delete it.ptr;
        mSize--;

        return iterator(next);
    }

    iterator erase(int val) {
        erase(find(val));
    }

    void print(iterator s, iterator e) {
        for(auto it = s;it!=e;it++) {
            cout<<*it<<' ';
        }
        cout<<endl;
    }

    void print() {
        print(begin(), end());
    }
};

class priority_queue {
public:
    vector<int> mData;
    size_t mSize;
    size_t mCap;

    priority_queue() {
        mSize = 0, mCap = 1;
        //mData = new int[mCap];
        mData = vector<int>();
    }

    bool empty() {
        return mSize == 0;
    }

    void fixUp(int p) {
        while (p>0) {
            if (mData[p] > mData[(p-1)/2]) {
                swap(mData[p], mData[(p-1)/2]);
            } else {
                break;
            }
        }
    }

    void fixDown(int p) {
        while (true) {
            p = 2*p+1;
            if (p>=mSize) break;
            if (p+1 < mSize && mData[p+1] > mData[p]) {
                p++;
            }

            if (mData[p] > mData[(p-1)/2]) {
                swap(mData[p], mData[(p-1)/2]);
            } else {
                break;
            }
        }
    }

    int top() {
        return mData[0];
    }

    void push(int val) {
        mData.push_back(val);

        fixUp(mSize);

        mSize++;
    }

    void pop() {
        mData[0] = mData[mSize-1];
        mData.pop_back();

        fixDown(0);

        mSize--;
    }

    void print() {
        priority_queue pq = *this;
        vector<int> data;
        while (!pq.empty()) {
            data.push_back(pq.top());
            pq.pop();
        }

        for(auto &x: data) cout<<x<<' ';
        cout<<endl;


    }

};

int main()
{
    cout << "Hello world!" << endl;
    avl t;
    t.insert(5);
    t.insert(8);
    t.insert(1);
    t.insert(2);
    t.print();
    t.erase(5);
    t.erase(2);
    t.erase(999);
    t.print();

    cout<<endl;

    linklist l;
    l.insert(9);
    l.insert(3);
    l.insert(5);
    l.print();
    l.insert(++l.begin(), 8);
    l.print();
    l.insert(l.begin(), 1);
    l.print();

    priority_queue pq;
    pq.push(5);
    pq.push(3);
    pq.print();
    pq.print();
    pq.pop();
    pq.print();
    pq.push(5);
    pq.push(8);
    pq.push(1);
    pq.push(2);
    pq.print();
    pq.pop();
    pq.pop();
    pq.print();

    return 0;
}
