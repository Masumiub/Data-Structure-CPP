#include <iostream>
#include <stack>
using namespace std;

int main(){
    int size,num;
    cin>> size;
    stack<int>input_stack, tmp_stack;
    for(int i = 0; i<size ; i++){
        cin>> num;
        input_stack.push(num);
    }
    while(!input_stack.empty()){
        int K = input_stack.top();
        input_stack.pop();
        while(!tmp_stack.empty() && tmp_stack.top()<K){
            input_stack.push(tmp_stack.top());
            tmp_stack.pop();
        }
        tmp_stack.push(K);
    }

    while(!tmp_stack.empty()){
        cout<< tmp_stack.top()<< " ";
        tmp_stack.pop();
    }
}
