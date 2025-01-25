#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>>arr(rows, vector<int>(cols));
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            cin >> arr[r][c];

    int sum = 0;
    for (int c = 0; c < cols; c++){
        for (int r = 0; r < rows; r++)
            sum += arr[r][c];
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}