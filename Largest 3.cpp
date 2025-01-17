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


    auto i = dataCollector.rbegin();
    int num = 3;
    while (i != dataCollector.rend() && num != 0) {
        num--;
        cout << *i <<' ';
        i++;
    }
    return 0;
}