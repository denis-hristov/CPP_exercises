#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n >> ws;
    vector<vector<char>>arr(n, vector<char>(n));
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            cin >> arr[r][c] >> ws;

    char surch;
    cin >> surch;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            if (surch == arr[r][c]) {
                cout << '(' << r << ", " << c << ')' << endl;
                return 0;
            }
    cout << surch << " does not occur in the matrix";
    return 0;
}