#include<iostream>
using namespace std;

struct node{
    string data;
    node* lchild;
    node* rchild;
};
node* root = NULL;

node* insert(node* p, string key){
    node* t;
    if(p==NULL){
        t = new node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key<p->data){
        p->lchild = insert(p->lchild, key);
    }
    else if(key>p->data){
        p->rchild = insert(p->rchild, key);
    }
    return p;
}

void preorder(node* curr){ // preorder

    if(curr!=NULL){
        cout<< curr->data<< ",";
        preorder(curr->lchild);
        preorder(curr->rchild);
    }

}

void inorder(node* curr){ // preorder

    if(curr!=NULL){
        inorder(curr->lchild);
        cout<< curr->data<< ",";
        inorder(curr->rchild);
    }

}

void postorder(node* curr){
    if(curr!=NULL){
        postorder(curr->lchild);
        postorder(curr->rchild);
        cout<< curr->data<< ",";
    }

}


int main()
{
    root = insert(root, "Leia");
    insert(root, "Boba");
    insert(root, "Darth");
    insert(root, "R2D2");
    insert(root,"Han");
    insert(root, "Luke");
    insert(root, "Chewy");
    insert(root, "Palpatine");
    insert(root, "Jabba");
    insert(root, "Anakin");



    preorder(root);
    cout<< endl;
    inorder(root);
    cout<< endl;
    postorder(root);

}
