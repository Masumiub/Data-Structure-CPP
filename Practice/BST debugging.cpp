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
node* root2 = NULL;

node* create_new_node(int value)
{
    node* newnode = new node;
    newnode->data = value;
    newnode->left_child = NULL;
    newnode->right_child = NULL;
    newnode->parent = NULL;

    return newnode;
}

int mul(node* curr, int cnt){
    if(curr->left_child!=NULL && curr->left_child!=NULL){
        return (cnt*curr->data);

    }
    else{
        return mul(curr->left_child, cnt);
        return mul(curr->right_child, cnt);
    }
    return cnt;
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
/*
void fun(node* curr){
    if(curr!=NULL){
        fun(curr->left_child);
        fun(curr->right_child);
        cout<< curr->data<< " "<< curr->parent->data<< endl;
    }
}*/
// in conventional postorder display,  we dont need to show every nodes' parent,
// if we write only curr->parent , then it gonna print every nodes' parents' address,
// we need to write curr->parent->data to show parent data. but at last 10 (root) has
// no parent, here we will get an error. & program will exit.

void fun2(node* curr){
    if(curr!=NULL){
        cout<< curr->data<< endl;
        fun2(curr->left_child);
        fun2(curr->right_child);
    }
}
//in preorder traversal, curr->data must be in first. (in preorder root/parent comes at first)
//in recursive func, if we use while loop, then the base condition/termination condition
//wont work. it will be infinity loop// We must use "if" & then the base

void find_min(node* current_node)
{
    if(current_node->left_child==NULL){
        cout<< "Minimum value: "<<current_node->data;
    }
    else{
        return find_min(current_node->left_child);
    }
}

void find_max(node* current_node)
{
    if(current_node->right_child==NULL){
        cout<< "\nMax value: "<<current_node->data;
    }
    else{
        return find_max(current_node->right_child);
    }
}

void check_twoBST_equal(node* curr, node* curr2){ // normal
    int count = 0;
    while((curr->right_child!=NULL && curr2->right_child!=NULL) && (curr->left_child!=NULL && curr2->left_child!=NULL)){
        if(curr->data == curr2->data){
            count++;
        }
        curr = curr->left_child;
        curr2 = curr2->left_child;
        //curr = curr->right_child;
        //curr2 = curr2->right_child;
    }
if(count>1){
    cout<< "Equal"<< endl;
}
else{
    cout<< "Not Equal!"<< endl;
}
}

int main()
{
    root = insert_value(root, 12);
    root = insert_value(root, 5);
    root = insert_value(root, 15);
    root = insert_value(root, 4);
    root = insert_value(root, 13);
    root = insert_value(root, 20);
    root = insert_value(root, 17);
root = insert_value(root, 24);


    root2 = insert_value(root2, 15);
    root2 = insert_value(root2, 73);
    root2 = insert_value(root2, 13);
    root2 = insert_value(root2, 4);
    root2 = insert_value(root2, 20);
    root2 = insert_value(root2, 11);
    root2 = insert_value(root2, 18);
cout<< mul(root, 1);
    //fun2(root2);
    //check_twoBST_equal(root, root2);
    //find_min(root);
    //find_max(root);
    return 0;
}
