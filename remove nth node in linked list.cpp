//PRIN Company
#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
};


void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}


void Delete_Node(Node **head_ref, int position)
{


    if (*head_ref == NULL)
        {return;}
    Node* temp = *head_ref;

    if (position == 0)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }


    for(int i = 0; temp != NULL && i < position - 1; i++)
        {temp = temp->next;}


    if (temp == NULL || temp->next == NULL)
        {return;}


     Node *next = temp->next->next;


    free(temp->next);
    temp->next = next;
}


void Print(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{


    Node* head = NULL;
    int n;
    push(&head, 17);
    push(&head, 17);
    push(&head, 10);
    push(&head, 6);
    push(&head, 6);
    push(&head, 15);
    push(&head, 14);
    push(&head, 4);
    push(&head, 9);
    push(&head, 4);

    cout << "Created Linked List: ";
    Print(head);
    cout<< endl<< endl;
    cout<<"Enter a term you want to Remove:";cin>>n;
    Delete_Node(&head, n);
    cout<< endl;
    cout << "Linked List after Deletion at given position: ";
    Print(head);
    return 0;
}
