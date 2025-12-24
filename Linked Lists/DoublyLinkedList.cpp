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

    int count(){
        int cnt = 0;
        node* temp = head;
        while(temp!= nullptr){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    void AddFromHead(int data){
        node* newnode = new node();
        newnode -> data = data;

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

    void DeleteFromTail(){
        if(is_empty()){ return void( cout << "the list is empty\n" ); }
        else{
            node* delptr = head;
            if(head->next == nullptr){
                head = nullptr;
            }
            else{
                while(delptr->next != nullptr){
                    delptr = delptr -> next;
                }
                delptr->prev->next = nullptr;
            }
            delete delptr;
        }
    }

    void deleteValue(int value){

        if(is_empty()){ return void( cout << "the list is empty\n" ); }
        
        else if(head-> data == value){ DeleteFromHead() ;} 

        else{

            node* delptr = head;
            while(delptr != nullptr && delptr->data != value ){
                delptr = delptr -> next;
            }

            if(delptr == nullptr) { return void( cout << "Value : " << value << " not found in the list.\n" ); }
            
            else{
                cout << "The value has been deleted succsifully";
                // we have two cases eathir the middle node or the last node
                if(delptr->next == nullptr){
                    delptr->prev->next = nullptr;
                }
                else{
                    delptr->prev->next = delptr -> next;
                    delptr->next->prev = delptr -> prev;
                }

                delete delptr;

            }
        }
        
    }

    void SearchForValue(int value){
        if(is_empty()){ return void( cout << "the list is empty\n" ); }
        if( !found(value) ) { return void( cout << "the value doesn't exist.\n"  ); }
        
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

    ~DLinkedList(){
        while(!is_empty()){
            DeleteFromHead();
        }
    }

};

int main(){
    DLinkedList DLL;    
}