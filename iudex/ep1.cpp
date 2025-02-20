#include <iostream>

using namespace std;

class Node {
public:
    string element;
    Node* next;

    Node(string it, Node* nextVal = nullptr) {
        this->element = it;
        this->next = nextVal;
    } 
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Queue() {
        this->front = this->rear = new Node("");
        this->size = 0;
    }

    void add(string it) {
        this->rear->next = new Node(it);
        this->rear = this->rear->next;
        size++;
    }

    void addPos(int pos, string it) {
        Node* newNode = new Node(it);
        Node* temp = this->front;
        for (int i = 0; i < pos; ++i) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == nullptr) {
            this->rear = newNode;
        }
        size++;
    }

    void next() {
        if (this->front->next != nullptr) { 
            Node* temp = this->front->next;
            this->front->next = temp->next;
            if (this->front->next == nullptr) {
                this->rear = this->front;
            }
            delete temp;
            size--;
        }
    }

    void status() {
        if (this->front->next == nullptr) {
            cout << "---";
        }
        Node* temp = this->front->next;
        while (temp != nullptr) {
            cout << temp->element;
            if (temp->next != nullptr) {
                cout << ", ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int qtd_casos;
    cin >> qtd_casos;

    for (int i = 1; i <= qtd_casos; i++) {
        cout << "caso " << i << ":" << endl;

        int qtd_op;
        cin >> qtd_op;
        Queue queue;

        for (int j = 0; j < qtd_op; j++) {
            string op;
            cin >> op;

            if (op == "add") {
                string first;
                cin >> first;
                try {
                    int pos = stoi(first);
                    string name;
                    cin >> name;
                    queue.addPos(pos-1, name);
                } catch (const std::invalid_argument&) {
                    queue.add(first);
                }
            } else if (op == "next") {
                queue.next();
            } else if (op == "status") {
                queue.status();
            }
        }
    }
    return 0;
}
