#include<iostream>
#include<queue>
using namespace std;

struct node{
    int data;
    node* lchild;
    node* rchild;
};
node* root = NULL;

node* insert(node* p, int key){
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

void inorder(node* curr){
    if(curr!=NULL){
        inorder(curr->lchild);
        cout<< curr->data<< " ";
        inorder(curr->rchild);
    }
}

void LevelOrder(node* root){
    if(root == NULL){
        return;
    }
    queue<node*>Q;
    Q.push(root);

    while(!Q.empty()){
        node* curr = Q.front();
        Q.pop();
        cout<< curr->data<< " ";
        if(curr->lchild!=NULL){
            Q.push(curr->lchild);
        }
        if(curr->rchild!=NULL){
            Q.push(curr->rchild);
        }

    }


}
int main()
{
    root = insert(root, 30);
    insert(root, 10);
    insert(root, 20);
    insert(root, 40);
    insert(root, 50);
    insert(root, 35);
    insert(root, 5);
    //inorder(root);
    LevelOrder(root);
}
