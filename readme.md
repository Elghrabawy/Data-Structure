<!-- ## Table of Contents -->

- [linear data structures](#linear-data-structures)
  - [Linked list](#linked-list)
    - [Singly Linked List](#singly-linked-list)
    - [Doubly Linked List](#doubly-linked-list)
  - [Stack](#stack)
    - [stack using array](#stack-using-array)
    - [stack using linked list](#stack-using-linked-list)
  - [Queue](#queue)
    - [queue using array](#queue-using-array)
      - [linear queue](#linear-queue)
      - [circular queue](#circular-queue)
    - [queue using linked list](#queue-using-linked-list)
  - [Linear Priority Queue](#linear-priority-queue)
- [non-linear data structures](#non-linear-data-structures)
- [sorting algorithms](#sorting-algorithms)
  - [insertion sort](#insertion-sort)
  - [selection sort](#selection-sort)
  - [bubble sort](#bubble-sort)
  - [quick sort](#quick-sort)
  - [merge sort](#merge-sort)
  - [counting sort](#counting-sort)
- [searching algorithms](#searching-algorithms)
  - [binary search](#binary-search)
<hr/>

<center>

## linear data structures

</center>

### Linked list
#### Singly Linked List
- Node implementation
```cpp
struct Node{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};
 ```
- Linked List implementation
```cpp
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
            head = newNode;
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
```

#### Doubly Linked List

<hr/>

### Stack

#### stack using array
```cpp
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
```

#### stack using linked list
- Node implementation
```cpp
struct Node{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};
```
- Stack implementation
```cpp

struct Stack{ // linked list
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
```
<hr/>

### Queue
#### queue using array
##### linear queue
```cpp

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
```

##### circular queue
```cpp
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
```

#### queue using linked list
- Node implementation
```cpp
struct Node{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};
```

- Queue implementation
```cpp
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
```
<hr/>

### Linear Priority Queue

<hr/>



<center>

## non-linear data structures

</center>

<hr/>

<center>

## sorting algorithms

</center>

### insertion sort
- Time Complexity
    - Best Case : O(n)
    - Worst Case : O(n<sup>2</sup>)
    - Average Case : O(n<sup>2</sup>)

- Main Idea
```
Scan all elements from a[1] to a[n - 1].
insert elemnt a[k] in correct possition in previously sorted sub-array.
```

- Steps
```
1.  repeat lines 2-4 for all i from 1 to size - 1.
2.  set key = arr[i] and j = i - 1.
3.  for all elements arr[j] greater than key:
        (a) shift it right.
        (b) decrease j with one.
    end loop
4.  put key in correct position -> a[j + 1] = key.

``` 
- using swaping
```cpp
void insertion_sort(int a[], int n){
    for(int i = 1; i < n; i++){
        int j = i - 1;
        while(j >= 0 && a[j] > a[j + 1]){
            swap(a[j], a[j + 1]);
            j--;
        }
    }
}
```
- using shifting and insert to correct position
```cpp
void insertion_sort_2(int a[], int n){
    for(int i = 1; i < n; i++){
        int j = i - 1, key = a[i];
        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
```

### selection sort
- Time Complexity
    - Best Case : O(n<sup>2</sup>)
    - Worst Case : O(n<sup>2</sup>)
    - Average Case : O(n<sup>2</sup>)


- Main idea
```
then find ith smallest element and set it in the ith position (1 <= i <= n)
```

- Steps
```
loop for all i from 0 to n - 1
    (a) find minimum element from i to end of array
    (b) swap a[i] and minimum element so on
end loop
```

- Code
```cpp
int smallest(int a[], int start, int end){
    int min_i = start;
    for(int i = start + 1; i < end; i++){
        if(a[i] < a[min_i]){
            min_i = i;
        }
    }
    return min_i;
}

void selection_sort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        int smallest_i = smallest(a, i, n);
        swap(a[i], a[smallest_i]);
    }
}
```

### bubble sort
### quick sort
- make a pivot function (2 ways implemented)
```cpp
int partition_1(int a[], int l, int r){
    int pivot = a[r];
    int i = l - 1;

    for(int j = l; j <= r; j++){
        if(a[j] < pivot){
            i++;
            swap(a[j], a[i]);
        }
    }

    swap(a[r], a[i + 1]);
    return i + 1;
}
int partition_2(int a[], int l, int r){
    int pivot = a[l];
    int i = l, j = r;

    while(i < j){
        while(a[i] <= pivot)
            i++;
        while(a[j] > pivot)
            j--;
        if(i < j)
            swap(a[i], a[j]);
    }
    swap(a[l], a[j]);
    return j;
}
```
- quick sort function
```cpp
void quick_sort(int a[], int l, int r){
    if(l < r){
        int pivot = partition_2(a, l, r);
        quick_sort(a, l, pivot - 1);
        quick_sort(a, pivot + 1, r);
    }
}

void quick_sort(int a[], int n){
    quick_sort(a, 0, n - 1);
}
```

### merge sort
### counting sort

<hr/>


<center>

## searching algorithms

</center>

### binary search
```cpp
int binary_search(int a[], int n, int key){
    int l = 0, r  = n - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(a[mid] > key){
            r = mid - 1;
        }
        else if(a[mid] < key){
            l = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
```

<hr/>