#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left, *right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

struct BST{
private:
    TreeNode *root = NULL;
    void _insert(int val, TreeNode *cur){
        if(cur->data > val){
            if(cur->left == NULL) 
                cur->left = new TreeNode(val);
            else
                _insert(val, cur->left);
        }
        else if(cur->data < val){
            if(cur->right == NULL)
                cur->right = new TreeNode(val);
            else
                _insert(val, cur->right);
        }
        else{
            cout << "Value Already exist, Insert another value\n";
        }
    }
    bool _search(int val, TreeNode *cur){
        if(cur == NULL) return false;

        if(cur->data > val){
            return _search(val, cur->left);
        }
        else if(cur->data < val){
            return _search(val, cur->right);
        }
        else{
            return true;
        }
    }
    int _size(TreeNode *cur){
        if(cur == NULL) return 0;
        else{
            return (1 + _size(cur->left) + _size(cur->right));
        }
    }
    int _count_leafs(TreeNode *cur){
        if(cur == NULL) return 0;
        if(cur->left == NULL && cur->right == NULL) return 1;
        return (_count_leafs(cur->left) + _count_leafs(cur->right));
    }
    TreeNode *min_node(TreeNode *cur){
        if(cur == NULL || cur->left == NULL) return cur;
        else return min_node(cur->left);
    }
    TreeNode *_delete(int val, TreeNode *cur){
        if(cur == NULL) return NULL;
        if(cur->data > val){
            cur->left = _delete(val, cur->left);
        }
        else if(cur->data < val){
            cur->right = _delete(val, cur->right);
        }
        else{
            TreeNode *tmp = cur;

            if(cur->left == NULL && cur->right == NULL){  // case 1: no child
                cur = NULL;
            }
            else if(cur->left == NULL){                    // case 2: has right child only
                cur = cur->right;
            }
            else if(cur->right == NULL){                   // case 3: has left child only
                cur = cur->left;
            }
            else{                                           // case 4: has 2 children
                TreeNode *mn = min_node(cur->right);
                cur->data = mn->data;
                cur->right = _delete(cur->data, cur->right);
            }
            delete tmp;
        }
        return cur;
    }
    void _inOrder(TreeNode *cur){
        if(cur == NULL) return;

        _inOrder(cur->left);
        cout << cur->data << " ";
        _inOrder(cur->right);

    };
    void _preOrder(TreeNode *cur){
        if(cur == NULL) return;

        cout << cur->data << " ";
        _preOrder(cur->left);
        _preOrder(cur->right);

    };
    void _postOrder(TreeNode *cur){
        if(cur == NULL) return;

        _postOrder(cur->left);
        _postOrder(cur->right);
        cout << cur->data << " ";
    };

public:

    void insert(int val){
        if(!root){
            root = new TreeNode(val);
        }
        else{
            _insert(val, root);
        }
    }
    bool search(int val){
        return _search(val, root);
    }
    int size(){
        return _size(root);
    }
    int count_leafs(){
        return _count_leafs(root);
    }
    void delete_node(int val){
        _delete(val, root);
    }
    void inOrder(){
        _inOrder(root);
    }
    void preOrder(){
        _preOrder(root);
    }
    void postOrder(){
        _postOrder(root);
    }
};


int main() {
    BST bst;
    bst.insert(12);
    bst.insert(15);
    bst.insert(3);
    bst.insert(35);
    bst.insert(21);
    bst.insert(42);
    bst.insert(14);

    cout << endl << " ----------------- " << endl;
    cout << "inorder :"; bst.inOrder(); cout << endl;
    cout << "preorder :"; bst.preOrder(); cout << endl;
    cout << "postorder :"; bst.postOrder(); cout << endl;
    cout << endl << " ----------------- " << endl;
    cout << "search 12 : " << (bst.search(12) ? "found" : "not found") << endl;
    cout << "search 20 : " << (bst.search(20) ? "found" : "not found") << endl;
    cout << "search 14 : " << (bst.search(14) ? "found" : "not found") << endl;
    cout << endl << " ----------------- " << endl;
    cout << "size : " << bst.size() << endl;
    cout << endl << " ----------------- " << endl;
    cout << "count leafs : " << bst.count_leafs() << endl;
    cout << endl << " ----------------- " << endl;
    cout << "delete 42 " << endl;
    bst.delete_node(42);
    cout << endl << " ----------------- " << endl;
    cout << "inorder :"; bst.inOrder(); cout << endl;
    cout << "preorder :"; bst.preOrder(); cout << endl;
    cout << "postorder :"; bst.postOrder(); cout << endl;


}