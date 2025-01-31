#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool lexicalyFirst(const string& current, const string& result) {
    return current < result;
}

bool shortestWord(const string& current, const string& result) {
    return current.length() < result.length();
}

bool longestWord(const string& current, const string& result) {
    return current.length() > result.length();
}

int main() {
    vector<string>words;

    string sentence;
    getline(cin, sentence);

    istringstream input(sentence);
    while (input >> sentence)
        words.push_back(sentence);

    int function;
    cin >> function;
    
    bool(*func)(const string & current, const string & result);

    switch (function) {
        case 1:
            func = lexicalyFirst;
            break;
        case 2:
            func = shortestWord;
            break;
        case 3:
            func = longestWord;
            break;
    }

    string result = words[0];

    for (size_t i = 1; i < words.size(); i++) {
        if (func(words[i], result))
            result = words[i];
    }

    cout << result << endl;

    return 0;
}