#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;//
};

node* head = NULL;
node* second =NULL;

bool isempty()
{
    if(head==NULL) {
        return true;
    }
    return false;
}

void delete_value(node *head)
{
    if(isempty()==true) {
        cout<<"list is empty\n";
    }
    else {
        node *q =head->next;
        while(q!=NULL){
            if(head->data!=q->data){
                head=q;
                q=q->next;
            }
            else{
                head->next=q->next;
                delete q;
                q=head->next;
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

void print_list(node *head)
{
    //node* current_node = head;
    while(head!= NULL) {
        cout<<head->data<<endl;
        head = head->next;
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

int main()
{
    insert_at_end(2);
    insert_at_end(2);
    insert_at_end(3);
    insert_at_end(3);
    insert_at_end(3);
    insert_at_end(5);
    insert_at_end(8);
    insert_at_end(8);

    //
    /*int value;
    cin>>value;
    search_value(value);*/
    delete_value(head);
    print_list(head);
    //print_list();

    return 0;
}
