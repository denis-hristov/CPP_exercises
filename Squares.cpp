#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    string numbers;
    getline(cin, numbers);
    istringstream wreadingData(numbers);

    multiset<double>dataCollector;
    double number;
    while (wreadingData >> number) {
        if(trunc(sqrt(number))==sqrt(number))
            dataCollector.insert(number);
    }

    for (auto i = dataCollector.rbegin(); i != dataCollector.rend(); i++) {
        cout << *i << ' ';
    }
    return 0;
}