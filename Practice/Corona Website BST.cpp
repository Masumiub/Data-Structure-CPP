#include<iostream>
using namespace std;

struct node{
    string name;
    string phone;
    int status;
    node* lchild;
    node* rchild;
};

node* root = NULL;

node* insert(node* p, string in_name, string in_phone, int in_status){
    node* new_node;
    if(p == NULL){
        new_node = new node;
        new_node->name = in_name;
        new_node->phone = in_phone;
        new_node->status = in_status;

        new_node->lchild = new_node->rchild = NULL;
        return new_node;
    }
    if(in_name< p->name){
        p->lchild = insert(p->lchild, in_name, in_phone, in_status);
    }
    else if(in_name> p->name){
        p->rchild = insert(p->rchild, in_name, in_phone, in_status);
    }
    return p;
}

void inorder(node* curr){
    if(curr!=NULL){
        inorder(curr->lchild);
        cout<< curr->name<< "->"<< curr->phone<< "->"<< curr->status<< endl;
        inorder(curr->rchild);
    }
}

void R_search(node* curr, string phone_num){
    if(curr==NULL){
        return;
    }
    if(curr->phone == phone_num){
        cout<< "Found!"<< curr->name<< "-> Status: "<< curr->status<< endl;
    }
    else if(curr->phone< phone_num){
        return R_search(curr->lchild, phone_num);
    }
    else{
        return R_search(curr->rchild, phone_num);
    }
}

//counting how many corona positives are here
int counting_positives(node* curr, int count){ // right sub tree
    if(curr!=NULL){
        if(curr->status == 1){
            count++;
        }
        return counting_positives(curr->rchild, count);
    }
    return count;
}

int counting_positives2(node* curr, int count){ // left sub tree
    if(curr!=NULL){
        if(curr->status == 1){
            count++;
        }
        return counting_positives(curr->lchild, count);
    }
    return count;
}

//delete leaf nodes
node* delete_leaf_node(node* root){
    if(root == NULL){
        return NULL;
    }
    if(root->lchild == NULL && root->rchild == NULL ){
        free(root);
        return NULL;
    }
    root->lchild = delete_leaf_node(root->lchild);
    root->rchild = delete_leaf_node(root->rchild);

    return root;
}

//displaying those people are negative
void display_corona_negative(node* root){
    if(root!=NULL){
        display_corona_negative(root->lchild);
        if(root->status == 0){
            cout<< "Corona Neg: "<< root->name<< endl;
        }
        display_corona_negative(root->rchild);
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

node* delete_node(node* p, string in_name){
    node * q;
    if(p == NULL){
        return NULL;
    }
    if(p->lchild == NULL && p->rchild == NULL){
        if(p == root){
            root = NULL;
        }
        free(p);
        return NULL;
    }
    if(in_name<p->name){
        p->lchild = delete_node(p->lchild, in_name);
    }
    else if(in_name>p->name){
         p->rchild = delete_node(p->rchild, in_name);
    }
    else{
        if(Height(p->lchild)>Height(p->rchild)){
            q = InPre(p->lchild);
            p->name = q->name;
            p->phone = q->phone;
            p->status = q->status;
            p->lchild = delete_node(p->lchild, q->name);
        }else{
            q = InSucc(p->rchild);
            p->name = q->name;
            p->phone = q->phone;
            p->status = q->status;
            p->rchild = delete_node(p->rchild, q->name);
        }
    }
    return p;
}

// delete all negative patients
node* delete_negative(node* curr){
    if(curr == NULL){
        return NULL;
    }
    if(curr!=NULL){
        if(root->status == 0){
            delete_node(root, curr->name);
        }
        if(curr->status == 0){
            delete_node(curr, curr->name);
        }
    }
    curr->lchild = delete_negative(curr->lchild);
    curr->rchild = delete_negative(curr->rchild);

    return curr;
}


void delete_negative2(node* curr){
    if(curr==NULL) return;
    if(curr!=NULL){
        if(curr->status == 0){
            delete_node(root, curr->name);
        }
        delete_negative2(curr->lchild);
        delete_negative2(curr->rchild);
    }
}
int main(){
    root = insert(root, "ABC", "123344354", 0);
    insert(root, "BGFS", "124354644354", 0);
    insert(root, "CDSY", "1246475354", 1);
    insert(root, "DDFG", "0987275354", 1);
    insert(root, "EFDU", "0097275354", 0);
    insert(root, "FDU", "0075354", 1);
    insert(root, "GJDU", "776685354", 0);
    insert(root, "HGJDU", "776685354", 1);

    //delete_leaf_node(root);
    //delete_node(root, "FDU");
    //display_corona_negative(root);

    delete_negative(root);
    inorder(root); // displaying

    //R_search(root, "0097275354");

    //cout<<"There are " <<counting_positives(root, 0) + counting_positives2(root, 0)<< "Positives cases."<< endl;
    return 0;
}
