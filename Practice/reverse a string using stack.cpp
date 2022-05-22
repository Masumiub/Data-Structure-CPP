#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct stack_words{
    char A[101];
    int str_size;
    int stack_size =str_size;
    int mystack[101];
    int top=-1;

bool isempty(){
    if(top==-1) return true;
    return false;
}
bool isfull(){
    if(top == stack_size-1){
        return true;
    }
    return false;
}
void push(char c){
    if(isfull() == false){
        top++;
        mystack[top] = c;
    }
    else{
        cout<< "Stack is Full\n";
    }
}

void pop(){
    if(isfull() == false){
        top--;
    }else{
        cout<< "Stack is Full\n";
    }
}

int peek(){
    if(isempty()==false)
        return mystack[top];
    else
        return 0;
}
};

void reverse_str(char *C, int n){

    stack_words S;
    for(int i =0 ; i<n ; i++){
        S.push(C[i]);
    }
    for(int i =0 ; i<n ; i++){
        C[i] = S.peek(); //overwrite the characer at index i;
        S.pop(); // perform pop;
    }
}


int main(){

    char C[51];
    cout<< "Enter a string: ";
    gets(C);

    int str_size = strlen(C);

    reverse_str(C, strlen(C));
    cout<< "Output: "<< C;
    /*cout<< "Stacking elements: ";
    for(int i=0; i<3; i++){
        push(i);
        cout<< top<< endl;
    }
    cout<< "Reversing elements: ";
    for(int i=0; i<3; i++){
        pop(i);
        //cout<< top<< endl;
    }*/

return 0;
}
