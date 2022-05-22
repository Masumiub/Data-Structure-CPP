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

void insert_at_front(int value){
    node* new_node = new node;
    new_node->data = value;
    new_node->next = head;

    head = new_node;
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

node* reverse(node* &head){ // reverse a linked list
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    while(currptr!=NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr; // new head
}

void display(node* newhead){
    node* curr= newhead;
    while(curr!=NULL){
        cout<< curr->data<< " ";
        curr = curr->next;
    }
}

int Delete(node *p,int index) // delete with a index key
{
node *q=NULL;
int x=-1,i;
    if(index < 1 )
    return -1;
    if(index==1)
    {
    q=head;
    x=head->data;
    head=head->next;
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
}

/*
void rev(node* curr){
if(curr!=NULL){
    rev(curr->next);
    cout<< curr->data<< " " ;
}*/

void rev2(node* curr){
if(curr!=NULL){

    cout<< curr->data<< " " ;
    rev2(curr->next);
}
}
/*
int  r_ten_count(node* curr, int count){
    //int count=0;

if(curr!=NULL){

    if(curr->data > 10){
        cout<< curr->data<< " " ;
        count++;
    }
    return count + r_ten_count(curr->next, count);

}
//return count;
}*/
void improve_search(node* p, int key){
    node* q= NULL;
    while(p!=NULL){
        if(key == p->data){
            q->next = p->next;
            p->next= head;
            head = p;
        }
        q = p;
        p = p->next;
    }
}

int main()
{
    insert_at_end(2);
    insert_at_end(5);
    insert_at_end(4);
    insert_at_end(6);
    insert_at_end(11);
    insert_at_end(12);
    insert_at_end(13);

    insert_at_front(1);
    //Delete(head, 2);
   // print_list();
    /*int value;
    cin>>value;
    search_value(value);*/
    //delete_value(3);
    improve_search(head, 12);
    print_list();
 //int count=0;
 //cout<< r_ten_count(head, count);
    //rev2(head);
   // counting_nodes();

    //middle_nodes();
    //sum();

    //node* newhead = reverse(head);
    //display(newhead);

    return 0;
}
