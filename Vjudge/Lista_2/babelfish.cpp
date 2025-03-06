#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Dict {
private:
    int m;
    vector<pair<string, string>>* hash_table;
    //Element = Palavra traduzida
    //Key = Palavra no Inglês padrão
public:
    Dict(int size) {
        this->m = size;
        this->hash_table = new vector<pair<string, string>>[size];
    }

    ~Dict() { delete[] this->hash_table; }

    int h(string element) {
        int sum = 0;
        for (size_t i = 0; i < element.length(); i++) {
            sum += int(element[i]) * (i + 1);
        }
        sum *= 7;
        return abs(sum) % this->m;
    }

    string find(string element) {
        int pos = this->h(element);
        for (pair<string, string> e : this->hash_table[pos]) {
            if (e.second == element) {
                return e.first;
            }
        }
        return "eh";
    }

    void add(string key, string element) {
        int pos = this->h(element);
        this->hash_table[pos].push_back(make_pair(key, element));
    }
};
 
int main() {
    string line = "";
    string key, element;
    Dict dict(100);

    while (getline(cin, line) && !line.empty()) {
        int pos = line.find(' ');
        key = line.substr(0, pos);
        element = line.substr(pos+1);

        dict.add(key, element);
    }

    while (cin >> element) {
        cout << dict.find(element) << endl;
    }

    return 0;
}