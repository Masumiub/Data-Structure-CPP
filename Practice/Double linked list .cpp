#include<iostream>
#include<ctime>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};

node* head =NULL;
node* tail =NULL;

bool isempty()
{
    if(head==NULL) {
        return true;
    }
    return false;
}
void insert_at_front(int value){
    node *new_node = new node;
    if(head == NULL){
       new_node->data = value;
       new_node->next = NULL;
       new_node->prev = NULL;
       head = new_node;
    }
    else{
         new_node->data = value;
         new_node->prev = NULL;
         new_node->next = head;
         head-> prev = new_node;
         head = new_node;
    }
}

void insert_at_end(int value)
{
    node* new_node = new node;
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    if(isempty()==true) {
        head = new_node;
        tail = new_node;
    }else{
        tail->next= new_node;
        new_node->prev = tail;
        tail= new_node;
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

void rev_print_list()
{
    node* current_node = tail;
    while(current_node!= NULL) {
        cout<<current_node->data<<endl;
        current_node = current_node->prev;
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
void delete_node(){
int index;
cout<< "Enter a position : ";
cin>> index;
node *p;
node *q;
int x=-1, i;
        if(index<1 || index > 5){
            return;
        }
        if(index == 1) // deleting the first node
        {
            head=head->next;
            if(head)head->prev =NULL;

            x=p->data;
            delete p;
        }else{
            for(i=0; i<index-1; i++){
            p=p->next;
            }
            p->prev->next = p->next;
            if(p->next){
            p->next->prev = p->prev;
            }
            x=p->data;
            delete p;
        }

}




void delete_value(int value){
    if(isempty()==true){
        cout<< "List empty";
    }
    else{
        if(head==tail && head->data==value ){
            delete head;
            head=NULL;
            tail=NULL;
        }

        else if(head->data == value){
            node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }else{
            node* current_node = head;
            while(current_node!= NULL) {
                if(current_node->data==value) {
                node *temp=current_node;
                current_node->prev->next= current_node->next;
                    if(current_node==tail){
                        tail = tail->prev;
                    }
                    else{
                        current_node->next->prev = current_node->prev;
                        }
                    delete temp;
                    return ;
                    }
                        current_node = current_node->next;

                }

        }


}
}


int main()
{
    insert_at_end(2);
    insert_at_end(5);
    insert_at_end(4);
    insert_at_end(5);
    insert_at_end(3);
    search_value(5);

    insert_at_front(10);
    //delete_node();
    delete_value(4);
    print_list();
    //rev_print_list();


}
