#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int n,k;

struct node {
    int data;
    node* next;
};

node* buildplayerll(int current) {
    if (current>n) {
        return NULL;
    }
    node* head = (node*)malloc(sizeof(node*));;
    head->data = current;
    head->next = buildplayerll(current+1);
    return head;
}

int main() {
    cin >> n >> k;

    node* head = buildplayerll(1); //first player
    
    node* current = head;
    node* before = NULL;
    while (head->next != NULL) {
        k--;
        if (k == 0) {
            k = current->data;
            if (current == head) {
                head = head->next;
            } else {
                before->next = current->next;
            }
        }
        
        if (before == NULL) {before = head;} else {before = current;}
        current = current->next;
        if (current == NULL) {
            current = head;
        }
    }
    cout << head->data;
    return 0;
}
