#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

class Dict {
private:
    struct Entry {
        int key;
        int value;
        bool occupied;
    };

    int len;
    vector<int> perm;
    vector<Entry> hash_table;

    int h(int key) {
        return key - (this->len * static_cast<int>(floor(static_cast<double>(key) / this->len)));
    }

public:
    Dict(int size) : len(size), hash_table(size, {-1, -1, false}) {}

    void probing() {
        this->perm.resize(this->len - 1);
        for (int i = 0; i < this->len - 1; i++) {
            cin >> this->perm[i];
        }
    }

    void add(int key, int value) {
        int pos = h(key);
        if (!this->hash_table[pos].occupied) {
            this->hash_table[pos] = {key, value, true};
            return;
        }
        
        if (this->hash_table[pos].key == key) return;

        for (int i = 0; i < this->perm.size(); i++) {
            int newPos = (pos + this->perm[i]) % this->len;
            if (!this->hash_table[newPos].occupied) {
                this->hash_table[newPos] = {key, value, true};
                return;
            }
            if (this->hash_table[newPos].key == key) return;
        }
    }

    void find(int key) {
        int pos = h(key);
        if (this->hash_table[pos].occupied && this->hash_table[pos].key == key) {
            cout << pos << " " << this->hash_table[pos].value << endl;
            return;
        }

        for (int i = 0; i < this->perm.size(); i++) {
            int newPos = (pos + this->perm[i]) % len;
            if (this->hash_table[newPos].occupied && this->hash_table[newPos].key == key) {
                cout << newPos << " " << this->hash_table[newPos].value << endl;
                return;
            }
        }
        cout << "-1" << endl;
    }
};

int main() {
    int perm_len = -1;
    while (cin >> perm_len && perm_len != 0) {
        if (perm_len == 1) continue;

        Dict dict(perm_len);
        dict.probing();

        int qtd_op;
        cin >> qtd_op;

        for (int i = 0; i < qtd_op; i++) {
            string op;
            int key;
            cin >> op >> key;
            if (op == "add") {
                int element;
                cin >> element;
                dict.add(key, element);
            } else if (op == "find") {
                dict.find(key);
            }
        }
    }

    return 0;
}