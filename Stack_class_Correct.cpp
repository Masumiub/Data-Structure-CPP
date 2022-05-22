#include<iostream>
using namespace std;

int mystack[4];
int stack_size =4;
int top=-1;

bool isempty(){
    if(top==-1){
        return true;
    }
    return false;
}

bool isfull(){
    if(top==stack_size-1){
        return true;
    }
     return false;
}

void push(int value){
    if(isfull()==false){
        top++;
        mystack[top]=value;
    }
    else{
        cout<< "Stack is Full\n";
    }
}

void pop(){
    if(isempty()==false){
        top--;
    }
    else{
        cout<< "Stack is empty"<<endl;
    }
}


int peek(){
    if(isempty()==false)
        return mystack[top];
}
int main(){
for(int i=0; i<3; i++){
    push(i);
    cout<< top<< endl;
}

}
