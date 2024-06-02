#include <bits/stdc++.h>
using namespace std;

struct Queue{ //circular queue using array
private:
    int queue[100], SIZE = 100, front = -1, rear = -1;
public:
    void enqueue(int val){
        if(isFull()){
            cout << "the queue is full" << endl;
        }
        else if(isEmpty()){
            rear = front = 0;
            queue[rear] = val;
        }
        else{
            rear = (rear + 1) % SIZE;
            queue[rear] = val;
        }
    };

    void dequeue(){
        if(isEmpty()){
            cout << "the queue is empty" << endl;
        }
        else if(front == rear){ // have one element
            front = rear = -1;
        }
        else{
            front = (front + 1) % SIZE;
        }
    };
    void display_queue(){
        if(isEmpty()){
            cout << "the queue is empty!" << endl;
        }
        else {
            int i = front, j = rear;

            if((rear + 1) % SIZE == front){
                cout << queue[front] << " ";
                i++; 
                i %= SIZE;
            }
            while((i % SIZE) != ((j + 1) % SIZE)){
                cout << queue[i] << " ";
                i++;
                i %= SIZE;
            }
            cout << endl;
        }
    };
    int get_front(){
        if(isEmpty()){
            cout << "queue is empty!" << endl;
            return -1;
        }
        else{
            return queue[front];
        }
    }
    bool isEmpty(){
        return (front == -1);
    }
    bool isFull(){
        return (front == (rear + 1) % SIZE);
        // (front = rear + 1) || (front == 0 && rear == size - 1). 
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