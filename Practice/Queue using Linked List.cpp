#include<iostream>
using namespace std;

struct node{
    int data;
    node* link;
};
node* front=NULL;
node* rear=NULL;

bool isempty(){
    if(front==NULL && rear ==NULL){
        return true;
    }
    else{
        return false;
    }
}

void enqueue(int value){
    node* ptr= new node();
    ptr->data = value;
    ptr->link=NULL;

    if(front==NULL){
        front=ptr;
        rear= ptr;
    }
    else{
        rear->link=ptr;
        rear=ptr;
    }
}

void dequeue(){
if(isempty()){
    cout<< "Queue is empty.";
}else{
    if(front==rear){
        delete front;
        front=rear=NULL;
    }
    else{
        node* ptr=front;
        front=front->link;
        delete ptr;
    }
}

}

void showfront(){
if(isempty()){
    cout<< "Queue is empty.";
}else{
    cout<< front->data;
}
}

void displayQueue(){
    if(isempty()){
        cout<< "Queue is empty.";
    }
    else{
        node *ptr = front;
        while(ptr!=NULL){
            cout<< ptr->data<< " ";
            ptr= ptr->link;
        }

    }

}
int main(){
enqueue(1);
enqueue(2);
enqueue(3);
enqueue(4);
enqueue(5);
displayQueue();
}
