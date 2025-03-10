#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

void stovec(string a, vector<string>& b) {
    istringstream iss(a);
    string word;
    b.clear();
    while (iss >> word) b.push_back(word);
}

void print(const vector<string>& a) {
    cout << '|';
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] != "empty") cout << a[i] << '|';
        else cout << " |";
    }
    cout << endl;
}

void move(vector<string>& a, const vector<string>& b) {
    int oldP = stoi(b[1]) - 1;
    int newP = stoi(b[2]) - 1;
    string c = a[oldP];
    a.erase(a.begin() + oldP);
    a.insert(a.begin() + newP, c);
}

void leave(vector<string>& a, const vector<string>& b) {
    int left = stoi(b[1]) - 1;
    a.erase(a.begin() + left);
}

int main() {
    vector<string> wagones;
    string input;
    while (getline(cin, input) && input != "end") {
        wagones.push_back(input);
    }

    string command;
    vector<string> b;

    while (getline(cin, command) && command != "E") {
        stovec(command, b);
        if (command[0] == 'P') {
            print(wagones);
        }
        else if (command[0] == 'M') {
            move(wagones, b);
            print(wagones);
        }
        else if (command[0] == 'L') {
            leave(wagones, b);
            print(wagones);
        }
        else if (command[0] == 'E') {
            break;
        }
    }
    return 0;
}