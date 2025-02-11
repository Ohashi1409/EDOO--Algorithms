#include <iostream>

using namespace std;

template <typename E>
class Node {
public:
    E element;
    Node* next;

    Node(Node* nextVal) {
        this->next = nextVal;
    }

    Node(E it, Node* nextVal) {
        this->element = it;
        this->next = nextVal;
    } 
};

template <typename E>
class Stack {
private:
    Node<E>* top;
    int size;

public:
    Stack() {
        this->top = nullptr;
        this->size = 0;
    }

    ~Stack() { clear(); }

    void clear() {
        while (this->top != nullptr) {
            Node<E>* temp = this->top;
            this->top = this->top->next;
            delete temp;
        }
        this->size = 0;
    }

    void push(E item) {
        this->top = new Node<E>(item, this->top);
        this->size++;
    }

    E pop() {
        if (this->top == nullptr) { throw "Error: Cannot pop from an empty stack.";}
        E it = this->top->element;
        this->top = this->top->next;
        this->size--;
        return it;
    }

    E topValue() {
        if (this->top == nullptr) { throw "Error: No value at top of stack.";}
        return this->top->element;
    }

    int length() { return this->size; }

    bool validExpression(string str) {
        for (char ch : str) {
            if (ch == '(' || ch == '[') { this->push(ch); }
            else if (ch == ')' || ch == ']') {
                if (this->length() == 0) { return false; }
                if ((ch == ')' && this->topValue() == '(') || (ch == ']' && this->topValue() == '[')) { this->pop(); }
                else { return false; }
            }
        }
        return (this->length() == 0);
    }
};

int main() {
    int qtd_casos;
    cin >> qtd_casos;
    for (int i = 0; i < qtd_casos; i++) {
        string str;
        cin >> str;

        Stack<char> stack;

        if (stack.validExpression(str)) {
            cout << "Yes" << endl;
        } 
        else {
            cout << "No" << endl;
        } 
    }
    return 0;
}