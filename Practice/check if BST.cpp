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

void display(node* curr){ // preorder

    if(curr!=NULL){
        cout<< curr->data<< endl;
        display(curr->lchild);
        display(curr->rchild);
    }
}

int count20(node* curr, int count){
    if(curr!=NULL){
        if(curr->data> 20){
            count++;
        }
        //return count20(curr->lchild, count);
        return count20(curr->rchild, count);
    }
    return count;
}

int find_min(node* curr, int min){ //3455654

    if(curr!=NULL){
        if(curr->data< min){
            min = curr->data;
        }
        return find_min(curr->lchild, min);
    }
    return min;

}


void search_iterative(node* curr, int key){
    //node* curr = root;
    while(curr!=NULL){
        if(key==curr->data){
            cout<< key<< "is found!";
            break;
        }
        else if(key<curr->data){
            curr = curr->lchild;
        }
        else{
            curr = curr->rchild;
        }
    }
}


void R_search(node* curr, int key){
    if(curr==NULL){
        return;
    }
    if(key == curr->data){
        cout<< "Key found!";
    }
    else if(key<curr->data){
        return R_search(curr->lchild, key);
    }
    else{
        return R_search(curr->rchild, key);
    }
}

void inorder(node* curr){
    if(curr!=NULL){
        inorder(curr->lchild);
        cout<< curr->data<< " ";
        inorder(curr->rchild);
    }
}

void postorder(node* curr){
    if(curr!=NULL){
        postorder(curr->lchild);
        postorder(curr->rchild);
        cout<< curr->data<< " ";
    }
}

bool is_subtree_lesser(node* root, int value){
    if(root == NULL){
        return true;
    }
    if(root->data <= value && is_subtree_lesser(root->left, value) && is_subtree_lesser(root->right, value)){
         return true;
    }
    else{
        return false;
    }
}
bool is_subtree_geater(node* root, int value){
    if(root == NULL){
        return true;
    }
    if(root->data > value && is_subtree_geater(root->left, value) && is_subtree_geater(root->right, value)){
         return true;
    }
    else{
        return false;
    }
}
bool is_bst(node* root){
    if(root == NULL){
        return true;
    }
    if(is_subtree_lesser(root->lchild, root->data) && is_subtree_geater(root->rchild, root->data) && is_bst(root->lchild) && is_bst(root->rchild)){
        return true;
    }
    else{
        return false;
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
    display(root);

    //cout<< "There are"<< count20(root, 0)<< "larger than 20.";
    cout<< endl;
    //cout<< "Minimum value in this binary tree: "<< find_min(root, 3455654);
    cout<< endl;
    //search_iterative(root, 30);
    cout<< endl;
    R_search(root, 35);
    cout<< endl;
    //cout<< "Inorder format: ";
    //inorder(root);

    cout<< endl;
    //cout<< "Postorder format: ";
    //postorder(root);
}

