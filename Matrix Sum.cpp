#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    int size;
    cin >> size >> ws;
    vector<vector<int>> square(size, vector<int>(size));
    int sum = 0;
    for (int r = 0; r < size; r++)
        for (int c = 0; c < size; c++) {
            cin >> square[r][c];
            if (r != c && r + c != size - 1 && square[r][c] % 2 != 0)
                sum += square[r][c];
        }
    cout << "The sum is: " << sum << endl;
    return 0;
}
