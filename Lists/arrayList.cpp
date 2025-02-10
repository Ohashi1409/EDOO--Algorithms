#include <iostream>
#include <string>

using namespace std;

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
class arrayList : public List<E> {
private:
    int maxSize;
    int listSize;
    int curr;
    E* listArray;

public:
    arrayList(int size) { 
        this->maxSize = size;
        this->listSize = this->curr = 0;
        this->listArray = new E[size];
    }

    ~arrayList() { delete[] this->listArray; }

    void clear() {
        delete[] this->listArray;
        this->listSize = this->curr = 0;
        this->listArray = new E[this->maxSize];
    }

    void insert(E item) {
        if (this->listSize >= this->maxSize) { throw "Error: List is full"; }
        for (int i = this->listSize; i > this->curr; i--) {
            this->listArray[i] = this->listArray[i - 1];
        }
        this->listArray[this->curr] = item;
        this->listSize++;
    }

    void append(E item) {
        if (this->listSize >= this->maxSize) { throw "Error: List is full"; }
        this->listArray[this->listSize] = item;
        this->listSize++;
    }

    void moveToStart() { this->curr = 0; }
    void moveToEnd() { this->curr = this->listSize; }

    void prev() {
        if (this->curr > 0) { this->curr--; }
    }

    void next() {
        if (this->curr < this->listSize) { this->curr++; }
    }

    E remove() {
        if (this->curr < 0 || this->curr >= this->listSize) { throw "Error: No element to remove"; }
        E it = this->listArray[this->curr];
        for (int i = this->curr; i < this->listSize - 1; i++) { this->listArray[i] = this->listArray[i + 1]; }
        this->listSize--;
        return it;
    }

    int length() { return this->listSize; }
    int currPos() { return this->curr; }

    void moveToPos(int pos) {
        if (pos < 0 || pos >= this->listSize) { throw "Error: Invalid position"; }
        this->curr = pos;
    }

    E getValue() {
        if (this->curr < 0 || this->curr >= this->listSize) { throw "Error: Invalid position"; }
        return this->listArray[this->curr];
    }

    int count(E item) {
        int counter = 0;
        for (int i = 0; i < this->listSize; i++) {
            if (this->listArray[i] == item) { counter++; }
        }
        return counter;
    }
};

int main() {
    int tamanhoLista;
    cout << "Primeiro digite o tamanho da lista: ";
    cin >> tamanhoLista;

    List<int>* list = new arrayList<int>(tamanhoLista); 

    int qtd_casos;
    cin >> qtd_casos;

    for (int i = 0; i < qtd_casos; i++) {
        int qtd_operations;
        cin >> qtd_operations;

        cout << "Caso " << i+1 << endl;
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
