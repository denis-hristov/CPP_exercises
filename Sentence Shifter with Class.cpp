#include <iostream>
#include <string>
#include <sstream>
#include <deque>

using namespace std;

class WordDeque {
    deque<string>words;

public:
    WordDeque(const string & data){
        istringstream input(data);
        string word;
        while (input >> word)
            words.push_back(word);
    }

    void rotateWords(int n) {
        for (int i = 0; i < n; i++) {
            string word = words.back();
            words.push_front(word);
            words.pop_back();
        }
    }

    void printWords()const {
        for(int i=0;i<words.size();i++)
            cout << words[i] << endl;
    }

};

int main() {
    string data;
    getline(cin, data);

    WordDeque sentence(data);

    int n;
    cin >> n;
    sentence.rotateWords(n);
    sentence.printWords();
    return 0;
}
