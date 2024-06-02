#include <bits/stdc++.h>
using namespace std;

struct BinaryTree{
    char tree[100];
    BinaryTree(char key){
        memset(tree, '\0', sizeof tree);
        tree[0] = key;
    }

    int left(int parent){
        return (2 * parent + 1);
    }

    int right(int parent){
        return (2 * parent + 2);
    }

    void setLeft(char key, int parent){
        if(tree[parent] == '\0'){
            cout << "Can't set child at " << (parent * 2) + 1 << ", no parent found";
        }
        else{
            tree[left(parent)] = key;
        }
    }

    void setRight(char key, int parent){
        if(tree[parent] == '\0'){
            cout << "Can't set child at " << (parent * 2) + 2 << ", no parent found";
        }
        else{
            tree[right(parent)] = key;
        }
    }

    void inOrder(int parent){
        if(parent < 100 && tree[parent] != '\0'){
            inOrder(left(parent));
            cout << tree[parent] << " ";
            inOrder(right(parent));
        }
    }
    void preOrder(int parent){
        if(parent < 100 && tree[parent] != '\0'){
            cout << tree[parent] << " ";
            preOrder(left(parent));
            preOrder(right(parent));
        }
    }
    void postOrder(int parent){
        if(parent < 100 && tree[parent] != '\0'){
            cout << tree[parent] << " ";
            postOrder(left(parent));
            postOrder(right(parent));
        }
    }
};

int main() {
    BinaryTree bt('A');
    bt.setLeft('B', 0);
    bt.setRight('C', 0);
    bt.setLeft('D', 1);
    bt.setRight('E', 1);
    bt.setLeft('F', 2);
    bt.setRight('G', 2);
    
    cout << "inorder : "; bt.inOrder(0); cout << endl;
    cout << "preorder : "; bt.preOrder(0); cout << endl;
    cout << "postorder : "; bt.postOrder(0); cout << endl;
    return 0;
}