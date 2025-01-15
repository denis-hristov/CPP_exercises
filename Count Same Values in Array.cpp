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

    vector<double>order;
    map<double, size_t>dataCollector;

    istringstream wreadingData(numbers);
    double number;
    while (wreadingData >> number) {
        dataCollector[number]++;
        if(dataCollector.find(number)->second == 1)
        order.push_back(number);
    }

    int t = 0;
    for (auto i : order) {
        t++;
        double n = dataCollector.find(i)->second;
        cout << i << " - " << n << " times\n";
        if (t == dataCollector.size())break;
    }

    return 0;
}
