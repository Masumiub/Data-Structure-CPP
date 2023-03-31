/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

void doublyLinkedlistTraversal(struct Node* N1){
    struct Node *p = N1;
    while(p->next!=NULL){
        cout<< p->data<< "->";
        p = p->next;
    }
    cout<< p->data;
}

void doublyLinkedlistTraversalRev(struct Node* N4){
    struct Node *p = N4;
    while(p->prev!=NULL){
        cout<< p->data<< "->";
        p = p->prev;
    }
    cout<< p->data;
}

int main()
{
    struct Node *N1 = new Node;
    struct Node *N2 = new Node;
    struct Node *N3 = new Node;
    struct Node *N4 = new Node;
    
    N1->data = 1;
    N1->prev = NULL;
    N1->next = N2;
    
    N2->data = 2;
    N2->prev = N1;
    N2->next = N3;
    
    N3->data = 3;
    N3->prev = N2;
    N3->next = N4;
    
    N4->data = 4;
    N4->prev = N3;
    N4->next = NULL;

    doublyLinkedlistTraversal(N1);
    cout<< endl;
    doublyLinkedlistTraversalRev(N4);
    
    return 0;
}
