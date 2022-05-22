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

int Height(node* p){
    int x, y;
    if(p==NULL){
        return 0;
    }
    x= Height(p->lchild);
    y= Height(p->rchild);
    return x>y?x+1:y+1;
}

node* InPre(node* p){
    while(p && p->rchild!=NULL){
        p = p->rchild;
    }
    return p;
}

node* InSucc(node* p){
    while(p && p->lchild!=NULL){
        p = p->lchild;
    }
    return p;
}

node *Delete(node* p, int key){
    node* q;

    if(p==NULL){
        return NULL;
    }
    if(p->lchild==NULL && p->rchild==NULL){
        if(p==root){
            root = NULL;
        }
        free(p);
        return NULL;
    }
    if(key<p->data){
        p->lchild = Delete(p->lchild, key);
    }
    else if(key>p->data){
        p->rchild = Delete(p->rchild, key);
    }
    else{
        if(Height(p->lchild)>Height(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else{
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}


void delete_odd_nodes(node* curr){

    if(curr->lchild!=NULL && curr->rchild!=NULL){
        if(curr->data%2==1){
            Delete(root, curr->data);
            return;
        }
        delete_odd_nodes(curr->lchild);
        delete_odd_nodes(curr->rchild);
    }
    //return;
}

void delete_less_than(node* curr, int key){
    if(curr!=NULL){
       if(curr->data<key){
            Delete(root, curr->data);
            return;
        }
        delete_less_than(curr->lchild, key);
        delete_less_than(curr->rchild, key);
    }
}

int FindHeight(node* root){
    if(root == NULL){
        return -1;
    }
    return max(FindHeight(root->lchild), FindHeight(root->rchild))+1;
}
int main()
{
    root = insert(root, 10);
    insert(root, 7);
    insert(root, 8);
    insert(root, 0);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 12);
    insert(root, 9);
    insert(root, 21);
    insert(root, 17);

    insert(root, 19);
    insert(root, 25);
    insert(root, 36);
    insert(root, 39);

    delete_odd_nodes(root);

    delete_odd_nodes(root);
    //delete_less_than(root, 9);
    //delete_less_than(root, 9);
    display(root);

    return 0;
}
