#include <iostream>

using namespace std;

template <typename E>
class Node {
public:
    E len_car;
    Node* next;

    Node(E it, Node* nextVal = nullptr) {
        this->len_car = it;
        this->next = nextVal;
    } 
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
        Node<E>* newNode = new Node<E>(it, nullptr);
        if (this->rear == nullptr) { this->front = this->rear = newNode; } 
        else { this->rear = this->rear->next = newNode; }
        this->size++;
    }

    void dequeue() {
        if (this->size <= 0) { throw "Empty queue"; }
        Node<E>* temp = this->front;
        this->front = this->front->next;
        delete temp;
        this->size--;
    }

    E frontLenCar() {
        if (this->size == 0) { throw "Empty queue"; }
        return this->front->len_car;
    }

    bool empty() { return this->size == 0; }
};

int transportation(int len_ferry, int qtd_cars) {
    Queue<int> Lqueue, Rqueue;
    len_ferry *= 100;

    for (int j = 0; j < qtd_cars; j++) {
        int len_car;
        string side;
        cin >> len_car >> side;
        if (side == "left") { Lqueue.enqueue(len_car); }
        else { Rqueue.enqueue(len_car); }
    }

    int crossings = 0;

    while (!Lqueue.empty() || !Rqueue.empty()) {
        int current_load = 0;
        if (!Lqueue.empty()) {
            while (!Lqueue.empty() && (current_load + Lqueue.frontLenCar() <= len_ferry)) {
                current_load += Lqueue.frontLenCar();
                Lqueue.dequeue();
            }
        } 
        crossings++;

        if (!Lqueue.empty() || !Rqueue.empty()) {
            current_load = 0;
            if (!Rqueue.empty()) {
                while (!Rqueue.empty() && (current_load + Rqueue.frontLenCar() <= len_ferry)) {
                    current_load += Rqueue.frontLenCar();
                    Rqueue.dequeue();
                }
            }
            crossings++;
        }
    }
    
    return crossings;
}

int main() {
    int qtd_casos;
    cin >> qtd_casos;
    for (int i = 0; i < qtd_casos; i++) {
        int len_ferry, qtd_cars;
        cin >> len_ferry >> qtd_cars;
        cout << transportation(len_ferry, qtd_cars) << endl;
    }
    return 0;
}