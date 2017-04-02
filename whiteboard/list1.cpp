#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()
#define until(x) while(!(x))

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

template <typename T>
class Node {
    T info;
    Node* link;
public:

    Node() {link = NULL;}
    Node(T inf) {
        info = inf;
        link = NULL;
    }
    Node(T inf,Node *lnk) {
        info = inf;
        link = lnk;
    }
    void setInfo(T inf) { info = inf;}
    void setLink(Node* lnk) {link=lnk;}
    T getInfo() {return info;}
    Node* getLink() {return link;}
};

template<typename T>
class List {
private:
    Node<T> *head;
public:

    List(){head=NULL;}
    //void print();
    //Node<T>* begin();
    Node<T>* end();
    //void insertHead(T info);
    //void insertTail(T info);
    //void insertSort(T info);
    void insertSort(T info[],int num);
    //void deleteHead();
    //void deleteTail();
    //void deleteInfo(T info);

    void print() {
        Node<T> *curr = head;
        if(head==NULL) {
            cout<<"EMPTY"<<endl;
            return;
        }

        while (curr!=NULL) {
            cout<<curr->getInfo()<<" --> ";
            curr = curr->getLink();
        }
        cout<<"NULL"<<endl;
    }

    void insertHead(T info) {
        Node<T> *n = new Node<T>(info,head);
        head = n;
    }

    void insertTail(T info) {
        Node<T> *curr = head;
        if (head==NULL) {
            insertHead(info);
            return;
        }

        while (curr->getLink() != NULL) {
            curr = curr->getLink();
        }

        Node<T> *n = new Node<T>(info);
        curr->setLink(n);
    }

    void insertSort(T info) {
        Node<T> *curr = head;
        if (head==NULL) {
            insertHead(info);
            return;
        }

        Node<T> *n = new Node<T>(info);
        if (curr->getInfo() >= info) {
            insertHead(info);
            return;
        }

        while (curr->getLink() != NULL) {
            if (curr->getLink()->getInfo() >= info) {
                n->setLink(curr->getLink());
                curr->setLink(n);
                return;
            }
            curr = curr->getLink();
        }

        curr->setLink(n);


    }

    void deleteHead() {
        if (head==NULL) return;
        head = head->getLink();
    }

    void deleteTail() {
        if (head==NULL) return;
        if (head->getLink()==NULL) {
            head = NULL;
            return;
        }

        Node<T> *curr = head;
        while (curr->getLink()->getLink() != NULL) {
            curr = curr->getLink();
        }
        curr->setLink(NULL);
    }

    void deleteInfo(T info) {
        if (head==NULL) return;

        Node<T> *curr = head;

        if (curr->getInfo()==info) {
            deleteHead();
            return;
        }

        while (curr->getLink()!=NULL) {
            if (curr->getLink()->getInfo() == info) {
                break;
            }
            curr = curr->getLink();
        }

        if (curr->getLink()==NULL) return;
        curr->setLink(curr->getLink()->getLink());
    }

    Node<T>* begin() {return head;}

    bool empty(){return head==NULL;}


};

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	srand(time(0));
	List<int> l1;
	List<int> l2;
	List<int> l3;
    for1(i,0,10) {
        int ins = rand()%(100-1+1)+1;
        l1.insertSort(ins);
    }
    for1(i,0,10) {
        int ins = rand()%(100-1+1)+1;
        l2.insertSort(ins);
    }
    for1(i,0,10) {
        int ins = rand()%(100-1+1)+1;
        l3.insertSort(ins);
    }

    List<int> l;

    until(l1.empty() && l2.empty() && l3.empty()) {
        int l1val = (l1.empty()?1E9:l1.begin()->getInfo());
        int l2val = (l2.empty()?1E9:l2.begin()->getInfo());
        int l3val = (l3.empty()?1E9:l3.begin()->getInfo());

        if (l1val<l2val) {
            if (l1val<l3val) {
                l.insertHead(l1val);
                l1.deleteHead();
            } else {
                l.insertHead(l3val);
                l3.deleteHead();
            }

        } else {
            if (l2val<l3val) {
                l.insertHead(l2val);
                l2.deleteHead();
            } else {
                l.insertHead(l3val);
                l3.deleteHead();
            }
        }


    }

    l.print();


	return 0;
}
