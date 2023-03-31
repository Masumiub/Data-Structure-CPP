/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

class stack{
private:
  int size;
  int top;
  int *arr;
    
public:
        stack(int size) {
            this->size = size;
            top = -1;
            arr = new int[size];
        }
        
    void push(int value){
        if(top == size-1){
            cout<< "The Stack is full"<< endl;
        }
        else{
            top++;
            arr[top] = value;
        }
    }
    
    
    void pop(){
        if(top==-1){
            cout<< "The Stack is empty"<< endl;
        }
        else{
            top--;
        }
    }

    int peak() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        
        return arr[top];
    }
    
    
};




int main()
{
    
    stack s(8);
    
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<< s.peak()<< endl;
    s.pop();
    s.peak();
    cout<< s.peak()<< endl;

    return 0;
}
