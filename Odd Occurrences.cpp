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
    string number;
    while (wreadingData >> number) {
        if (dataCollector.find(number) == dataCollector.end())
            dataCollector.insert(number);
        else
            dataCollector.erase(number);
    }

    istringstream order(numbers);
    bool coma = true;
    while (order>>number) {
        if (dataCollector.find(number) != dataCollector.end()) {
            if (coma)
                coma = false;
            else
                cout << ", ";
            cout << number;
            dataCollector.erase(number);
        }
    }
    return 0;
}