#include<iostream>
using namespace std;


struct node{
    int data;
    node* next;
}*Top=NULL;

void push(int value){
    node* new_node = new node;
    if(new_node==NULL){
        cout<< "Stack is Full."<< endl;
    }
    else{
        new_node->data = value;
        new_node->next = Top;
        Top = new_node;
    }
}

void display(){
    node* curr;
    curr= Top;
    while(curr!= NULL){
        cout<< curr->data<< endl;
        curr = curr->next;
    }
    cout<< endl;
}
void delete_lar_value(int value){
    if(Top == NULL){
        cout<< "List is Empty."<< endl;
    }
    else{
        if(Top->data == value){
            node* tmp = Top;
            Top = Top->next;
            delete Top;
        }
        else{
            node* curr = Top;
            while(curr->next!=NULL){
                if(curr->next->data == value){
                    node* tmp = curr->next;
                    curr->next = tmp->next;
                    delete tmp;
                    return;
                }
                curr = curr->next;
            }
        }
    }
}

int largest_num(){
    node* curr;
    curr= Top;

    int lar = Top->data;

    node* new_node  = new node;
    while(curr!= NULL){
        if(Top->data < curr->data){
            lar = curr->data;
        }
        curr = curr->next;
    }
    //cout<< "Largest Value: "<< lar;
    return lar;
}

void add_front(int value){
    node* new_node= new node;
    new_node->data = value;
    new_node->next = Top;
    Top = new_node;
}
int main(){
push(11);
push(12);
push(16);
push(63);
push(23);
push(55);


int delete_value = largest_num();
delete_lar_value(delete_value);
add_front(delete_value);
display();

}
