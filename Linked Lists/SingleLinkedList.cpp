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
            if(temp -> data == data) 
                return true;
            temp = temp -> next;
        }
        return false;
    }
    
    int count(){
        int cnt = 0;
        node* temp = head;
        while(temp != nullptr){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    void AddFromHead(int value){
        node* newnode = new node();
        newnode -> data = value;
        newnode -> next = head;
        head = newnode;
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

    void DeleteFromHead(){
        if(is_empty()){ return void( cout << "the list is empty\n" ); }
        else {
            node* delptr = head;
            head = head->next;
            delete delptr;
        }        
    }

    void DeleteFromTail(){
        if(is_empty()){ return void( cout << "the list is empty\n" ); }

        if(head-> next == nullptr ) { delete head ; head = nullptr; }

        else{

            node* prevdel = head; 

            while (prevdel->next->next != nullptr) {
                prevdel = prevdel->next;
            }

            delete prevdel -> next;
            prevdel -> next = nullptr;

        }

    }

    void deleteValue(int value){
        if(is_empty()){ return void( cout << "the list is empty\n" ); }
        
        node* delptr = head;

        if(head->data == value){ // first case : if value in head
            head = head->next;
            delete delptr;
        } 

        else{   // second case : if value in any other node
            node* prev = nullptr;
            
            while (delptr != nullptr && delptr->data != value) {
                prev = delptr;       
                delptr = delptr->next;
            }

            if(delptr == nullptr) {return void ( cout << "Value : " << value << " not found in the list.\n" ); }

            prev->next = delptr->next;
            delete delptr; 

        }
    }

    void SearchForValue(int value){
        if(is_empty()){ return void( cout << "the list is empty\n" ); }
        if(!found(value)) return void( cout << "the value doesn't exist.\n" );
        
        node* temp = head;

        while(temp != nullptr && temp->data != value){
            temp = temp -> next;
        }

        return void ( cout << "the value : \"" << value << "\" is found !\n" );

    }

    void PrintList(){
        node* temp = head;
        cout << "This list has " << count() << " nodes :-\n";
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    ~LinkedList(){
        while(!is_empty()){
            DeleteFromHead();
        }
    }

};

int main(){
    LinkedList l;
}