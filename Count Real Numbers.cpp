#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string numbers;
    getline(cin, numbers);
    map<double, size_t>dataCollector;

    istringstream wreadingData(numbers);
    double number;
    while (wreadingData >> number)
        dataCollector[number]++;

    for (auto i : dataCollector)
        cout << i.first << " -> " << i.second << endl;
    return 0;
}
