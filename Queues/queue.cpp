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
class adtQueue {
public:
    virtual ~adtQueue() {};
    virtual void clear() = 0;
    virtual void enqueue(E item) = 0;
    virtual E dequeue() = 0;
    virtual E frontValue() = 0;
    virtual int length() = 0;
};

template <typename E>
class Queue {
private:
    Node<E>* front;
    Node<E>* rear;
    int size;

public:
    Queue() {
        this->front = this->rear = nullptr;
        this->size = 0;
    }

    ~Queue() { clear(); }

    void clear() {
        while (this->front != nullptr) {
            Node<E>* temp = this->front;
            this->front = this->front->next;
            delete temp;
        }
        this->rear = nullptr;
        this->size = 0;
    }

    void enqueue(E it) {
        this->rear->next = new Node<E>(it, nullptr);
        this->rear = this->rear->next;
        this->size++;
    }

    E dequeue() {
        if (this->size == 0) { throw "Error: Empty queue."; }
        E it = this->front->next->element;
        this->front->next = this->front->next->next;
        if (this->front->next == nullptr) { this->rear = this->front; }
        this->size--;
        return it;
    }

    E frontValue() {
        if (this->size == 0) { throw "Error: Empty queue."; }
        return this->front->next->element;
    }

    int length() { return this->size; }
};