#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<pair<string, int>>data;
    string name;
    int id;
    while (true) {
        cin >> name;
        if (name == "end")break;
        cin >> id;
        data.push_back({ name, id });
    }
    sort(data.begin(), data.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
        });
    for (int i = data.size() - 1; i >= 0; i--) {
        cout << data[i].first << " " << data[i].second << endl;
    }
    return 0;
}