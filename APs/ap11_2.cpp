#include <iostream>
#include <list>
#include <string>

using namespace std;

class Dict{
private:
    int m;
    int cnt;
    pair<string, bool> **hash_table;
public:
    Dict(int size) {
        this->m = size;
        this->cnt = 0;
        this->hash_table = new pair<string, bool>*[size];

        for(int i = 0; i<size; i++){
            this->hash_table[i]->first = nullptr;
            this->hash_table[i]->second = false;
        }
    }

    int h(string e){   
        int sum = 0;
        for (int i = 0; i < e.length(); i++) { sum += e[i]; }
        return (abs(sum)%this->m);
    }

    int find(string element) {
        int pos = this->h(element);
        while (!this->hash_table[pos]->first.empty()) {
            if ((this->hash_table[pos]->first == element) && (!this->hash_table[pos]->second)) {
                return pos;
            }
            pos = (pos+1)%this->m;
        }
        return -1;
    }

    void insert(string element) {
        if ((this->cnt < this->m) && !find(element)) {
            int pos = this->h(element);
            if (this->hash_table[pos]->first != "" && !this->hash_table[pos]->second) {
                do {
                    pos = (pos+1)%this->m;
                } while (this->hash_table[pos]->first != "" && !this->hash_table[pos]->second);
            }
            this->hash_table[pos] = new pair<string, bool>(element, false);
            this->cnt++;
        }
    }

    void remove(string element) {
        if (find(element) != -1) {
            int pos = this->h(element);
            while (!this->hash_table[pos]->first.empty()) {
                if ((this->hash_table[pos]->first == element) && (!this->hash_table[pos]->second)) {
                    this->hash_table[pos]->second = true;
                    this->cnt--;
                }
                pos = (pos+1)%this->m;
            }
        }
    }
};

int main() {
    int lenHash;
    cin >> lenHash;

    Dict dict(lenHash);

    string op, str;
    while (cin >> op && op != "fim") {
        cin >> str;
        if (op == "add") {
            dict.insert(str);
        }
        else if (op == "rmv") {
            dict.remove(str);
        }
        else if (op == "sch") {
            cout << str << " " << dict.find(str) << endl;
        }
    }

    return 0;
}