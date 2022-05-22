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

/*
void combine(){
    node* curr = head;
    int sum =0;
    while(curr!=nullptr){
        sum += curr->data;
        curr = curr->next;
    }
    //cout<< sum;
    head->data = sum;
    head->next = nullptr;
}*/

/*
void combine(){

        int mergeValue = head->data;
        while (head->next != nullptr && head->next->data == mergeValue) {
        // merge with next node (and delete next node)
        head->data += head->next->data;
        node* trash = head->next;
        head->next = head->next->next;
        delete trash;
        }

        // combine throughout rest of list
        node* curr = head;
        while (curr->next != NULL) {
        mergeValue = curr->next->data;
            while (curr->next->next != nullptr && curr->next->next->data == mergeValue) {
            // merge with next node (and delete next node)
            curr->next->data += curr->next->next->data;
            node* trash = curr->next->next;
            curr->next->next = curr->next->next->next;
            delete trash;
            }
            curr = curr->next;
        }

}*/
void surround( int a, int b){

    if(head->data == a){
       node* prev_node = new node;
        prev_node->data = b;
        prev_node->next = head;
        head = prev_node;

    /*    node* new_node = new node; // new next node
        new_node->data = b;
        new_node->next = nullptr;

        node* curr2 = head;
        while(curr2->next!=NULL){
            curr2 = curr2->next;
        }
        curr2->next = new_node;*/

    }

    node* current = head;
    node* prev = NULL;


    while(current!=NULL){

        if(current->data == a){
            node* prev_node = new node;
            prev_node->data = b;
            prev_node->next = prev->next;
            prev->next = prev_node;

            node* new_node = new node; // new next node
            new_node->data = b;
            new_node->next = current->next;
            current->next = new_node;
        }
        prev = current;
        current = current->next;
    }


}

int main()
{
    //1, 2, 3, 4, 2, 5
    //{7, 0, 1, 3, 7, 7, 4, 7}
    insert_at_end(7);
    insert_at_end(0);
    insert_at_end(1);
    insert_at_end(3);
    insert_at_end(7);
    insert_at_end(7);
    insert_at_end(4);
    insert_at_end(7);
    surround(7, 0);
    //combine();
    print_list();

}
