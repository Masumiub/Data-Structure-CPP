#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* head = NULL;

struct node2{
    int data;
    node2* next;
};
node2* head2 = NULL;

bool isempty()
{
    if(head==NULL) {
        return true;
    }
    return false;
}

bool isempty2()
{
    if(head2==NULL) {
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

void insert_at_end2(int value)
{
    node2* new_node2 = new node2;
    new_node2->data = value;
    new_node2->next = NULL;

    if(isempty2()==true) {
        head2 = new_node2;
    }
    else {
        node2* current_node2 = head2;
        while(current_node2->next!= NULL) {
            current_node2 = current_node2->next;
        }
        current_node2->next = new_node2;
    }
}

void linkedmystery(node* head, node2* head2){
    node* curr1 = head;
    while(head2!=NULL){
        if(curr1->next==NULL){
            curr1->next = head2;
            head2 = NULL;
        }
        else if(head2->data < curr1->next->data){
            node* temp2 = head2;
            head2 = head2->next;
            temp2->next = curr1->next;
            curr1->next = temp2;
        }else{
            curr1= curr1->next;
        }
    }
}

void print_list()
{
    node* current_node = head;
    while(current_node!= NULL) {
        cout<<current_node->data<<"  ";
        current_node = current_node->next;
    }
}


void print_list2()
{
    node2* current_node = head2;
    while(current_node!= NULL) {
        cout<<current_node->data<<"  ";
        current_node = current_node->next;
    }
}

int main()
{
    insert_at_end(2);
    insert_at_end(7);
    insert_at_end(5);
    insert_at_end(33);
    print_list();
    cout<< endl;
    insert_at_end2(1);
    insert_at_end2(10);
    insert_at_end2(9);
    insert_at_end2(8);
    insert_at_end2(66);
    insert_at_end2(55);
    print_list2();
    return 0;
}
