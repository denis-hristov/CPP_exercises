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

    vector<string>names;
    while (n--) {
        string name;
        getline(cin >> ws, name);

        if (find(names.begin(), names.end(), name) == names.end())
            names.push_back(name);
    }
    for (auto i : names)
        cout << i << endl;
    return 0;
}