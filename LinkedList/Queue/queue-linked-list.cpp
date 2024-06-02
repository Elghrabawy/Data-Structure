#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

struct Queue{ //queue using linked list
private:
    Node *front = NULL, *rear = NULL;
    
public:
    void enqueue(int val){
        Node *newNode = new Node(val);
        if(isEmpty()){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
    };
    void dequeue(){
        if(isEmpty()){
            cout << "queue is empty" << endl;
        }
        else if(front == rear){
            delete front;
            front = rear = NULL;
        }
        else{
            
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    };
    void display_queue(){
        Node *curr = front;
        while(curr != NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    };
    int get_front(){
        if(isEmpty()){
            cout << "queue is empty" << endl;
            return -1;
        }
        else{
            return front->data;
        }
    }
    bool isEmpty(){
        return (front == NULL);
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout << "Front : " << q.get_front() << endl;
    cout << "queue : ";
    q.display_queue();

    q.dequeue();
    q.dequeue();

    cout << "Front : " << q.get_front() << endl;
    cout << "queue : ";
    q.display_queue();

    cout << "Front : " << q.get_front() << endl;
    cout << "queue : ";
    q.display_queue();

    q.enqueue(3);
    q.enqueue(4);

    cout << "Front : " << q.get_front() << endl;
    cout << "queue : ";
    q.display_queue();

    q.dequeue();
    cout << "Front : " << q.get_front() << endl;
    q.dequeue();
    cout << "Front : " << q.get_front() << endl;
    q.dequeue();
    cout << "Front : " << q.get_front() << endl;
    cout << "queue : ";
    q.display_queue();

    q.dequeue();
    cout << "Front : " << q.get_front() << endl;
}