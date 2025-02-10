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
class List {
public:
    virtual ~List() {}
    virtual void clear() = 0;
    virtual void insert(E item) = 0;
    virtual void append(E item) = 0;
    virtual E remove() = 0;
    virtual void moveToStart() = 0;
    virtual void moveToEnd() = 0;
    virtual void prev() = 0;
    virtual void next() = 0;
    virtual int length() = 0;
    virtual int currPos() = 0;
    virtual void moveToPos(int pos) = 0;
    virtual E getValue() = 0;
    virtual int count(E item) = 0;
};

template <typename E>
class linkedList : public List<E> {
private:
    Node<E>* head;
    Node<E>* tail;
    Node<E>* curr;
    int cnt;

public:
    linkedList() {
        this->curr = this->tail = this->head = new Node<E>(nullptr);
        this->cnt = 0;
    }

    ~linkedList() {
        clear();
        delete this->head;
    }

    void clear() {
        while (this->head != nullptr) {
            Node<E>* temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
        this->curr = this->tail = this->head = new Node<E>(nullptr);
        this->cnt = 0;
    }

    void insert(E item) {
        this->curr->next = new Node<E>(item, this->curr->next);
        if (this->tail == this->curr) { this->tail = this->curr->next; }
        this->cnt++;
    }

    void append(E item) {
        this->tail = this->tail->next = new Node<E>(item, nullptr);
        this->cnt++;
    }

    void moveToStart() { this->curr = this->head; }
    void moveToEnd() { this->curr = this->tail; }

    void prev() {
        if (this->curr == this->head) return;
        Node<E>* temp = this->head;
        while (temp->next != this->curr) { temp = temp->next; }
        this->curr = temp;
    }

    void next() {
        if (this->curr != this->tail) { this->curr = this->curr->next; } 
    }

    int length() { return this->cnt; }

    int currPos() {
        Node<E>* temp = this->head;
        int i;
        for (i = 0; this->curr != temp; i++) { temp = temp->next; }
        return i;
    }

    void moveToPos(int pos) {
        if (pos < 0 || pos > this->cnt) return;
        this->curr = this->head;
        for (int i = 0; i < pos; i++) { this->curr = this->curr->next; }
    }

    E remove() {
        if (this->curr->next == nullptr) {
            throw "Error: Cannot remove element from an empty list.";
        }
        E it = this->curr->next->element;
        if (this->tail == this->curr->next) { this->tail = this->curr; }
        Node<E>* temp = this->curr->next;
        this->curr->next = this->curr->next->next;
        this->cnt--;
        delete temp;
        return it;
    }

    E getValue() {
        if (this->curr->next == nullptr) throw "Error: No value at current position.";
        return this->curr->next->element;
    }

    int count(E item) {
        int counter = 0;
        Node<E>* temp = this->head->next;
        while (temp != nullptr) {
            if (temp->element == item) counter++;
            temp = temp->next;
        }
        return counter;
    }
};

int main() {
    List<int>* list = new linkedList<int>();

    int qtd_casos;
    cin >> qtd_casos;

    for (int i = 0; i < qtd_casos; i++) {
        int qtd_operations;
        cin >> qtd_operations;
        for (int j = 0; j < qtd_operations; j++) {
            string op;
            cin >> op;

            if (op == "insert") {
                int element;
                cin >> element;
                list->insert(element);
            } 
            else if (op == "count") {
                int element;
                cin >> element;
                cout << list->count(element) << endl;
            } 
            else if (op == "next") {
                list->next();
            } 
            else if (op == "prev") {
                list->prev();
            } 
            else if (op == "remove") {
                try {
                    list->remove();
                } catch (const char* msg) {
                    cout << msg << endl;
                }
            }
        }
    }

    delete list;
    return 0;
}
