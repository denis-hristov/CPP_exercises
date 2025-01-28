#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, int>data;
    string name;
    int id;
    while (true) {
        cin >> name >> id;
        if (name == "end")break;
        data.insert({ name, id });
    }
    cin >> id;
    for (auto i = data.begin(); i != data.end(); i++) {
        if (id == i->second)
            cout << i->first << ' ' << i->second << endl;
    }
    return 0;
}