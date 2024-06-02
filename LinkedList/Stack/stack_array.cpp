#include <bits/stdc++.h>
using namespace std;

struct Stack{ // array
private:
    int stack[100], size = 100, top = -1;

public:
    void push(int val){
        if(isFull()){
            cout << "OVERFLOW, the stack is full" << endl;
            return;
        }
        else{
            stack[++top] = val;
        }
    }

    int pop(){
        if(isEmpty()){
            cout << "UNDERFLOW, the stack is empty" << endl;
            return -1;
        }
        else{
            return stack[top--];
        }
    }

    int get_top(){
        if(isEmpty()){
            cout << "UNDERFLOW, the stack is empty" << endl;
            return -1;
        }
        else{
            return stack[top];
        }
    }


    bool isFull(){
        return (top == size - 1);
    }

    bool isEmpty(){
        return (top == -1);
    }

};

int main()
{
    Stack st;
    for(int i = 0; i < 100; i++){
        st.push(i);

    }
    for(int i = 0; i < 100; i++){   
        cout << st.get_top() << endl;
        st.pop();
    }
}