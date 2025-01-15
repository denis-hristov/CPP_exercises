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

    map<string, size_t>names;
    while (n--) {
        string name;
        cin >> name;
        names[name]++;
    }

    for (auto i = names.begin(); i != names.end(); i++)
        cout << i->first << endl;
    return 0;
}