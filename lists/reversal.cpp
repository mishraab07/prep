using namespace std;

#include<bits/stdc++.h>

typedef struct node_s{
    int value;
    struct node_s* next;
}Node;

Node* newNode(int val) {
    Node* temp = new Node();
    temp->value = val;
    temp->next = NULL;
    
    return temp;
}

void reverse(Node **head) {

    Node* first;
    Node* rest;
    
    // empty list
    if(!*head)
        return;

    first = *head;
    rest = first->next;

    // only 1 element, already reversed
    if(!rest)
        return;

    reverse(&rest);
    first->next->next = first;
    first->next = NULL;

    *head = rest;
}

void printList(Node *head) {
    Node* it = head;

    while(it != NULL) {
        cout<<it->value<<"->";
        it=it->next;
    }
    cout<<"NULL"<<endl;
}

int main() {
    Node *head = NULL;
    head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(54);
    head->next->next->next = newNode(12);
    head->next->next->next->next = newNode(90);
    
    printList(head);
    reverse(&head);
    printList(head);

    return 0;
}
