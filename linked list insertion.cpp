/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;


struct Node{
    int data;
    struct Node * next;
};

void showList(struct Node* ptr){
    while(ptr!=NULL){
        cout<< ptr->data<< " ";
        ptr = ptr->next;
    }
}

struct Node* insertAtFirst(struct Node *head, int data){
    struct Node * ptr = new Node;
    ptr->next = head;
    ptr->data = data;
    return ptr;
}


struct Node* insertAtIndex(struct Node *head, int data, int index){
    struct Node * ptr = new Node;
    
    struct Node *p = head;
    int i = 0;
    
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    
    return head;
}


struct Node* insertAtEnd(struct Node *head, int data){
    struct Node * ptr = new Node;
    
    struct Node *p = head;
    
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->data = data;
    ptr->next = NULL;
    return head;
    
}


struct Node* insertAfter(struct Node *head,struct Node *prevNode, int data){
    struct Node * ptr = new Node;
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
    
}
int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;
    head = new Node;
    second = new Node;
    third = new Node;
    
    head->data = 7;
    head->next = second;
    
    second->data = 9;
    second->next = third;
    
    third->data = 11;
    third->next = NULL;


    //head = insertAtFirst(head, 55);
    head = insertAtIndex(head, 10, 1);
    head = insertAfter(head, second, 44);
    head = insertAtEnd(head, 88);
    showList(head); 

    return 0;
}
