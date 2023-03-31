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

void circularLinklistTraversal(struct Node* head){
    struct Node* ptr= head;
    
    do{
        cout<< ptr->data<< " ";
        ptr = ptr->next;
    }while(ptr!= head);
    
}

struct Node * insertAtFirst(struct Node* head, int value){
    struct Node * ptr = new Node;
    ptr->data = data;
    struct Node *p = head->next;
    
    while(p->next!=head){
        p=p->next;
    }
    
    p->next=ptr;
    ptr->next= head;
    head = ptr;
    
    return head;
}

int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth = new Node;
    //
    head = new Node;
    second = new Node;
    third = new Node;
    
    head->data = 7;
    head->next = second;
    
    second->data = 9;
    second->next = third;
    
    third->data = 11;
    third->next = fourth;
    
    fourth->data = 22;
    fourth->next = head;

    circularLinklistTraversal(head);
    return 0;
}
