#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Dict {
private:
    int m, cnt;
    pair<int, string> **hash_table;
    int *perm;

    //0 = vazio
    //1 = ocupado
    //2 = deletado
public:
    Dict(int size, int *p) { 
        this->m = size;
        this->cnt = 0; 
        this->perm = p; 
        this->hash_table = new pair<int, string>*[size];
        for (int i = 0; i < size; i++) {
            this->hash_table[i] = nullptr; 
        }
    }

    ~Dict() {
        for (int i = 0; i < this->m; i++) {
            if (this->hash_table[i] != nullptr) {
                delete this->hash_table[i];
            }
        }
        delete[] this->hash_table;
    }

    int h(string e) {
        int sum = 0;
        for (size_t i = 0; i < e.length(); i++) {
            sum += int(e[i]) * (i + 1);
        }
        sum *= 19;
        return abs(sum) % this->m;
    }

    int find(string e) {
        int pos = this->h(e);
    
        if (this->hash_table[pos] != nullptr && this->hash_table[pos]->second == e) {
            return pos;
        } else {
            for (int i = 0; i < 19; i++) {
                int offset = this->perm[i];
                pos = abs(pos + offset) % this->m;
    
                if (this->hash_table[pos] != nullptr && this->hash_table[pos]->second == e) {
                    return pos;
                }
            }
            return -1;
        }
    }
    
    void add(string e) {        
        if (this->m <= this->cnt || this->find(e) != -1) { 
            return; 
        } else {        
            int pos = this->h(e);
            if (this->hash_table[pos] == nullptr || this->hash_table[pos]->first != 1) {
                this->hash_table[pos] = new pair<int, string>(1, e);
                this->cnt++;
            } else {
                for (int i = 0; i < 19; i++) {
                    int offset = this->perm[i];
                    pos = abs(pos + offset) % this->m;
    
                    if (this->hash_table[pos] == nullptr || this->hash_table[pos]->first != 1) {
                        this->hash_table[pos] = new pair<int, string>(1, e);
                        this->cnt++;
                        break;
                    }
                }
            }
        }
    }    
    
    void del(string e) {
        int pos = this->find(e);
    
        if (pos != -1) {
            this->hash_table[pos]->first = 2;
            this->hash_table[pos]->second = "";
            this->cnt--;
        }
    }
    
    void print() {
        cout << this->cnt << endl;
        for (int i = 0; i < this->m; i++) {
            if (this->hash_table[i] != nullptr && this->hash_table[i]->first == 1) {
                cout << i << ":" << this->hash_table[i]->second << endl;
            }
        }
    }
};

int *probing() {
    int *perm = new int[19];
    int resultado;

    for (int i = 1; i < 20; i++) {
        resultado = ((i * i) + (23 * i));
        perm[i - 1] = resultado;
    }

    return perm;
}

int main() {
    int *perm = probing();

    string command, op, element;
    int cases, qtd_operations;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        Dict* dict = new Dict(101, perm);
        cin >> qtd_operations;

        for (int j = 0; j < qtd_operations; j++) {
            cin >> op;
            command = op.substr(0, 3);
            element = op.substr(4);

            if (command == "ADD") {
                dict->add(element);
            } else if (command == "DEL") {
                dict->del(element);
            }
        }

        dict->print();
        delete dict; 
    }

    delete[] perm;
    return 0;
}