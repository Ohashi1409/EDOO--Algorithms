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

    BSTNode<Key>* getRoot() { return this->root; }

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
    int n;
    cin >> n;
    BST<int> bst;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        bst.insert(num);
    }

    cout << "Pre order : ";
    bst.preorder(bst.getRoot());
    cout << endl;

    cout << "In order  : ";
    bst.inorder(bst.getRoot());
    cout << endl;

    cout << "Post order: ";
    bst.posorder(bst.getRoot());
    cout << endl;

    return 0;
}