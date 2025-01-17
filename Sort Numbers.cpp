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
    istringstream wreadingData(numbers);

    set<double>dataCollector;
    double number;
    while (wreadingData >> number)
        dataCollector.insert(number);

    bool arel = true;
    for (auto i = dataCollector.begin(); i != dataCollector.end(); i++) {
        if (arel)arel = false;
        else cout << " <= ";
        cout << *i;
    }
    return 0;
}