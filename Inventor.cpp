#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    map<string, double> data;
    int n;
    cin >> n;
    cin.ignore();
    while(data.size()<n) {
        string city;
        double price;
        int quantity;

        getline(cin, city);
        cin >> price >> quantity;
        cin.ignore();

        data[city] += price * quantity;
    }

    for (pair<string,double>i : data) {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
