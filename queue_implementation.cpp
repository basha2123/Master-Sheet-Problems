#include<iostream>
using namespace std;


struct Queue{
    struct Node{
        int value;
        Node *next;
    };
    
    Node *f = NULL;
    Node *b = NULL;
    int size = 0;
    
    void enQueue(int val){
        Node *n = new Node;
        n -> value = val;
        //n -> next = NULL;
        
        if(b!=NULL){
            b -> next = n;
        }
        if( f == NULL){
            f = n;
        }
        b = n;
    }
    
    int front(){
        return f -> value;
    }
    
    int back(){
        return b -> value;
    }
    
    void deQueue(){
        Node *temp = f;
        f = f -> next;
        temp -> next = NULL;
        delete temp;
    }
};

int main(){
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    cout << q.front() << endl;
    q.deQueue();
    cout << q.back() << endl;
    return 0;
}



