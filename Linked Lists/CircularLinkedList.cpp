#include <bits/stdc++.h>
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

class cLinkedList{

    public :

    node* head;

    cLinkedList(){
        head = nullptr;
    }

    bool is_empty(){
        return !head;
    }

    bool found(int data){

    }

    int count(){

    }

    void AddFromHead(int data){
        node* newnode = new node();
        newnode -> data = data;

        if( is_empty() ){
            head = newnode;
            head -> next = head;
        }

        else{    // moving the head to the new head and adjusting the new head -> next and adjusting the next of the last node
            node* temp = head;
            while(temp -> next != head ){ // because the list is linked at the end to the head again so there is no "nullptr"
                temp = temp -> next;
            }

            newnode->next = head;
            head = newnode;
            temp->next = head;
        }
    }

    void AddFromTail(int data){
        node* newnode = new node();
        newnode -> data = data;

        if( is_empty() ){
            AddFromHead(data);
        }

        else{  

        }

    }

};

int main(){
    
}