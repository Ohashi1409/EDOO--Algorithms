#include <iostream>
#include <string>
#include <list>

using namespace std;

class Dict {
private:
    int len;
    list<int> *H;
public:
    Dict(int size) {
        this->len = size;
        this->H = new list<int>[size];
    }

    int h(int element) { return (element%10); }

    bool find(int element) {
        int pos = this->h(element);
        for (int num : this->H[pos]) {
           if (num == element) { return true; }
        }
        return false;
    }

    void insert(int element) {
        if (!find(element)) {
            int pos = this->h(element);
            this->H[pos].push_back(element);
        }
    }

    void print() {
        for (int i = 0; i < this->len; i++) {
            cout << i << " ";
            for (int value : this->H[i]) {
                cout << value << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int qtd_num;
    cin >> qtd_num;
    Dict dict(10);
    for (int i = 0; i < qtd_num; i++) {
        int num;
        cin >> num;
        dict.insert(num);
    }

    dict.print();

    return 0;
}