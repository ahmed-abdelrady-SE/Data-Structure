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
class binary_tree{
private:

    node<T>* root;

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

    T max_value(node<T>* root){
        if(!root->left && !root->right) return root->data;

        T maxval = root->data;
        if(root->left){
            maxval = max(maxval, max_value(root->left));
        }
        if(root->right){
            maxval = max(maxval, max_value(root->right));
        }

        return maxval;
    }

    T min_value(node<T>* root){
        if(!root->left && !root->right) return root->data;

        T minval = root->data;
        if(root->left){
            minval = min(minval, min_value(root->left));
        }
        if(root->right){
            minval = min(minval, min_value(root->right));
        }

        return minval;
    }

    int tree_height(node<T>* root){
        if(root == nullptr) return 0;

        return max( tree_height(root->left) , tree_height(root->right) ) + 1;
    } 

    bool search(node<T>* root , T target){
        if (root == nullptr) return false;
        if (root->data == target) return true;

        return search(root->left,target) || search(root->right, target);
    }

    void destructor(node<T>* node){
        if(node == nullptr) return;
        destructor(node->left);
        destructor(node->right);
        delete node;
    }


public:

    binary_tree(){
        root = nullptr;
    }

    void set_root(T value){
        root = new node<T>(value);
    }

    void print_inorder(){
        inorder(root);
        cout << "\n";
    }

    void print_postorder(){
        postorder(root);
        cout << "\n";
    }

    void print_preorder(){
        preorder(root);
        cout << "\n";
    }

    T get_max_value(){
        return max_value(root);
    }

    T get_min_value(){
        return min_value(root);
    }

    int get_tree_height(){
        return tree_height(root);
    }

    bool search_element(int target){
        return search(root, target);
    }

    ~binary_tree(){
        destructor(root);
    }

};

int main(){
    binary_tree<int> bt;
    bt.set_root(50);
}