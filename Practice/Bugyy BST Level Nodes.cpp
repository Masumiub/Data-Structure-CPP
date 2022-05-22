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


int count_node(node* curr, int curr_level, int given_level, int count){
    if(curr != NULL){
        return count;
    }
    if(curr_level == given_level){
         count++;
    }
    return count_node(curr->lchild, curr_level, given_level, count);
    return count_node(curr->rchild, curr_level, given_level, count);
return count;

}

void find_product(node* root, int &counter){
    if(root == NULL || (root->lchild == NULL && root->rchild == NULL) ){
   // if(root == NULL || (root->lchild == NULL && root->rchild == NULL)){
        return;
    }
    if(root->lchild != NULL || root->rchild != NULL){
        counter *= root->data;
    }
    find_product(root->lchild, counter);
    find_product(root->rchild, counter);
}

int nodesatlevel(node* curr, int level){
    if(curr == NULL){
        return 0;
    }
    if(level ==0){
        return 1;
    }
    return nodesatlevel(curr->lchild, level-1) + nodesatlevel(curr->rchild, level-1);
}
int main()
{
    root = insert(root, 12);
    insert(root, 5);
    insert(root, 15);
    insert(root, 4);
    insert(root, 13);
    insert(root, 20);
    insert(root, 17);
    insert(root, 24);
    inorder(root);
cout<< endl;
//cout<< count_node(root, 1, 3, 0);
cout<< nodesatlevel(root, 2);
cout<< endl;
//int counter=1;
//find_product(root,counter);
//cout<< counter<< endl;

    //cout<< "Minimum value in this binary tree: "<< find_min(root, 3455654);
    cout<< endl;
    //search_iterative(root, 30);
    cout<< endl;
    //R_search(root, 35);
    cout<< endl;
    //cout<< "Inorder format: ";
    //inorder(root);

    cout<< endl;
    //cout<< "Postorder format: ";
    //postorder(root);
}
