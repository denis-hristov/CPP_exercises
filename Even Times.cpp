#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, size_t>numbers;
    while (n--) {
        int number;
        cin >> number;
        numbers[number]++;
    }

    for(auto i = numbers.begin();i!=numbers.end();i++)
        if (i->second % 2 == 0) {
            cout << i->first;
            break;
        }
    return 0;
}