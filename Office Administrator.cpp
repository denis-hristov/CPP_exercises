#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    map<string, set<int>> data;
    while (true) {
        string name, room;
        cin >> name;
        if (name == "END") break;
        cin >> room;

        int roomNum = stoi(room);

        if (data.find(name) == data.end()) {
            data[name] = set<int>();
        }
        data[name].insert(roomNum);
    }

    queue<string> output;
    while (true) {
        string whereIs;
        cin >> whereIs;
        if (whereIs == "END") break;

        bool found = false;
        for (const auto& i : data) {
            if (i.first == whereIs) {
                stringstream line;
                line << i.first << ": ";
                for (const int& room : i.second) {
                    line << room << " ";
                }
                output.push(line.str());
                found = true;
                break;
            }
        }
        if (!found) {
            string line = whereIs + ": Not found!";
            output.push(line);
        }
    }

    while (!output.empty()) {
        cout << output.front() << endl;
        output.pop();
    }
    return 0;
}
