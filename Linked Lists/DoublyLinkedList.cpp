#include <bits/stdc++.h>
using namespace std;

class node{      // the main class for the nodes in the linked list 
    
    public:

    int data;  
    node* next;
    node* prev;

    node(){
        data = 0;
        next = nullptr;
        prev = nullptr;
    }

};

class DLinkedList{
    public:

    node* head;

    DLinkedList(){
        head = nullptr;
    }

    bool is_empty(){
        return !head;
    }

    bool found(int data){
        node* temp = head;
        while(temp != nullptr){
            if(temp -> data == data) 
                return true;
            temp = temp -> next;
        }
        return false;
    }

    void AddFromHead(int value){
        node* newnode = new node();
        newnode -> data = value;

        if(is_empty()){  // case 1 the list is empty
            newnode->next = nullptr;
            newnode->prev = nullptr;
            head = newnode;
        }

        else{   // case 2 adding to an existing nodes
            newnode -> next = head;
            newnode -> prev = nullptr;
            head->prev = newnode;
            head = newnode; 
        }
    }

    void AddFromTail(int value){
        node* newnode = new node();
        node* temp = head;  // to reach the tail

        if(is_empty()){  // case 1 the list is empty
            AddFromHead(value);
        }

        else{

            while(temp->next != nullptr){     // reaching the tail with the temp ptr
                temp = temp->next;
            }

            newnode -> data = value;
            newnode -> next = nullptr;
            newnode -> prev = temp;
            temp -> next  = newnode;

        }

    }

    void DeleteFromHead(){
        if(is_empty()){ return void( cout << "the list is empty\n" ); }
        else{
            node* delptr = head;

            if(head->next == nullptr){
                head = nullptr;
            }

            else{
                head = head->next;
                head -> prev = nullptr;
            } 

            delete delptr;
        }
    }



};

int main(){
    DLinkedList DLL;
}