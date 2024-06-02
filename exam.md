## Question 2
### 1
```cpp
    inorder   : 1 3 4 5 6 8 9 10 11 12 20 21 30 31
    preorder  : 9 5 3 1 4 8 6 20 12 10 11 30 21 31
    postorder : 1 4 3 6 8 5 11 10 12 21 31 30 20 9 
```

### 2
```cpp
    struct Node{
        int data;
        Node* next;
        Node(int d) : data(d), next(NULL){}
    };

    Node* buildLinkedList(int a[], int n){
        Node* head = new Node(a[0]); // n > 0
        Node* temp = head;
        for(int i = 1; i < n; i++){
            temp->next = new Node(a[i]);
            temp = temp->next;
        }
        return head;
    }
```

## Question 3
### a-1
```cpp
    void insert(int val){
        Node *newNode = new Node(val);
        if(first == NULL){
            first = last = newNode;
        }
        else{
            last->next = newNode;
            last = newNode;
        }
    }
```
### a-2
```cpp
    struct TreeNode{
        int data;
        TreeNode *left, *right;
        TreeNode(int d) : data(d), left(NULL), right(NULL){}
    };
    int countLeafs(TreeNode *root){
        if(root == NULL) return 0;
        if(root->right == NULL && root->left == NULL) return 1;

        return countLeafs(root->left) + countLeafs(root->right);
    }
```

## Question 4
### a
```cpp
     12
    /  \
   3   15
      /  \     
     14  35
        /  \
       21  42
```
### b
<img src= "./../graph.png" width = "300px">

### c
```cpp
    void enqueue(Node *front, Node *rear, int val){
        Node *temp = new Node(val);
        if(rear == NULL){
            front = rear = temp;
        }
        else{
            rear->next = temp;
            rear = temp
        }
    }
```


