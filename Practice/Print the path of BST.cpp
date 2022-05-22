#include<iostream>

using namespace std;

struct node
{
    int data;
    node* left_child;
    node* right_child;
    node* parent;
};
node* root = NULL;
node* create_new_node(int value)
{
    node* newnode = new node;
    newnode->data = value;
    newnode->left_child = NULL;
    newnode->right_child = NULL;
    newnode->parent = NULL;

    return newnode;
}

node* insert_value(node* current_node, int value)
{
    if(current_node==NULL) {
        return create_new_node(value);
    }
    if(current_node->data>value) {
        current_node->left_child = insert_value(current_node->left_child,value);
        current_node->left_child->parent = current_node;
    }
    else {
        current_node->right_child = insert_value(current_node->right_child,value);
        current_node->right_child->parent = current_node;
    }

    return current_node;
}

void fun(node* curr){
    if(curr!=NULL){
        fun(curr->left_child);
        cout<< curr->data<< "->";
        fun(curr->right_child);
    }

}

void display_path(node* curr, int key){
    if(key==curr->data){
        cout<< curr->data<< endl;
    }
    else if(curr->data>key){
        cout<< curr->data<< endl;
        return display_path(curr->left_child, key);
    }
    else{
        cout<< curr->data<< endl;
        return display_path(curr->right_child, key);
    }
}

int main()
{
    root = insert_value(root, 8);
    root = insert_value(root, 3);
    root = insert_value(root, 10);
    root = insert_value(root, 1);
    root = insert_value(root, 6);
    root = insert_value(root, 4);
    root = insert_value(root, 7);
    root = insert_value(root, 14);
    root = insert_value(root, 13);
//    cout<< "Inoder: ";
//    fun(root);
//    cout<< "NULL";
    display_path(root, 13);

}

