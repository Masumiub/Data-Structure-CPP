#include <iostream>
using namespace std;

struct ListNode{
    int data;
    ListNode *next;
};

ListNode* head = NULL;

bool isempty()
{
    if(head==NULL) {
        return true;
    }
    return false;
}
void insert_at_end(int value)
{
ListNode* new_node = new ListNode;
    new_node->data = value;
    new_node->next = NULL;

    if(isempty()==true) {
        head = new_node;
    }
    else {
        ListNode* current_node = head;
        while(current_node->next!= NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
}

void display(){
    ListNode* current_node = head;
        while(current_node!= NULL) {
            cout<< current_node->data<< " " ;
            current_node = current_node->next;
        }

}


void addFront(ListNode*& head, int value) {
	ListNode* new_node= new ListNode();
    new_node->data= value;
    new_node->next= head;
    head = new_node;
}
int main()
{
    insert_at_end(1);
    insert_at_end(2);
    insert_at_end(3);

    display();
    addFront(head, 4);
    cout<< endl;
    display();
    return 0;
}
