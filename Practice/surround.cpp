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

void insert_at_end(int value)
{
    node* new_node = new node;
    new_node->data = value;
    new_node->next = NULL;

    if(isempty()==true) {
        head = new_node;
    }
    else {
        node* current_node = head;
        while(current_node->next!= NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}



void print_list()
{
    node* current_node = head;
    while(current_node!= NULL) {
        cout<<current_node->data<<" -> ";
        current_node = current_node->next;
    }
    cout<< "NULL"<< endl;
}

void insert_at_first(int value){

    node* new_node = new node;
    new_node->data = value;
    new_node->next = head;
    head = new_node;
}

void insert_key(int specific_key, int new_key){
    //finding position of "Beloved"
    node* curr= head;

    int count=0; int index=0;
    while(curr!=NULL){


         if(curr->data == specific_key){
            break;
         }
         index++;
         curr=curr->next;
    }
    //cout<< index<<endl;
    node* p = head;

    node* new_node = new node;
    new_node->data = new_key;

    if(index == 0){
    new_node->next = head;
    head = new_node;
    }


    else{
        for(int i=0; i<index-1; i++){
            p = p->next;
        }
        new_node->next = p->next;
        p->next = new_node;

    }
}

void insert_key_middle(int specific_key, int new_key){

    node* p = head;

    node* new_node = new node;
    new_node->data = new_key;
    for(int i=0; i<5-1; i++){
            p = p->next;
        }
    new_node->next = p->next;
    p->next = new_node;

}

void surround(node* head, int a, int b) {

    node* current = head;

    insert_key(a, b);
    insert_key_middle(a, b);
    while(current!=NULL){

        if(current->data == a){

            node* new_node = new node; // new next node
            new_node->data = b;
            new_node->next = current->next;
            current->next = new_node;
        }

        current = current->next;
    }

}


int main()
{
   // insert_at_end(1);
    insert_at_end(2);
    insert_at_end(3);
    insert_at_end(4);
    insert_at_end(6);
    insert_at_end(2);

    surround(head, 2, 9);
    print_list();
    return 0;
}
