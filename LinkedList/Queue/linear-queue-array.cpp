#include <bits/stdc++.h>
using namespace std;

struct Queue{ // linear queue using array
    int queue[100], SIZE = 100, front = -1, rear = -1;

    void enqueue(int val){
        if(isFull()){
            cout << "OVERFLOW, the queue is full" << endl;
        }
        else{
            queue[++rear] = val;
            if(front == -1)
                front = 0;
        }
    }

    void dequeue(){
        if(isEmpty()){
            cout << "UNDERFLOW, the queue is empty" << endl;
        }
        else if(front == rear){
            front = rear = -1;
        }
        else{
            front++;
        }
    }

    int get_front(){
        if(isEmpty()){
            cout << "the queue is empty" << endl;
            return -1;
        }
        else{
           return queue[front];
        }
    }

    void display_queue(){
        if(isEmpty()){
            cout << "the queue is empty" << endl;
        }
        else{
            for(int i = front; i <= rear; i++){
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
    bool isEmpty(){
        return (front == -1 && rear == -1);
    }

    bool isFull(){
        return (rear == SIZE - 1);
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