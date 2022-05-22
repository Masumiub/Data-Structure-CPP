#include<iostream>
using namespace std;
struct BstNode{
    int data;
    BstNode* left;
    BstNode* right;
}
BstNode* GetNewNode(int data){
    BstNode* newNode = new BstNode();
    newNode->data=data;
    newNode->left= newNode->right = NULL;
    return newNode;
}

void Insert(BstNode** rootPtr, int data){
    if(*root==NULL){
        *root= GetNewNode(data);
        return root;
    }
}

int main(){
    BstNode* root=NULL // pointer to root node, empty tree
    root = Insert(&root, 15);
    root = Insert(&root, 10);
    root = Insert(&root, 20);
}
