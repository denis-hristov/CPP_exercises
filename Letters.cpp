#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

void printMaching(set<string>orderedWords, char search) {
    bool noMaching = true;
    for (string word : orderedWords) {
        string lower = word;
        transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
        if (lower.find(search) != string::npos) {
            noMaching = false;
            cout << word << ' ';
        }
    }
    if(!noMaching) cout << endl;
    else cout << "---" << endl;
}

void erasePunct(string & input) {
    for (char& c : input)
        if (ispunct(c))
            c = ' ';
}

int main() {
    set<string>orderedWords;

    string input;
    getline(cin, input);

    erasePunct(input);

    istringstream data(input);
    while (data >> input) {
        orderedWords.insert(input);
    }

    while (true) {
        char search;
        cin >> search;
        if (search == '.')break;

        search = ::tolower(search);

        printMaching(orderedWords, search);
    }
    return 0;
}