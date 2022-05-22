#include <iostream>
using namespace std;

struct node
{
  int data;
  node *next;
};

node *head = NULL;

bool isempty ()
{
  if (head == NULL)
    {
      return true;
    }
  return false;
}

void insert(int value){

  node *new_node = new node;
  new_node->data = value;
  new_node->next = NULL;
  if (isempty () == true)
    {
      head = new_node;
    }
  else
    {
      node *curr = head;
      while(curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

void delete_even_values(){

  node *curr = head;
  while(curr->next != NULL)
    {
      if(head->data % 2 == 0){
            node *tmp2 = head;
            head = head->next;
            delete tmp2;
        }
      else{
            if (curr->next->data % 2 == 0){
                node *tmp = curr->next;
                curr->next = tmp->next;
                delete tmp;
                //curr = head;
                //continue;
            }
            else{
                curr = curr->next;
            }
        }
    }

}

void display ()
{
  node *curr = head;
  while (curr != NULL)
    {
      cout << curr->data << " ";
      curr = curr->next;
    }
}

int main(){
  insert (2);
  insert (1);
  insert (4);
  insert (6);
  insert (7);
  insert (5);
  insert (10);

  display ();
  delete_even_values ();
  cout << endl;
  display ();
  return 0;
}
