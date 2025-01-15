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

void addingNumbers(int a, set<int> &b) {
    while (a--) {
        int i;
        cin >> i;
        b.insert(i);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    set<int>numbers1, numbers2;

    addingNumbers(n, numbers1);
    addingNumbers(m, numbers2);

    bool spase = true;
    for (int i : numbers1)
        for (int t : numbers2)
            if (i == t) {
                if (!spase)
                    cout << ' ';
                else
                    spase = false;
                cout << i;
            }
    return 0;
}