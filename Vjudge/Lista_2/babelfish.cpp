#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Dict{
private:
    int m;
    int cnt;
    pair<string, string> **hash_table;
    vector<bool> *deleted;
public:
    Dict(int size) {
        this->m = size;
        this->cnt = 0;
        this->hash_table = new pair<string, string>*[size];
        this->deleted = new vector<bool>(size, false);
    
        for(int i = 0; i<size; i++){
            this->hash_table[i]->first = "";
            this->hash_table[i]->second = "";
        }
    }

    string h(const string& word) {
        string vowels = "aeiou";
        size_t first_vowel_index = word.find_first_of(vowels); // Encontra a primeira vogal
    
        if (first_vowel_index == string::npos) { return word + "ay"; }
    
        return word.substr(first_vowel_index) + word.substr(0, first_vowel_index) + "ay";
    }

    int find(string element) {
        string key = this->h(element);
        while (this->hash_table->first != "") {
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
    string line;
    while (getline(cin, line)) {
        if (line.empty()) { break; }

        istringstream iss(line);
        string original, translated;
        iss >> original >> translated;

        
    }

    return 0;
}