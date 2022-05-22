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

void create(int A[],int n)
{
int i;
node *t;
node*last;
head=new node;
head->data=A[0];
head->next=NULL;
last=head;
for(i=1;i<n;i++)
{
t=new node;
t->data=A[i];
t->next=NULL;
last->next=t;
last=t;
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

void sorted_insert(node* p, int x){
    node* new_node = new node;
    node* q = NULL;
    new_node->data = x;
    new_node->next = NULL;

    if(head == NULL){
        head = new_node;
    }else{

        while(p && p->data<x){
            q = p;
            p = p->next;
        }
        if(p == head){
            new_node->next = head;
            head = new_node;
        }
        else{
            new_node->next = q->next;
            q->next = new_node;
        }
    }
}


void Display(node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

int main(){
    int A[] = {10, 20, 30, 40, 50};
    create(A,5);
    sorted_insert(head, 45);
    Display(head);
}
