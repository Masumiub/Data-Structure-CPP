#include<iostream>
using namespace std;

struct node{
    string book;
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

/*void insert_at_front(string book_name){

    node* new_node = new node;
    new_node->book = book_name;
    new_node->next = head;
    head = new_node;

}*/


void insert_at_end(string book_name)
{
    node* new_node = new node;
    new_node->book = book_name;
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
        cout<< curr->book<< "  ";
        curr=curr->next;
    }
}

void insert_book(string specific_book, string new_book){
    //finding position of "Beloved"
    node* curr= head;

    int count=0; int index=0;
    while(curr!=NULL){


         if(curr->book == specific_book){
            break;
         }
         index++;
         curr=curr->next;
    }
    cout<< index<<endl;
    node* p = head;

    node* new_node = new node;
    new_node->book = new_book;

    if(index == 0){
    new_node->next = head;
    head = new_node;
    }


    else{
        for(int i=0; i<index-1; i++){
            p = p->next;
    }
        new_node->next = p->next;
        p->next = new_node;

    }
}

int main(){
/*insert_at_front("Peter Pan");
insert_at_front("Beloved");
insert_at_front("Dracula");
insert_at_front("Scoop");*/
insert_at_end("Scoop");
insert_at_end("Dracula");
insert_at_end("Beloved");
insert_at_end("Peter Pan");
display();

insert_book("Beloved",  "Dubliner");

display();

return 0;
}
