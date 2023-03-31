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

struct Node * deleteFirstNode(struct Node* head){
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}


struct Node * deleteAtIndex(struct Node* head, int index){
    struct Node *p = head;
    struct Node *q = head->next;
    
    for(int i=0; i<index-1; i++){
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);
    
    return head;
}

struct Node * deleteAvalue(struct Node* head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    
    while(q->data!=value && q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value){
        p->next = q->next;
        free(q);
    }

    return head;
}

struct Node * deleteAtLast(struct Node* head){
    struct Node *p = head;
    struct Node *q = head->next;
    
    while(q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    free(q);
    
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
    fourth->next = NULL;

    //head = deleteFirstNode(head);
    
    //head = deleteAtIndex(head, 2);
    
    head = deleteAtLast(head);
    showList(head);
    return 0;
}
