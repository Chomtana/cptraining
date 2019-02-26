#include <bits/stdc++.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define for2(i,a,b) for(int (i)=(a);((a)<=(b)?(i)<=(b):(i)>=(b));(i)+=((a)<=(b)?1:-1))
#define all(x) x.begin(),x.end()

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


};

int main() {
	ios::sync_with_stdio(false);
	cout<<fixed;
	List<int> lst1;
	lst1.insertHead(100);
	lst1.insertHead(200);
	lst1.insertHead(400);
	lst1.insertHead(150);
	lst1.insertHead(50);
	lst1.print();

	List<int> lst2;
	lst2.insertTail(100);
	lst2.insertTail(200);
	lst2.insertTail(400);
	lst2.insertTail(150);
	lst2.insertTail(50);
	lst2.deleteInfo(100);
	lst2.deleteInfo(400);
	lst2.deleteInfo(50);
	lst2.print();

	List<int> lst3;
	lst3.insertSort(100);
	lst3.insertSort(200);
	lst3.insertSort(400);
	lst3.insertSort(150);
	lst3.insertSort(50);
	lst3.deleteHead();
	lst3.deleteTail();
	lst3.print();
	return 0;
}
