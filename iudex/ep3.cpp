#include <iostream>

using namespace std;

class BSTNode {
public:
    int element;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int e) {
        this->element = e;
        this->left = this->right = nullptr;
    }
};

class BST {
private:
    BSTNode* root;
    int nodecount;
public:
    BST() {
        this->root = nullptr;
        this->nodecount = 0;
    }

    BSTNode* getRoot() { return this->root; }
    int getNodeCount() { return this->nodecount; }

    int find(int e) { return this->findhelp(this->root, e); }

    int findhelp(BSTNode* rt, int e) {
        if (rt == nullptr) { return -1; }
        if (rt->element > e) { return this->findhelp(rt->left, e); }
        else if (rt->element == e) { return rt->element; }
        else { return this->findhelp(rt->right, e); }
    }

    void insert(int e) {
        this->root = this->inserthelp(this->root, e);
        this->nodecount++;
    }

    BSTNode* inserthelp(BSTNode* rt, int e) {
        if (rt == nullptr) { return new BSTNode(e); }
        if (rt->element > e) { rt->left = this->inserthelp(rt->left, e); }
        else { rt->right = this->inserthelp(rt->right, e); }
        return rt;
    }

    void remove(int e) {
        int temp = this->findhelp(this->root, e);
        if (temp != -1) {
            this->root = this->removehelp(this->root, e);
            this->nodecount--;
        }
    }

    BSTNode* removehelp(BSTNode* rt, int e) {
        if (rt == nullptr) { return nullptr; }
        if (rt->element > e) { rt->left = this->removehelp(rt->left, e); }
        else if (rt->element < e) { rt->right = this->removehelp(rt->right, e); }
        else {
            if (rt->left == nullptr) { return rt->right; }
            else if (rt->right == nullptr) { return rt->left; }
            else {
                BSTNode* temp = this->getmin(rt->right);
                rt->element = temp->element;
                rt->right = this->deletemin(rt->right);
            }
        }
        return rt;
    }

    BSTNode* getmin(BSTNode* rt) {
        if (rt->left == nullptr) { return rt; }
        return this->getmin(rt->left);
    }

    BSTNode* deletemin(BSTNode* rt) {
        if (rt->left == nullptr) { return rt->right; }
        rt->left = this->deletemin(rt->left);
        return rt;
    }

    void posorder(BSTNode* rt) {
        if (rt != nullptr) {
            this->posorder(rt->left);
            this->posorder(rt->right);
            cout << rt->element << endl;
        }
    }
};

int main() {
    int qtd_commands;
    cin >> qtd_commands;
    BST bst;

    for (int i = 0; i < qtd_commands; i++) {
        string command;
        int num;
        cin >> command >> num;

        if (command == "ins") { bst.insert(num); }
        else if (command == "rem") { bst.remove(num); }
    }

    cout << bst.getNodeCount() << endl;
    bst.posorder(bst.getRoot());

    return 0;
}