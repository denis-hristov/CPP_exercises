#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>>arr(n, vector<int>(n));
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            cin >> arr[r][c];

    int sum1 = 0, sum2 = 0;
    for (int c = 0; c < n; c++){
        sum1 += arr[c][c];
        sum2 += arr[c][n - 1 - c];
    }
    cout << abs(sum1-sum2) << endl;
    return 0;
}