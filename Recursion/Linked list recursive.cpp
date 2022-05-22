#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* head = NULL;

bool isempty()
{
    if(head==NULL) {
        return true;
    }
    return false;
}

void insert_at_front(int value){
    node* new_node = new node;
    new_node->data = value;
    new_node->next = head;

    head = new_node;
}



void display(node* curr){ // reverse order
    if(curr!=NULL){
        cout<< curr->data<< "->" ;
        display(curr->next);
    }
}

void display2(node* curr){ // normal order
    while(curr!=NULL){
        cout<< curr->data<< "->" ;
        curr = curr->next;
    }
}

int minimum(node* curr, int cnt){

    if(curr!=NULL){
        if(cnt>curr->data){
            cnt = curr->data;
        }
        return minimum(curr->next, cnt);
    }
    return cnt;
}

node* insert_at_end(node* curr, int value){
    if(curr==NULL){
        node* new_node = new node;
        new_node->data = value;
        new_node->next = NULL;
        return new_node;
    }
    else{
        curr->next = insert_at_end(curr->next, value);
    }
    return curr;
}

node* delete_node(node* head, int k){ // k is the position
    if(head == NULL){
        return NULL;
    }
    if(k==1){
        node* p = head->next;
        delete(head);
        return p;
    }
    head->next = delete_node(head->next, k);
    return head;
}


node* insert_node_rec(node* head, int i, int data){
    if(head == NULL){
        return NULL;
    }
    if(i == 0){
        node* new_node = new node;
        new_node->next = head;
        return new_node;
    }
    if(i == 1){
        node* new_node = new node;
        new_node->data = data;
        new_node->next = head->next;
        head->next = new_node;
        return head;
    }
    node* curr= insert_node_rec(head->next, i-1, data);
    return head;
}
int main()
{
    head = insert_at_end(head, 10);
    insert_at_end(head, 9);
    insert_at_end(head, 11);
    insert_at_end(head, 12);
    insert_at_end(head, 13);
    display2(head);
    cout<< "NULL";
    return 0;
}
