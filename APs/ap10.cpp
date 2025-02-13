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

    int pop(int num) {
        int sum = 0;
        for (int i = 0; i < num; i++) {
            if (this->top == nullptr) { throw "Empty stack - Cannot pop";}
            E it = this->top->element;
            this->top = this->top->next;
            this->size--;
            sum += it;
        }
        return sum;
    }

    E topValue() {
        if (this->top == nullptr) { throw "Empty stack - No value at the top";}
        return this->top->element;
    }

    int length() { return this->size; }
};

int main() {
    int qtd_casos;
    cin >> qtd_casos;
    for (int i = 0; i < qtd_casos; i++) {
        Stack<int> pilha;
        string command = "";
        int num = 0;

        cout << "Caso " << i+1 << ":" << endl;

        while (command != "end") {
            cin >> command >> num;
            if (command == "push") {
                pilha.push(num);
            }
            else if (command == "pop") {
                cout << pilha.pop(num) << endl;
            }
        }        
    }
    return 0;
}