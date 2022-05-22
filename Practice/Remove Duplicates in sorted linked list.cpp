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

void delete_value(node *head) // without key
{
    if(isempty()==true) {
        cout<<"list is empty\n";
    }
    else {

            node* current_node = head->next;
            node* prev_node =head;
            while(current_node!= NULL) {
                if(current_node->data == prev_node->data) {
                    node* temp_node = current_node;
                    current_node = current_node->next;
                    prev_node->next=current_node;
                    delete temp_node;
                    //return;
                }else{
                prev_node = current_node;
                current_node=current_node->next;
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


void search_value(int value)
{
    node* current_node = head;
    while(current_node!= NULL) {
        if(current_node->data==value) {
            cout<<"found\n";
            return;
        }
        current_node = current_node->next;
    }
    cout<<"not found\n";
}


void rem_dup(int value){ // with key - all occur
    node* curr=head;
    if(head ==NULL){
        return;
    }
    if(head!=NULL && head->data == value){
        head=head->next;
    }
    while(curr->next!=NULL){
        if(curr->next->data == value){
        node* tmp = curr->next;
        curr->next = curr->next->next;
        free(tmp);
        }
        else{
            curr = curr->next;
        }
    }
}

int main()
{
    insert_at_end(1);
    insert_at_end(2);
    insert_at_end(2);
    insert_at_end(3);
    insert_at_end(3);
    insert_at_end(3);
    insert_at_end(4);
    insert_at_end(5);

//rem_dup(3);
    //print_list();
    /*int value;
    cin>>value;
    search_value(value);*/
    delete_value(head);
    print_list();

    return 0;
}
