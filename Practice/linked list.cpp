#include<iostream>
#include<ctime>
using namespace std;

struct node{
    int data;
    node* next;
};

node* head=NULL;// at the first time, head will be null

bool isempty(){
    if(head ==NULL){
        return true;
    }
    else{
        return false;
    }
}

void insert_at_end(int value){
    node* new_node = new node;// node type (pointer) stores a address of new node.
    new_node->data = value; // assigning first value.
    new_node->next= NULL;// next is null

    if(isempty()==true){
        head=new_node; // after inserting the first value, we need to update head, (it was null), now it will point to the first node.
    }
    else{
        node* current_node = head;
        while(current_node->next!=NULL){
            current_node= current_node->next;
        }
        current_node->next=new_node;
    }
}



void search_num(int value){
node* current_node = head;
        while(current_node!=NULL){
               if(current_node->data==value){
                cout<< "found it"<< endl;
                return ;
               }

            current_node= current_node->next;
        }
        cout<< "not found"<< endl;
}


void delete_value(int given_value){
    if(isempty()==true){
        cout<< "List is empty";
    }else{
        if(head->data==given_value){
            node* temp_node=head;
            head =head->next;
            delete temp_node;
        }
        else{

             node* current_node = head;
            while(current_node->next!=NULL){
            if(current_node->next->data==given_value){
                node* temp_node=current_node->next;
                current_node->next = temp_node->next;
                delete temp_node;
                break;}
            }
            current_node = current_node->next;
        }
    }

}

void print_list(){

    node* current_node = head;
        while(current_node!=NULL){
                cout<< current_node->data<< endl;
            current_node= current_node->next;
        }
}

int main(){
insert_at_end(2);
insert_at_end(5);
insert_at_end(3);
insert_at_end(6);
insert_at_end(7);
insert_at_end(8);
insert_at_end(9);
search_num(2);

delete_value(2);
print_list();
// how to delete duplicate values
}
