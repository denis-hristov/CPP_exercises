#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    vector<int>numbers;
    string data;
    getline(cin, data);
    istringstream input(data);
    string i;
    while (input >> i)
        if(stoi(i)>=0)
            numbers.push_back(stoi(i));

    int last = numbers.size()-1;
    if (numbers.size() == 0)
        cout <<  "empty";
    else
        while (last>=0) {
            cout << numbers[last] << ' ';
            last--;
        }
    return 0;
}