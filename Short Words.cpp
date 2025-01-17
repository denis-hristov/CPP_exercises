#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string numbers;
    getline(cin, numbers);
    transform(numbers.begin(), numbers.end(), numbers.begin(), ::tolower);
    istringstream wreadingData(numbers);

    set<string>dataCollector;
    string word;
    while (wreadingData >> word) {
        if(word.size()<5)
            dataCollector.insert(word);
    }

    bool coma = true;
    for (auto i = dataCollector.begin(); i != dataCollector.end();i++) {
        if (coma)coma = false;
        else cout << ", ";
        cout << *i;
    }
    return 0;
}