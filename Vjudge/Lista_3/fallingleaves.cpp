#include <iostream>
#include <stack>

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

    BSTNode<Key>* inserthelp(BSTNode<Key>* rt, Key k) {
        if (rt == nullptr) { return new BSTNode<Key>(k); }
        if (rt->key > k) { rt->left = this->inserthelp(rt->left, k); }
        else { rt->right = this->inserthelp(rt->right, k); }
        return rt;
    }

    void deletehelp(BSTNode<Key>* rt) {
        if (rt != nullptr) {
            this->deletehelp(rt->left);
            this->deletehelp(rt->right);
            delete rt;
        }
    }

public:
    BST() { this->root = nullptr; }

    ~BST() { this->deletehelp(this->root); }

    void insert(Key k) { this->root = this->inserthelp(this->root, k); }

    BSTNode<Key>* getRoot() { return this->root; }

    void print(BSTNode<Key>* rt) {
        if (rt != nullptr) { 
            cout << rt->key; 
            this->print(rt->left);
            this->print(rt->right);
        }
    }
};

int main() {
    stack<string> stack;
    string line;
    cin >> line;
    while (line != "$") {
        if (line == "*") {
            BST<char> bst;
            string nodes;
            while (!stack.empty()) {
                nodes += stack.top();
                stack.pop();
            }
            for (char ch : nodes) {
                bst.insert(ch);
            }
            bst.print(bst.getRoot());
            cout << endl;
        }
        else {
            stack.push(line);
        }
        cin >> line;
    }
    BST<char> bst;
    string nodes;
    while (!stack.empty()) {
        nodes += stack.top();
        stack.pop();
    }
    for (char ch : nodes) {
        bst.insert(ch);
    }
    bst.print(bst.getRoot());
    cout << endl;

    return 0;
}