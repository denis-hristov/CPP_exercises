#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

int main() {
    vector<int>numbers;
    string data;
    getline(cin, data);
    istringstream input(data);
    string i;
    while (input >> i)
        numbers.push_back(stoi(i));

    int first = 0, last = numbers.size()-1;
    while (first <= last) {
        if (first == last) {
            cout << numbers[first];
            break;
        }
        cout << numbers[first] + numbers[last] << ' ';
        first++;
        last--;
    }

    return 0;
}