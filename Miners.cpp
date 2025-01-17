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
    map<string, int> data;
    vector<string>order;
    while (true) {
        string resource;
        getline(cin >> ws, resource);
        if (resource == "stop")break;

        int quantity;
        cin >> quantity;

        pair<map<string, int>::iterator, bool> insertResource = data.insert({ resource, quantity });

        if(insertResource.second==true)
            order.push_back(resource);
        else
            insertResource.first->second += quantity;
    }
    for (auto i : order) {
        cout << i << " -> " << data[i] << endl;
    }
    return 0;
}