#include <stdio.h>

#define for1(a,b,c) for(int (a)=(b);(a)<(c);(a)++)

using namespace std;

class node {
    public:
    int data;
    node* next = NULL;
    node* pre = NULL;

    node(int x) {
        data = x;
    }
};

node* head = NULL;

int main() {
	int n,m; scanf("%d%d",&n,&m);
	//list<int> data;
	//for1(i,1,n+1) data.push_back(i);
    head = new node(1);
    node* curr = head;
    for1(i,2,n+1) {
        //node* n = new node(i);
        curr->next = new node(i);
        curr->next->pre = curr;
        curr = curr->next;
    }
	curr = head; //auto it = data.begin();
	int count = 0;
	while(head->next!=NULL) {
        //cerr<<'<'<<head->data<<' '<<head->next->data<<'>'<<endl;
        count++;
        //if (count>10) break;
		for1(i,0,m-1){
			//count++;
			curr = curr->next; //++it;
			if (curr==NULL) curr = head; //it=data.begin();
		}
		printf("%d ",curr->data);
		//count++;
		//it=data.erase(it);
        if (curr->pre == NULL) {
            head = curr->next;
            head->pre = NULL;
            curr = curr->next;
        } else {
            //if (curr->data == 5) cerr<<"aaa "<<curr->pre->data<<endl;
            curr->pre->next = curr->next;
            if (curr->next!=NULL) curr->next->pre = curr->pre;
            curr = curr->next;
        }
		if (curr==NULL) curr = head; //it=data.begin();
		//++it;
	}
	printf("%d",head->data);
	//cout<<count;
	return 0;
}
