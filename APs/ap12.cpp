#include <iostream>

using namespace std;

template <typename Key, typename E>
class BSTNode {
private:
    Key key;
    E element;
    BSTNode* left;
    BSTNode* right;
public:
    BSTNode(Key k, E e) {
        this->key = k;
        this->element = e;
        this->left = this->right = nullptr;
    }
};

template <typename Key, typename E>
class BST {
private:
    BSTNode<Key, E>* root;
    int nodecount;
public:
    BST() {
        this->root = nullptr;
        this->nodecount = 0;
    }

    E find(Key k) {
        return this->findhelp(this->root, k)
    }

    E findhelp(BSTNode<Key, E>* rt, Key k) {
        if (rt == nullptr) { return nullptr; }
        if (rt->key > k) { return findhelp(rt->left, k); }
        else if (rt->key == k) { return rt->element; }
        else { return findhelp(rt->right, k); }
    }

    void insert(Key k, E e) {
        this->root = inserthelp();
        this->nodecount++;
    }

    BSTNode* inserthelp(BSTNode<Key, E>* rt, Key k, E e) {
        if (rt == nullptr) { return new BSTNode(k, e); }
        if (rt->key > k) { rt->left = inserthelp(rt->left, k, e); }
        else { rt->right = inserthelp(rt->right, k, e); }
        return rt;
    }

    E remove(Key k) {
        E temp = findhelp(this->root, k);
        if (temp != nullptr) {
            
        }
    }

    BSTNode* removehelp(BSTNode<Key, E>* rt, Key k) {
        if (rt == nullptr) { return nullptr; }
        if (rt->key > k) { rt->left = removehelp(rt->left, k); }
        else if (rt->key < k) { rt->right = removehelp(rt->right, k); }
        else {
            if (rt->left == nullptr) { return rt->right; }
            else if (rt->right == nullptr) { return rt->left; }
            else {
                BSTNode<Key, E> temp = getmin(rt->right);
                rt->element = temp.element;
                rt->key = temp.key;
                rt->right = deletemin(rt->right);
            }
        }
        return rt;
    }

    BSTNode* getmin(BSTNode<Key, E>* rt) {
        if (rt->left == nullptr) { return rt; }
        return 
    }

    BSTNode* deletemin(BSTNode<Key, E>* rt) {
        if (rt->left == nullptr) { return rt->right; }
        rt->left = deletemin(rt->left);
        return rt;
    }

    void preorder(BSTNode<Key, E>* rt) {
        if (rt != nullptr) { 
            cout << rt->element << endl; 
            preorder(rt->left);
            preorder(rt->right);
        }
    }

    void inorder(BSTNode<Key, E>* rt) {
        if (rt != nullptr) {
            inorder(rt->left);
            cout << rt->element << endl;
            inorder(rt->right);
        }
    }

    void posorder(BSTNode<Key, E>* rt) {
        if (rt != nullptr) {
            posorder(rt->left);
            posorder(rt->right);
            cout << rt->element << endl;
        }
    }
};

int main() {
    int qtd_op;
    cin >> qtd_op;
    for (int i = 0; i < qtd_op; i++) {
        string op;
        cin >> op;
        if (op == "insert") {
            int num;
            cin >> num;
        }
        else if (op == "pre"){

        }
        else if (op == "in") {

        }
        else if (op == "post") {

        }
    }
 
    return 0;
}