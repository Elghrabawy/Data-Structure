#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

struct Stack{ // linked-list
private:
    Node *head = NULL;

public:
    void push(int val){
        Node *newNode = new Node(val);
        if(head == NULL){
            head = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    int pop(){
        if(isEmpty()){
            cout << "UNDERFLOW, the stack is empty" << endl;
            return -1;
        }
        else{
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    int get_top(){
        if(isEmpty()){
            cout << "the stack is empty" << endl;
            return -1;
        }
        else{
            return head->data;
        }
    }

    bool isEmpty(){
        return (head == NULL);
    }
};

int main()
{
    Stack st;
    for(int i = 0; i < 100; i++){
        st.push(i);

    }
    st.push(20);
    for(int i = 0; i < 100; i++){   
        cout << st.get_top() << endl;
        st.pop();
    }
    st.pop();
    st.pop();
}