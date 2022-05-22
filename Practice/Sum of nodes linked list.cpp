#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* head=NULL;
bool isempty(){
    if(head==NULL){
        return true;
    }
    else{
        return false;
    }
}

void insert_at_end(int value){
    node* ptr=new node;
    ptr->data= value;
    ptr->next=NULL;
    if(head==NULL){
        head=ptr;
    }
    else{
        node *current_node=head;
        while(current_node->next!=NULL){
            current_node = current_node->next;
        }
        current_node->next=ptr;
    }
}

void add_a_headnode(int value){
    node *new_node=new node;
    new_node->data=value;
    new_node->next=head;
    head=new_node;
}

void display(){
node *current_node=head;
        while(current_node!=NULL){
                cout<< current_node->data<< " ";
                current_node = current_node->next;
        }
}

void summation(){
node *current_node=head;

int sum=0;
        while(current_node!=NULL){
                sum +=current_node->data;
                current_node = current_node->next;
        }
        cout<< "\nSum: "<< sum;
}

int main(){
insert_at_end(0);
insert_at_end(1);
insert_at_end(2);
insert_at_end(3);
insert_at_end(4);
insert_at_end(5);
insert_at_end(6);
add_a_headnode(11);
display();
summation();
}
