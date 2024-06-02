#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data, priority; 
    Node *next;
    Node(int val) : data(val), priority(0), next(NULL) {}
    Node(int val, int p) : data(val), priority(p), next(NULL) {}
};

struct PriorityQueue{
    Node *first = NULL, *last = NULL;

    void insert(int val, int per){
        Node *newNode = new Node(val);
        if(first == NULL || per < first->priority){
            newNode->next = first;
            first = newNode;
        }
        else{
            Node *cur = first;
            while(cur != NULL && cur->next->priority <= per){
                cur = cur->next;
            }

            newNode->next = cur->next;
            cur = newNode;
        }
    }

    void del(){
        if(first == NULL){
            cout << "UNDERFLOW.. Queue is empty\n";
        }
        else{
            Node *tmp = first;
            first = first->next;
            delete tmp;
        }
    }
};

int main()
{
}