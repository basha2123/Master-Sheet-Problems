#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insert(Node*& head, int val) {
    Node* newNode = new Node{val, NULL, NULL};

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void findPairs(Node* head, int target) {
    if (!head) return;

    Node* left = head;
    Node* right = head;

    while (right->next)
        right = right->next;

    while (left != right && right->next != left) {
        int sum = left->data + right->data;

        if (sum == target) {
            cout << "(" << left->data << ", " << right->data << ")" << endl;
            left = left->next;
            right = right->prev;
        }
        else if (sum < target) {
            left = left->next;
        }
        else {
            right = right->prev;
        }
    }
}

int main() {
    Node* head = NULL;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    int target = 5;

    cout << "Pairs : " << endl;
    findPairs(head, target);

    return 0;
}
