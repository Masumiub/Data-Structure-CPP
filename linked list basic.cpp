/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node * next;
};

void showList(struct Node* ptr){
    while(ptr!=NULL){
        cout<< ptr->data<< " ";
        ptr = ptr->next;
    }

}

int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;
    head = new Node;
    second = new Node;
    third = new Node;
    
    head->data = 7;
    head->next = second;
    
    second->data = 9;
    second->next = third;
    
    third->data = 11;
    third->next = NULL;

    showList(head);

    return 0;
}
