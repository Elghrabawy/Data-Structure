#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

struct LinkedList{ 
    Node *head, *tail;

    LinkedList() : head(NULL), tail(NULL){}

    LinkedList(int a[], int n) : head(NULL), tail(NULL){
        for (int i = 0; i < n; i++) {
            insert_back(a[i]);
        }
    }

    void print(){
        Node *curr = head;
        while(curr != NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    void insert_front(int val){ // backward
        Node *newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }   

    void insert_back(int val){ // forward
        Node *newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void delete_front(){ // backward
        if(head == NULL) {
            cout << "the list is empty!\n";
        }
        else if(head -> next == NULL){
            delete head;
            head = tail = NULL;
        }
        else{
            Node *temp = head;
            head = head->next;
            delete temp;
        }

    }

    void delete_back(){ // forward
        if(head == NULL){
            cout << "the list is empty!\n";
        }
        else if(head->next == NULL){
            delete head;
            head = tail = NULL;
        }
        else {
            Node *temp = head;
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            delete tail;
            temp->next = NULL;
            tail = temp;
        }
    }

    Node* search(int val){
        Node *curr = head;
        while(curr != NULL){
            if(curr->data == val) return curr;
            curr = curr->next;
        }

        return curr;
    }


    int count(){
        Node *curr = head;
        int cnt = 0;
        while(curr != NULL){
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }

    void sort(){

    }
};

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    LinkedList ls(a, 5);
    
    ls.print();
    cout << endl;

}
