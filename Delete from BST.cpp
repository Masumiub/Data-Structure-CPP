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

bool search_value(node* current_node, int value)
{
    if(current_node==NULL) {
        return false;
    }
    if(current_node->data == value) {
        return true;
    }
    else if(current_node->data>value) {
        return search_value(current_node->left_child,value);
    }
    else {
        return search_value(current_node->right_child,value);
    }
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

void preorder_traversal(node* current_node)
{
    if(current_node!=NULL) {
        cout<<current_node->data<<endl;
        preorder_traversal(current_node->left_child);
        preorder_traversal(current_node->right_child);
    }
}

void inorder_traversal(node* current_node)
{
    if(current_node!=NULL) {
        inorder_traversal(current_node->left_child);
        cout<<current_node->data<<endl;
        inorder_traversal(current_node->right_child);
    }
}


void inorder_search(node* current_node, int given_value)
{
    if(current_node!=NULL) {
        inorder_search(current_node->left_child,given_value);
        if(current_node->data==given_value) {
            cout<<"match found\n";
        }
        inorder_search(current_node->right_child,given_value);
    }
}

node* find_min(node* current_node)
{
    if(current_node->left_child!=NULL)
        return find_min(current_node->left_child);
    return current_node;
}

node* search_node(node* current_node, int value)
{
    if(current_node==NULL) {
        return current_node;
    }
    if(current_node->data == value) {
        return current_node;
    }
    else if(current_node->data>value) {
        return search_node(current_node->left_child,value);
    }
    else {
        return search_node(current_node->right_child,value);
    }
}

void replace_node(node* old_node, node* new_node)
{
    if(old_node->parent!=NULL) {
        if(old_node->data > old_node->parent->data) {
            old_node->parent->right_child = new_node;
        }
        else {
            old_node->parent->left_child = new_node;
        }
    }
    else {
        root = new_node;
    }
    if(new_node!=NULL) {
        new_node->parent = old_node->parent;
    }
}

void delete_value(int given_value)
{
    node* node_to_be_deleted = search_node(root,given_value);
    if(node_to_be_deleted==NULL) {
        return;
    }
    else {
        if(node_to_be_deleted->left_child==NULL) {
            replace_node(node_to_be_deleted,node_to_be_deleted->right_child);
        }
        else if(node_to_be_deleted->right_child==NULL) {
            replace_node(node_to_be_deleted,node_to_be_deleted->left_child);
        }
        else {
            node* min_node = find_min(node_to_be_deleted->right_child);
            if(min_node==node_to_be_deleted->right_child) {
                replace_node(node_to_be_deleted, node_to_be_deleted->right_child);
                min_node->left_child = node_to_be_deleted->left_child;
                min_node->left_child->parent = min_node;
            }
            else {
                replace_node(min_node,min_node->right_child);
                replace_node(node_to_be_deleted,min_node);
                min_node->left_child = node_to_be_deleted->left_child;
                min_node->left_child->parent = min_node;
                min_node->right_child = node_to_be_deleted->right_child;
                min_node->right_child->parent = min_node;
            }
        }
        delete node_to_be_deleted;
    }
}

int main()
{
    root = insert_value(root, 10);
    root = insert_value(root, 7);
    root = insert_value(root, 13);
    root = insert_value(root, 4);
    root = insert_value(root, 20);
    root = insert_value(root, 11);
    root = insert_value(root, 18);
    //preorder_traversal(root);
    //cout<<endl;
    inorder_traversal(root);
    cout<<endl;
    delete_value(13);
    inorder_traversal(root);
    //inorder_search(root,7);
    //cout<<find_min(root)<<endl;
    //cout<<search_value(root,8)<<endl;
}
