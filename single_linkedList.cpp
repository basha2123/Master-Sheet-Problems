#include<iostream>
using namespace std;

struct Linkedlist{
    struct Node{
        int value;
        Node *next;
    };
    
    Node *head = NULL;
    
    void insertAtEnd(int val){
        Node *n = new Node;
        n -> value = val;
        n -> next = NULL;
        
        if(head == NULL){
            head = n;
        }
        else{
            Node *temp = head;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = n;
        }
    }
    
    void insertAtBeg(int val){
        Node *n = new Node;
        n -> value = val;
        n -> next = head;
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
        head = head->next;
        delete temp;
    }
    
    void deleteAtEnd(){
    if(head == NULL) return;

    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

    void deleteInBw(int index){
        Node *temp = head;
        if(index == 0) return deleteAtBeg();
        // else if()
        while(index - 1 != 0){
            temp = temp-> next;
            // if(index == temp)
            index--;
        }
        Node *mid = temp -> next;
        
        temp -> next= mid -> next;
        mid -> next = NULL;
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
    Linkedlist l;
    l.insertAtBeg(10);
    l.insertAtEnd(20);
    l.insertAtEnd(30);
    
    l.insertInBw(15,2);
    
    l.display();
    
    l.deleteInBw(0);
    l.display();
    
    return 0;
}

