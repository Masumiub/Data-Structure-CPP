#include<iostream>
#include<string>
using namespace std;

/*struct stack{
    int size;
    int top;
    char *s;
}*/
//stack using linked list;
struct node{
    int data;
    node* next;
}*Top=NULL;


void push(char x){
    node* new_node = new node;
    if(Top==NULL){
        cout<< "Stack is Full."<< endl;
    }
    else{
        new_node->data = x;
        new_node->next = Top;
        Top = new_node;
    }
}

char pop(){
    node* curr;
    char x=-1;
    if(Top == NULL){
        cout<< "Stack is Empty"<< endl;
    }
    else{
        curr = Top;
        Top = Top->next;
        x= curr->data;
        delete curr;
    }
    return x;
}

void display(){
    node* curr;
    curr= Top;
    while(curr!= NULL){
        cout<< curr->data;
        curr = curr->next;
    }
    cout<< endl;
}
int is_balance(char *exp){
    /*struct stack st;
    st.size=strlen(exp);
    st.Top =-1;
    st.s = new char[st.size];*/

    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i]=='('){
            //push(&st, exp[i]);
            push(exp[i]);
        }else if(exp[i]==')'){
            /*if(isempty(st)){
                return false;
            }else{
            pop(&st);
            }*/
            if(Top == NULL){
                return 0;
            }
            pop();
        }
    }
    if(Top==NULL){
        return 1; // true =1
    }
    else{
        return 0; // false =0
    }
    //return isempty(st)? true:false;

}

int main(){
    char *exp="((a+b)*(c-d))))";
    cout<< is_balance(exp);
    return 0;
}
