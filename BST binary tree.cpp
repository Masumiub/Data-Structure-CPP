#include<iostream>
#include<vector>
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

int FindHeight(node* root){
    if(root == NULL){
        return -1;
    }
    return max(FindHeight(root->lchild), FindHeight(root->rchild))+1;
}

int flag =1;
int solve(node* root){
    if(root == NULL) return 0;
    int l = solve(root->lchild);
    int r = solve(root->rchild);
    if(abs(l-r)>1) flag =0;
    return max(l,r)+1;
}

bool isBalanced(node* root){
    flag =1;
    solve(root);
    return flag;
}

void helper(vector<int>& res, node* root, int d){
    if(root==NULL)return;
    if(d == res.size()){
        res.push_back(root->data);
    }
    else{
        res[d] = max(res[d], root->data);
    }
    helper(res, root->lchild, d+1);
    helper(res, root->rchild, d+1);
}
vector<int>largest_value_in_level(node* root){
    vector<int>res;
    helper(res,root,0);
    return res;
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

    Delete(root, 10);
    display(root);
    cout<< "Height of this BST: "<< FindHeight(root);
    //cout<< "There are"<< count20(root, 0)<< "larger than 20.";
    cout<< endl;
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

    vector<int>res = largest_value_in_level(root);
    for(int i =0; i<res.size(); i++){
        cout<< res[i]<< " ";
    }
}
