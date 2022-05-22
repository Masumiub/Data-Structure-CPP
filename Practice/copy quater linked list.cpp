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
        cout<<current_node->data<<"->";
        current_node = current_node->next;
    }
    cout<< "NULL"<< endl;
}

void copy_first_list(){
    node* head1 = NULL;
    node* head2 = NULL;
    node* head3 = NULL;
    node* p;
    node* q;
    node* curr= head;
    for(int i=0; i<2; i++){
        p= curr;
        curr = curr->next;
    }
    head1 = head;
    p= head1;
   for(int i=0; i<2; i++){
        cout<< p->data<< "->";
        p = p->next;
    }
    cout<< endl;cout<< endl;
    node* curr2= head;
    for(int i=2; i<4; i++){
        q= curr2;
        curr2 = curr2->next;
    }
     q= head2;
   for(int i=2; i<4; i++){
        cout<< q->data<< "->";
        q = q->next;
    }
}

void find_1st_min(){
    node* curr = head;
    int min = 324325647;
    int min2=-1;
    int min3=-1;
    //int min2 = head->next->data;
    //int min3 = head->next->next->data;

    while(curr!=NULL){
        if(min>curr->data){
            min = curr->data;
        }
        curr= curr->next;
    }
    node* curr2= head;
    while(curr2!=NULL){
        if(curr2->data == (min+1)){
            min2 = curr2->data;
            break;
        }
        curr2= curr2->next;
    }
    node* curr3= head;
    while(curr3!=NULL){
        if(curr3->data == (min2+1)){
            min3 = curr3->data;
            break;
        }
        curr3= curr3->next;
    }
    cout<< "The First minimum Value: "<<min<< endl;
    cout<< "The Second minimum Value: "<<min2<< endl;
    cout<< "The Third minimum Value: "<<min3<< endl;
}

void print3smallest(){
    node* curr = head;
    int min1 = 1000000000;
    int min2 = 1000000000;
    int min3 = 1000000000;
    while(curr!=NULL){
            /* Check if current element is less than
           firstmin, then update first, second and
           third */
        if(curr->data< min1){
            min3 = min2;
            min2 = min1;
            min1 = curr->data;
        }
        /* Check if current element is less than
        secmin then update second and third */
        else if(curr->data< min2){
            min3 = min2;
            min2 = curr->data;
        }
        /* Check if current element is less than
        then update third */
        else if(curr->data < min3){
            min3 = curr->data;
        }
        curr = curr->next;
    }
    cout<< "First Min: "<< min1<< endl;
    cout<< "Second Min: "<< min2<< endl;
    cout<< "Third Min: "<< min3<< endl;
}
int main(){
    insert_at_end(3);
    insert_at_end(2);
    insert_at_end(1);
    insert_at_end(5);
    insert_at_end(6);
    insert_at_end(8);
    insert_at_end(9);
    insert_at_end(15);

    print_list();
    cout<< endl;
    cout<< endl;
    print3smallest();
    //find_1st_min();
    //copy_first_list();
}
