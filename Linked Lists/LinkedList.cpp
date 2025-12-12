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

    void AddFromHead(int value){
        node* temp = new node();
        temp -> data = value;

        if( is_empty() ){   //case 1 : adding the first ever node
            temp -> next = nullptr;
            head = temp;
        }
        else{    // case 2 : adding to an existing nodes
            temp -> next = head;
            head = temp;
        }
    }

    

};

int main(){

}