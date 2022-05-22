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

void delete_value(node *head)
{
    /*if(isempty()==true) {
        cout<<"list is empty\n";
    }
    else {*/

            node *p;
            node *q;
            node *tmp;
            p=head;
            for(int i=0;p!=NULL && p->next!=NULL; i++){
                q=p;
                for(int j=1; q->next!=NULL; j++){
                    if(p->data == q->next->data){
                        tmp=q->next;
                        q->next=q->next->next;
                        delete tmp;
                    }else{
                        q=q->next;
                    }
                }
                p=p->next;
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

int main()
{
    insert_at_end(9);
    insert_at_end(10);
    insert_at_end(11);
    insert_at_end(9);
    insert_at_end(13);
    insert_at_end(9);
    insert_at_end(13);
    insert_at_end(15);


    //print_list();
    /*int value;
    cin>>value;
    search_value(value);*/
    delete_value(head);
    print_list();

    return 0;
}
