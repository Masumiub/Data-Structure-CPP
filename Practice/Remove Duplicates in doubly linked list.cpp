#include<iostream>
using namespace std;

struct node{
    int data;
    node* prev;
    node* next;
};

node* head = NULL;
node* tail = NULL;

bool isempty(){
    if(head == NULL){
        return true;
    }
    return false;
}

void insert_at_end(int value){
    //first create a new node;
    node* new_node = new node;
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(isempty()==true){ // update head pointer
        head=new_node ; // point to new node;
        tail=new_node ;
    }
    else{
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}
void display(){
    node* curr=head;
    while(curr!=NULL){
        cout<< curr->data<< "  ";
        curr= curr->next; // traversing
    }
}

void delete_dup(int value){ // with key - all occur
    node* curr=head;
    while(curr!=NULL){
        if(head==tail && head->data== value){
            delete tail;
            head = NULL;
            tail = NULL;
            break;
        }
        else if(head->data == value){
            node* to_delete =head;
            head = head->next;
            head->prev = NULL;
            delete to_delete;
            curr = head;
            continue;
        }
        else if(curr->data == value){
            node* to_delete = curr;
            curr->prev->next = curr->next;
            if(curr == tail){
                tail = tail->prev;
                delete to_delete;
                break;
            }
            else{
                curr->next->prev = curr->prev;
                curr= curr->next;
                delete to_delete;
            }
        }
        else{
            curr=curr->next;
        }
    }
}/*
void remove_duplicates(){ // without key basic
    if(isempty()==true){
        cout<< "List is Empty";
    }else{
        node* curr = head->next;
        node* curr_prev = head;
        while(curr!=NULL){
            if(curr->data == curr_prev->data){
                node* tmp = curr;
                curr->prev->next = curr->next;
                curr_prev = curr;
                curr->next->prev = curr->prev;
                free(tmp);
            }
            curr_prev = curr;
            curr = curr->next;
        }

    }
}
*/
void rem_dup(){ //  without key
    if(head == NULL){
        cout<< "List is empty";
        return;
    }
    else{
        node* curr = head;
        while(curr!=NULL){
            node* tmp = curr->next;
            while(tmp!=NULL){
                if(curr->data == tmp->data){
                    node* tmp2=tmp;
                    tmp->prev->next = tmp->next;
                    if(tmp->next!=NULL){
                        tmp->next->prev = tmp->prev;
                    }
                    //tmp2 = NULL;
                    delete tmp2;
                }
                tmp = tmp->next;
            }
            curr=curr->next;
        }
    }
}
/*void Insert(node *p,int index,int x)
{
node *t;
int i;
    if(index < 0 )
        {return;}
    if(index==0)
    {
        t=new node;
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else
    {
        for(i=0;i<index-1;i++)
            {p=p->next;}
        t=new node;
        t->data=x;
        t->prev=p;
        t->next=p->next;
        if(p->next)
            {p->next->prev=t;}
        p->next=t;
    }
}
/*int Delete(node *p,int index) // delete a node, with index
{
    node *q=NULL;
    int x=-1,i;

    if(index < 1 )
        return -1;
    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}*/

int main(){
    cout<< "Doubly linked list : ";
    insert_at_end(1);

    insert_at_end(2);
    insert_at_end(1);
    insert_at_end(2);
    insert_at_end(2);
    insert_at_end(3);
    insert_at_end(3);
    insert_at_end(4);
    display();
    delete_dup(3);
    //rem_dup();
    //remove_duplicates();
    cout<< endl;
    display();
}
