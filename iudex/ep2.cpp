#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Dict {
private:
    int m;
    int cnt;
    vector<pair<int, string>>* hash_table;
public:
    Dict(int size) {
        this->m = size;
        this->cnt = 0;
        this->hash_table = new vector<pair<int, string>>[size];
    }

    ~Dict() { delete[] this->hash_table; }

    int h(int key) { return key%10; }

    bool find(const int &key) {
        int pos = this->h(key);
        for (auto it = this->hash_table[pos].begin(); it != this->hash_table[pos].end(); ++it) {
            if (it->first == key) {
                return true;
            }
        }
        return false;
    }

    void add(int key, string element) {
        if (!find(key)) {
            int pos = this->h(key);
            this->hash_table[pos].push_back(make_pair(key, element));
            this->cnt++;
        }
    }

    void del(int key) {
            int pos = this->h(key);
            for (auto it = this->hash_table[pos].begin(); it != this->hash_table[pos].end(); ++it) {
                if (it->first == key) {
                    this->hash_table[pos].erase(it);
                    this->cnt--;
                    break;
                }
            }
        }

    void print() {
        cout << "alpha = " << this->cnt << "/" << 10 << endl;
        for (int i = 0; i < this->m; i++) {
            int sizeHash = this->hash_table[i].size();
            cout << i << ":";
            for (pair<int, string> e : this->hash_table[i]) {
                sizeHash--;
                cout << "(" << e.first << "," << e.second << ")"; 
                if (sizeHash > 0) {
                    cout << ",";
                }
            }
            cout << endl;
        }
    }
};
 
int main() {
    int qtd_casos;
    cin >> qtd_casos;
    for (int i = 0; i < qtd_casos; i++) {
        Dict dict(10);
        int qtd_op;
        cin >> qtd_op;
        for (int j = 0; j < qtd_op; j++) {
            string op;
            int key;
            cin >> op >> key;
            if (op == "add") {
                string element;
                cin >> element;  
                dict.add(key, element);  
            }
            else if (op == "del") {
                dict.del(key);
            }
        }
        cout << "caso " << i+1 << ":" << endl;
        dict.print();
    }
    return 0;
}