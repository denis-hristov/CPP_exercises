#include <iostream>
#include <string>
#include <deque>

using namespace std;

class Students {
    deque<pair<string, pair<string, double>>> data;
public:
    Students(istream& input) {
        int n;
        input >> n;

        if (n <= 0) {
            cout << "Invalid input" << endl;
            return;
        }

        for (int i = 0; i < n; i++) {
            string name, surname;
            double grade;

            input >> name >> surname >> grade;
            data.emplace_back(name, make_pair(surname, grade));
        }
    }

    void print() {
        if (data.empty()) return;

        double average = 0;
        for (const auto& i : data) {
            cout << i.first << " " << i.second.first
                << " " << i.second.second << endl;
            average += i.second.second;
        }

        cout << average / data.size() << endl;
    }
};

int main() {
    Students classMates(cin);
    classMates.print();
    return 0;
}
