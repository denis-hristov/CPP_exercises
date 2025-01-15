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

    map<string, map<string, set<string>>>world;
    while (n--) {
        string continent, country, city;
        cin>>continent>>country>>city;

        world[continent][country].insert(city);
    }

    for (auto i = world.begin(); i != world.end(); i++) {
        cout << i->first << ":\n";
        for (auto p = i->second.begin(); p != i->second.end(); p++) {
            cout << "  " << p->first << " -> ";
            bool comas = true;
            for (auto y = p->second.begin(); y != p->second.end(); y++) {
                if (!comas)
                    cout << ", ";
                else
                    comas = false;
                cout << *y;
            }
            cout << endl;
        }
    }
    return 0;
}