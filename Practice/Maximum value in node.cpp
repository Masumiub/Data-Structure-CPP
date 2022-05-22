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

void counting_nodes(){
node* current_node = head;
int count=0;
    while(current_node!= NULL) {
        count++;
        current_node = current_node->next;
    }
cout<< "There are total "<< count<< " nodes "<< endl;
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

void sum(){
    node* current_node = head;
    int s=0;
    while(current_node!= NULL) {
        s +=current_node->data;
        current_node = current_node->next;
    }
    cout<< "Total sum of Node Values: "<< s<< endl;
}

void Max(){
node* current_node = head;
int p=head->data;

    while(current_node!= NULL) {
        if(current_node->data>p){
            p=current_node->data;
        }
        current_node = current_node->next;
    }
    cout<< "Maximum value in Linked list "<<p;
}



int main()
{
    insert_at_end(2);
    insert_at_end(5);
    insert_at_end(4);
    insert_at_end(5);
    insert_at_end(3);

   // print_list();
    /*int value;
    cin>>value;
    search_value(value);*/
    delete_value(5);
    print_list();

    counting_nodes();
    sum();
    Max();


    return 0;
}
