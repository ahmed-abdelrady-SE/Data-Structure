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
        node* temp = head;
        if (is_empty()) return false;
        do{
            if(temp -> data == data) 
                return true;
            temp = temp -> next;
        }
        while(temp!= head);
        return false;
    }

    int count(){
        if(is_empty()) return 0;

        int cnt = 0;
        node* temp = head;

        do{
            cnt ++;
            temp = temp -> next;
        }
        while(temp != head);
        return cnt;
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
            
            /* 
            we need to adjust the old tail -> next to be pointing to the new tail
            and we need to make the new tail -> next to point at the head
            */
            
            node* temp = head;
            while(temp -> next != head ){ // because the list is linked at the end to the head again so there is no "nullptr"
                temp = temp -> next;
            }

            temp -> next = newnode;
            newnode -> next = head;
        }

    }

    void DeleteFromHead(){
        
        if( is_empty() ){ return void( cout << "the List is Empty\n"); }
        
        /*
            we need to move the head one step forward and make the tail point to the new head and delete the old head
        */

        else if(head -> next == head){
            delete head;
            head = nullptr;
        }

       else{
            node* delptr = head;
            node* temp = head;
            while(temp -> next != head ){ // because the list is linked at the end to the head again so there is no "nullptr"
                temp = temp -> next;
            }

            head = head -> next;
            temp -> next = head;
            delete delptr;
        }
    }

    void DeleteFromTail(){
        if( is_empty() ){ return void( cout << "the List is Empty\n"); }

        else if(head -> next == head) DeleteFromHead();

        else{
            /*
                we need to link the new tail to the head and remove the old tail
            */
           node* prevdelptr = head;
           while(prevdelptr -> next -> next != head){
            prevdelptr = prevdelptr ->next;
           }
           delete prevdelptr -> next;
           prevdelptr -> next = head;
        }
    }

    void DeleteAtValue(int data){
        if( is_empty() ){ return void( cout << "the List is Empty\n"); }

        else if(head -> data == data) {
            DeleteFromHead();
            return;
        }

        else{
            node* delptr = head->next;
            node* prev = head;

            while(delptr != head && delptr -> data != data){
                prev = delptr;
                delptr = delptr -> next;
            }

            if(delptr -> data == data){
                prev -> next = delptr -> next;
                delete delptr;
                return;
            }

            return void ( cout << "Value : " << data << " not found in the list.\n" );

        }
    }

    void SearchForValue(int data){
        if(is_empty()){ return void( cout << "the list is empty\n" ); }
        if(!found(data)) return void( cout << "the value doesn't exist.\n" );

        node* temp = head;
        while(temp -> next != head && temp -> data != data){
            temp = temp -> next;
        }

        return void ( cout << "the value : \"" << data << "\" is found !\n" );


    }

};

int main(){
    cLinkedList CLL;
}