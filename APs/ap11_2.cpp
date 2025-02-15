#include <iostream>

using namespace std;

template <typename List>
class Dict {
private:
    int m;
    int cnt;
    List* H;
public:
    Dict(int size) {
        this->m = size;
        this->cnt = 0;
        this->H = new List[size];
        for (int i = 0; i < size; i++) {
            this->H[i] = new List[];
        }
    }

    void insert() {
        
    }
};

int main() {
    

    return 0;
}