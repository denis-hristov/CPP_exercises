#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <stack>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, vector<double>>greatsData;
    while (n--) {
        string student;
        double great;
        cin >> student >> great;

        greatsData[student].push_back(great);
    }

    cout << fixed << setprecision(2);
    for (auto i = greatsData.begin(); i != greatsData.end(); i++) {
        cout << i->first<<" -> ";

        double average = 0;
        for (double p : i->second) {
            cout << p << ' ';
            average += p;
        }

        cout << "(avg: " << average / i->second.size() << ")\n";
    }

    return 0;
}