#include<iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

node* first = NULL;
node* second = NULL;

void concat_linked_list(node* first, node* second){
    node* p = first;
    while(p->next!= NULL){
        p = p->next;
    }
    p->next = second;
    second = NULL;
}
