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

void delete_value(int given_value)
{
    if(isempty()==true) {
        cout<<"list is empty\n";
    }
    else {
        if(head->data==given_value) {
            node* temp_node = head;
            head = head->next;
            delete temp_node;
        }
        else {
            node* current_node = head;
            while(current_node->next!= NULL) {
                if(current_node->next->data == given_value) {
                    node* temp_node = current_node->next;
                    current_node->next = temp_node->next;
                    delete temp_node;
                    return;
                }
                current_node = current_node->next;
            }
        }
    }
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
        cout<<current_node->data<<endl;
        current_node = current_node->next;
    }
}

bool check_sorted(){
    int x = -32768;
    node* p = head;
    while(p!=NULL){
        if(p->data <x){
            return false;
        }else{
            x= p->data;
            p=p->next;
        }
    }
    return true;
}
int main()
{
    insert_at_end(2);
    //insert_at_end(5);
    insert_at_end(4);
    insert_at_end(6);
    insert_at_end(11);
    insert_at_end(12);
    print_list();
    cout<< check_sorted();
}
