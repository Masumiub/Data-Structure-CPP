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

    for(int i =0; current_node!=NULL; i++){
        cout<< current_node->data<< "->";
        current_node = current_node->next;
    }
    cout<< "NULL"<< endl;


}

void chop(int key){
    node* current_node = head;


    /*int count =0;
    for(int i =0; current_node!=NULL; i++){
        count++;
        current_node = current_node->next;
    } */

    int n = 6-(key+1);
    //cout<< n-key<< endl;

    node* prev = NULL;

    for(int i =0; current_node!=NULL ; i++){
        prev = current_node;
        if(i == key){
            prev = head;
            head= current_node;
        }
        if(i == n){
            prev->next = NULL;
        }
        current_node = current_node->next;
    }
}

int main()
{
    insert_at_end(10);
    insert_at_end(20);
    insert_at_end(30);
    insert_at_end(40);
    insert_at_end(50);
    insert_at_end(60);
    chop(2);
    print_list();
}
