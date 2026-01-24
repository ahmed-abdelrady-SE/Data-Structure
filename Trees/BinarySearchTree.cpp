#include <bits/stdc++.h>
using namespace std;

template <typename T>
class node{
public:

    T data;
    node* right;
    node* left;

    node(T data){
        this->data = data;
        right = left = nullptr;
    }

};

template <typename T>
class binarysearch_tree{
private:

    node<T>* root;

    node<T>* insert(node<T>* Node ,T item){
        if(!Node){
            return new node<T>(item);
        }
        else{
            if(item < Node->data){
                Node->left = insert(Node->left , item);
            }
            else{
                Node->right = insert(Node->right , item);
            }
        }
        return Node;
    }

    void inorder(node<T>* root){
        if(root == nullptr) return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void postorder(node<T>* root){
        if(root == nullptr) return;

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    void preorder(node<T>* root){
        if(root == nullptr) return;

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    bool search(node<T>* node, T item) {
        if (node == nullptr) return false;
        if (node->data == item) return true;

        if (item < node->data)
            return search(node->left, item);
        else
            return search(node->right, item);
    }

    T max_value(node<T>* node){
        if(!node or !node->right) return node->data;

        return max_value(node->right);
    }

    T min_value(node<T>* node){
        if(!node or !node->left) return node->data;

        return min_value(node->left);
    }

    int tree_height(node<T>* root){
        if(root == nullptr) return 0;

        return max( tree_height(root->left) , tree_height(root->right) ) + 1;
    } 

    void destructor(node<T>* node){
        if(node == nullptr) return;
        destructor(node->left);
        destructor(node->right);
        delete node;
    }

public:

    binarysearch_tree(){
        root = nullptr;
    }

    void insert(T item){
        root = insert(root, item);
    }

    void inorder(){
        inorder(root);
        cout << "\n";
    }

    void postorder(){
        postorder(root);
        cout << "\n";
    }

    void preorder(){
        preorder(root);
        cout << "\n";
    }

    bool search(T item){
        return search(root, item);
    }

    T max_value(){
        return max_value(root);
    }

    T min_value(){
        return min_value(root);
    }

    int tree_height(){
        return tree_height(root);
    }

    ~binarysearch_tree(){
        destructor(root);
    }

};

int main(){
    binarysearch_tree<int> bst;
    bst.insert(20);
    bst.insert(50);
    bst.insert(10);
    bst.insert(60);
    bst.insert(30);
    bst.insert(15);
    bst.insert(5);
    cout << bst.max_value() << "\n";
    cout << bst.min_value() << "\n";
    cout << bst.tree_height() << "\n";
    bst.inorder();
    bst.preorder();
    bst.postorder();
}