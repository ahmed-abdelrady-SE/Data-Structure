#include <bits/stdc++.h>
using namespace std;

class node{

    public:

    int data;
    node* next;

    node(){
        data = 0;
        next = nullptr;
    }
};

class Stack_LL{
    public:

    node* top;
    Stack_LL(){
        top = nullptr;
    }

    bool is_empty(){
        return !top;
    }

    bool is_full(){
        
    }

    void push(int data){
        node* newnode = new node();
        newnode->data = data;
        
    }

    void pop(){

    }

    int peek(){

    }

    int size(){

    }

    void print(){

    }

};

int main(){

}