#include <iostream>
using namespace std;

class node{      // the main class for the nodes in the linked list 
    
    public:

    int data;  
    node* next;

    node(){
        data = 0;
        next = nullptr;
    }

};

class LinkedList{
    public:

    node* head;

    LinkedList(){
        head = nullptr;
    }

    bool is_empty(){
        return !head;
    }

    bool found(int data){
        node* temp = head;
        while(temp != nullptr){
            if(temp -> data = data) 
                return true;
            temp = temp -> next;
        }
        return false;
    }

    void AddFromHead(int value){
        node* newnode = new node();
        newnode -> data = value;

        if( is_empty() ){   //case 1 : adding the first ever node
            newnode -> next = nullptr;
            head = newnode;
        }
        else{    // case 2 : adding to an existing nodes
            newnode -> next = head;
            head = newnode;
        }
    }

    void AddFromTail(int value){
        node * newnode = new node();
        node *temp = head;    // to reach the tail
        newnode -> data = value;

        if( is_empty() ){   //case 1 : adding the first ever node
            newnode -> next = nullptr;
            head = newnode;
        }
        else{
            while(temp -> next != nullptr){  // so we stop at the last node
                temp = temp -> next;
            } 
            temp ->next = newnode;
            newnode -> next = nullptr;
        }
    }

};

int main(){

}