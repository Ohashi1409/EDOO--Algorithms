#include <iostream>

using namespace std;

template <typename Key>
class BSTNode {
public:
    Key key;
    BSTNode* left;
    BSTNode* right;

    BSTNode(Key k) {
        this->key = k;
        this->left = this->right = nullptr;
    }
};

template <typename Key>
class BST {
private:
    BSTNode<Key>* root;
    int nodecount;
public:
    BST() {
        this->root = nullptr;
        this->nodecount = 0;
    }

    Key find(Key k) {
        return this->findhelp(this->root, k);
    }

    Key findhelp(BSTNode<Key>* rt, Key k) {
        if (rt == nullptr) { return nullptr; }
        if (rt->key > k) { return this->findhelp(rt->left, k); }
        else if (rt->key == k) { return rt->key; }
        else { return this->findhelp(rt->right, k); }
    }

    void insert(Key k) {
        this->root = this->inserthelp(this->root, k);
        this->nodecount++;
    }

    BSTNode<Key>* inserthelp(BSTNode<Key>* rt, Key k) {
        if (rt == nullptr) { return new BSTNode<Key>(k); }
        if (rt->key > k) { rt->left = this->inserthelp(rt->left, k); }
        else { rt->right = this->inserthelp(rt->right, k); }
        return rt;
    }

    Key remove(Key k) {
        Key temp = this->findhelp(this->root, k);
        if (temp != nullptr) {
            this->root = this->removehelp(this->root, k);
            this->nodecount--;
        }
        return temp;
    }

    BSTNode<Key>* removehelp(BSTNode<Key>* rt, Key k) {
        if (rt == nullptr) { return nullptr; }
        if (rt->key > k) { rt->left = this->removehelp(rt->left, k); }
        else if (rt->key < k) { rt->right = this->removehelp(rt->right, k); }
        else {
            if (rt->left == nullptr) { return rt->right; }
            else if (rt->right == nullptr) { return rt->left; }
            else {
                BSTNode<Key> temp = this->getmin(rt->right);
                rt->key = temp.key;
                rt->right = this->deletemin(rt->right);
            }
        }
        return rt;
    }

    BSTNode<Key>* getRoot() { return this->root; }

    BSTNode<Key>* getmin(BSTNode<Key>* rt) {
        if (rt->left == nullptr) { return rt; }
        return this->getmin(rt->left);
    }

    BSTNode<Key>* deletemin(BSTNode<Key>* rt) {
        if (rt->left == nullptr) { return rt->right; }
        rt->left = this->deletemin(rt->left);
        return rt;
    }

    void preorder(BSTNode<Key>* rt) {
        if (rt != nullptr) { 
            cout << rt->key << " "; 
            this->preorder(rt->left);
            this->preorder(rt->right);
        }
    }

    void inorder(BSTNode<Key>* rt) {
        if (rt != nullptr) {
            this->inorder(rt->left);
            cout << rt->key << " ";
            this->inorder(rt->right);
        }
    }

    void posorder(BSTNode<Key>* rt) {
        if (rt != nullptr) {
            this->posorder(rt->left);
            this->posorder(rt->right);
            cout << rt->key << " ";
        }
    }
};

int main() {
    BST<int> bst;
    int qtd_op;
    cin >> qtd_op;
    for (int i = 0; i < qtd_op; i++) {
        string op;
        cin >> op;
        if (op == "insert") {
            int num;
            cin >> num;
            bst.insert(num);
        }
        else if (op == "pre"){
            bst.preorder(bst.getRoot());
            cout << endl;
        }
        else if (op == "in") {
            bst.inorder(bst.getRoot());
            cout << endl;
        }
        else if (op == "post") {
            bst.posorder(bst.getRoot());
            cout << endl;
        }
    }
 
    return 0;
}