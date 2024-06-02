#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left, *right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

struct BinaryTree{
    TreeNode *root;

    void inOrder(TreeNode *cur){
        if(cur == NULL) return;

        inOrder(cur->left);
        cout << cur->data << " ";
        inOrder(cur->right);

    };
    void preOrder(TreeNode *cur){
        if(cur == NULL) return;

        cout << cur->data << " ";
        preOrder(cur->left);
        preOrder(cur->right);

    };
    void postOrder(TreeNode *cur){
        if(cur == NULL) return;

        postOrder(cur->left);
        postOrder(cur->right);
        cout << cur->data << " ";
    };
};

int main() {
    BinaryTree bt;
    bt.root = new TreeNode(1);
    bt.root->left = new TreeNode(2);
    bt.root->right = new TreeNode(3);
    bt.root->left->left = new TreeNode(4);
    bt.root->left->right = new TreeNode(5);
    bt.root->right->left = new TreeNode(6);
    bt.root->right->right = new TreeNode(7);

    cout << "Inorder: "; bt.inOrder(bt.root);
    cout << "\nPreorder: "; bt.preOrder(bt.root);
    cout << "\nPostorder: "; bt.postOrder(bt.root);
}