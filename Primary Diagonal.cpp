#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>>arr(n, vector<int>(n));
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            cin >> arr[r][c];

    int sum = 0;
    for (int c = 0; c < n; c++)
        sum += arr[c][c];
        cout << sum << endl;
    return 0;
}