#include <iostream>
#include<stdlib.h>
using namespace std;

struct Stack{
   
   struct Node{
       int value;
       Node *next;            
   };
   
   int size = 0;
   Node *top = NULL;
   
   void push(int val){
       Node *n = new Node;
       n->value = val;
        if(top == NULL){
          n->next == NULL;
      }
      else
          n->next = top;
       top = n;
       size++;
   }
   
    void pop(){
        if(top == NULL)
            cout << "Empty";
        else
            top = top -> next;
        size--;
    }
   
    int peek(){
        if(top == NULL)
            cout<<"Empty";
        return top->value;
    }
};

int main()
{
   Stack s;
   s.push(1);
   s.push(2);
   s.push(3);
   s.pop();
   s.pop();
   cout<< "peek" << endl;
   cout<<s.peek();

   return 0;
}
