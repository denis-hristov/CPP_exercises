#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    map<string, string> nameToLocation;
    map<string, vector<string>> coordToNames;
    string line;

    while (getline(cin, line) && line != ".") {
        size_t firstComma = line.find(',');
        size_t secondComma = line.find(',', firstComma + 1);

        string name = line.substr(0, firstComma);
        string latitude = line.substr(firstComma + 1, secondComma - firstComma - 1);
        string longitude = line.substr(secondComma + 1);
        string coordinates = latitude + " " + longitude;

        nameToLocation[name] = line;
        coordToNames[coordinates].push_back(line);
    }

    while (getline(cin, line) && line != ".") {
        if (nameToLocation.count(line)) {
            cout << nameToLocation[line] << endl;
        }
        else if (coordToNames.count(line)) {
            for (const string& entry : coordToNames[line]) {
                cout << entry << endl;
            }
        }
    }

    return 0;
}
