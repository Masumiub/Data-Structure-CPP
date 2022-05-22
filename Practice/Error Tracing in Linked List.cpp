#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* head= NULL;

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

void search_value(int value)
{

    node* current_node = head;

    bool found = false;
    while(current_node!= NULL) { // if we use current_node->next! , last element of list will be unchecked
        if(current_node->data==value) {
            cout<<"found\n";
            found = true;
            //return;
        }
        current_node = current_node->next;
    }
    if(found == false)
        cout<<"not found\n";
}

int main()
{
    insert_at_end(2);
    insert_at_end(3);
    insert_at_end(6);
    insert_at_end(8);


search_value(8);
    return 0;
}
