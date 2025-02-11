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
class adtStack {
public:
    virtual ~adtStack() {}
    virtual void clear() = 0;
    virtual void push(E item) = 0;
    virtual E pop() = 0;
    virtual E topValue() = 0;
    virtual int length() = 0;
};

template <typename E>
class Stack : public adtStack<E> {
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
};