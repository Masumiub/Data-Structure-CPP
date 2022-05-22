/*pre
root-> left->right

in order
left-> root->right

post order
left-> right-> root*/

#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* root = NULL;

node* create_new_node(int value){
node* newnode= new node;
newnode->data = value;
newnode->left = NULL;
newnode->right = NULL;

return newnode;
}

node* insert_value(node* curr, int value){
    if(curr==NULL){
        return create_new_node(value);
    }
    if(curr->data>=value){
        curr->left = insert_value(curr->left, value);
    }else{
        curr->right = insert_value(curr->right, value);
    }

    return curr;
}


bool search_value(node* curr, int value){
    if(curr==NULL){
        return false;
    }
    if(curr->data==value){
        return true;
    }
    if(curr->data> value){
        return search_value(curr->left, value);
    }
    else{
         return search_value(curr->right, value);
    }
}

int main(){

root = insert_value(root, 10);
root = insert_value(root, 9);
root = insert_value(root, 13);

cout<< search_value(root, 8);
return 0;
}
