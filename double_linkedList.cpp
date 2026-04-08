#include<iostream>
using namespace std;
struct doubleList{
    struct Node{
        int value;
        Node *next;
        Node *prev;
    };
    
    Node *head = NULL;
    
    void insertAtEnd(int val){
        Node *n = new Node;
        n -> value = val;
        n -> next = NULL;
        n -> prev = NULL;
        
        if(head == NULL){
            head = n;
            return;
        }
        
        Node *temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        
        temp -> next = n;
        n -> prev = temp;
    }
    
    void insertAtBeg(int val){
        Node *n = new Node;
        n -> value = val;
        n -> prev = NULL;
        n -> next = head;
        
        if(head != NULL)
            head -> prev = n;
        head = n;
    }
    void insertInBw(int val, int index){
        Node *n = new Node;
        Node *temp = head;
        while(index -1 != 0){
            temp = temp -> next;
            index--;
        }
        n -> next = temp -> next;
        temp -> next = n;
        
        n -> value = val;
    }
    void deleteAtBeg(){
        if(head == NULL){
            cout << "Empty";
            return;
        }
        
        Node *temp = head;
        head = head -> next;
        
        if(head != NULL){
            head -> prev = NULL;
        }
        delete temp;
    }     
    
    void deleteAtEnd(){
        if(head == NULL){
            cout << "Empty";
            return;
        }
        if(head -> next == NULL){
            delete head;
            head = NULL;
            return;
        }
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->prev->next = NULL;
        delete temp;
    }
      
    void deleteInBw(int index){
        Node *temp = head;
        if(index == 0) return deleteAtBeg();
        while(index - 1 != 0){
            temp = temp-> next;
            index--;
        }
        Node *mid = temp -> next;
        
        temp->next = mid->next;
        mid->next->prev = temp;
        delete mid;
    } 
    
    void display(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp -> value << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
};

int main(){
    doubleList d;
    
    d.insertAtBeg(10);
    d.insertAtBeg(5);
    d.insertAtEnd(20);
    d.insertAtEnd(30);

    d.display();   

    d.insertAtBeg(12);
    d.display();   

    d.insertAtEnd(11);
    d.display(); 
    
    d.deleteInBw(3);
    d.display();

    return 0;
}
