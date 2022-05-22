/*int fun1(value, address/oil)
{
    how many times that value will be there and return that number
}

int fun2(){

travse all values and call that function & store that number
}*/

#include<iostream>
using namespace std;

struct node{
    string item;
    node* next;
};
node* head = NULL;


bool isempty(){
    if(head==NULL){
        return true;
    }
    else{
        return false;
    }
}

void insert_at_end(string item)
{
    node* new_node = new node;
    new_node->item = item;
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

void display(){
    node* curr = head;
    while(curr!=NULL){
        cout<< curr->item<< "  ";
        curr=curr->next;
    }
}
int search_item(string item){
    int count=0;
    node* curr = head;
    while(curr!=NULL){
        if(curr->item == item){
            count++;
        }
        curr=curr->next;
    }
    return count;
}

void count_dup_pair(node* head){
    //node* curr = head;
    //node* curr2 = head->next;
    int count=0;
    /*int pair_count ;
    while(curr!=NULL){
        pair_count += search_item(curr->item);
        curr=curr->next;
    }
    cout<< "Pair Count: "<<pair_count;*/
    while(head->next != NULL){
        node* p= head->next;
        while(p!= NULL){
            if(head->item == p->item){
                count++;
                //break;
            }
            p = p->next;
        }
        head = head->next;
    }

    cout<<"\nThis Linked list has: "<<  count<< " pairs.";
}
int main(){
    insert_at_end("oil");
    insert_at_end("rice");
    insert_at_end("rice");
    insert_at_end("nut");
    insert_at_end("nut");
    insert_at_end("nut");

    display();
    //cout<< search_item("nut");
    count_dup_pair(head);
    return 0;
}
