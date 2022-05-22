#include<iostream>
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

int count_nodes(node* curr){
    static int count=0;
    if(curr!=NULL){
        count++;
        count_nodes(curr->lchild);
        count_nodes(curr->rchild);
    }
    return count;
}

int sum_value(node* curr){
    static int sum=0;
    if(curr!=NULL){
        sum+=curr->data;
        sum_value(curr->lchild);
        sum_value(curr->rchild);
    }
    return sum;
}

void display_leaf_node(node* curr){

    if(curr==NULL){
        return;
    }
    if(curr->lchild==NULL && curr->rchild==NULL){
        cout<< curr->data<< " ";
        return;
    }
    display_leaf_node(curr->lchild);
    display_leaf_node(curr->rchild);

}

void check_leaf_node(node* curr){
    if(curr==NULL){
        return;
    }
    if(curr->lchild==NULL && curr->rchild==NULL){
        if(curr->data%2==0){ cout<<"Even"<< endl;}
        else{ cout<<"Odd"<< endl;}
        return;
    }
    check_leaf_node(curr->lchild);
    check_leaf_node(curr->rchild);
}

void InPre(node* curr){
    if(curr==NULL){
        return;
    }
    if(curr->rchild==NULL){
        cout<< curr->data;
    }
    InPre(curr->rchild);
}

void InSucc(node* curr){
    if(curr==NULL){
        return;
    }
    if(curr->lchild==NULL){
        cout<< curr->data;
    }
    InSucc(curr->lchild);
}

int main()
{
    root = insert(root, 10);
    root =insert(root, 5);
    root =insert(root, 13);
    root =insert(root, 3);
    root =insert(root, 7);
    root =insert(root, 14);
    //insert(root, 5);
    inorder(root);
    //int total_sum = sum_value(root);
    //cout<< "\nThe Sum of BST Nodes: "<<total_sum;
    //int total_nodes = count_nodes(root);
    //cout<< total_nodes ;
    //float median = total_sum/ total_nodes;

    //cout<< "Median: "<< median ;
    cout<< endl;
    display_leaf_node(root);
    cout<< endl;
    cout<< endl;
    check_leaf_node(root);
    cout<< endl;
    cout<< endl;
    InPre(root->lchild);
    cout<< endl;
    cout<< endl;
    InSucc(root->rchild);
}
