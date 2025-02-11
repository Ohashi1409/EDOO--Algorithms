#include <iostream>

using namespace std;

template <typename E>
class Node {
public:
    E len_car;
    Node* next;
    string side;

    Node(E it, string side, Node* nextVal = nullptr) {
        this->len_car = it;
        this->side = side;
        this->next = nextVal;
    } 
};

template <typename E>
class Queue {
private:
    Node<E>* front;
    Node<E>* rear;
    int size;
    string side;

public:
    Queue() {
        this->front = this->rear = nullptr;
        this->side = "left";
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

    void enqueue(E it, string side) {
        Node<E>* newNode = new Node<E>(it, side, nullptr);
        if (this->rear == nullptr) {
            this->front = this->rear = newNode;
        } else {
            this->rear = this->rear->next = newNode;
        }
        this->size++;
    }

    void dequeue() {
        if (this->size == 0) { throw "Empty queue"; }
        Node<E>* temp = this->front;
        this->front = this->front->next;
        if (this->front == nullptr) { this->rear = this->front; }
        delete temp;
        this->size--;
    }

    E frontLenCar() {
        if (this->size == 0) { throw "Empty queue"; }
        return this->front->len_car;
    }

    string frontSide() {
        if (this->size == 0) { throw "Empty queue"; }
        return this->front->side;
    }

    int length() { return this->size; }

    int transportation(int len_ferry, int qtd_cars) {
        len_ferry *= 100;

        for (int j = 0; j < qtd_cars; j++) {
            int len_car;
            string side;
            cin >> len_car >> side;
            if (len_ferry >= len_car) { this->enqueue(len_car, side); } 
        }

        int crossings = 0, combined_len_cars = 0;
        while (this->length() > 0) {
            if (this->side != this->frontSide()) {
                crossings++;
                this->side = (this->side == "left") ? "right" : "left";
                combined_len_cars = 0;
            }
            else if (len_ferry >= combined_len_cars + this->frontLenCar()) {
                combined_len_cars += this->frontLenCar();
                this->dequeue();
                if (this->length() == 0) { crossings++; }
            }
            else {
                crossings++;
                this->side = (this->side == "left") ? "right" : "left";
                combined_len_cars = 0;
            }
        }
        return crossings;
    }
};

int main() {
    int qtd_casos;
    cin >> qtd_casos;
    for (int i = 0; i < qtd_casos; i++) {
        Queue<int> queue;
        int len_ferry, qtd_cars;
        cin >> len_ferry >> qtd_cars;
        cout << queue.transportation(len_ferry, qtd_cars);
        if (i != qtd_casos - 1) { cout << endl; }
    }
    return 0;
}