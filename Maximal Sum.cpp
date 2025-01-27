#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>

using namespace std;

void reading(istream & input, vector<vector<int>> & arr, int & rows, int & cols) {
    input >> rows >> cols >> ws;
    arr.resize(rows, vector<int>(cols));

    for (int r = 0; r < rows; r++) {
        string colsinput;
        getline(input, colsinput);
        istringstream colsStream(colsinput);

        for (int c = 0; c < cols && colsStream; c++)
            colsStream >> arr[r][c];
    }
}

void finder(vector<vector<int>>arr, int rows, int cols, int & maxSum, int index[2]) {
    int  sum;
    for (int r = 0; r < rows - 2; r++)
        for (int c = 0; c < cols - 2; c++) {
            sum = arr[r][c] + arr[r][c + 1] + arr[r][c + 2] +
                arr[r + 1][c] + arr[r + 1][c + 1] + arr[r + 1][c + 2] +
                arr[r + 2][c] + arr[r + 2][c + 1] + arr[r + 2][c + 2];
            if (maxSum < sum) {
                maxSum = sum;
                index[0] = r;
                index[1] = c;
            }
        }
    cout << "Sum = " << maxSum << endl;
    cout << arr[index[0]][index[1]] << ' ' << arr[index[0]][index[1] + 1] << ' ' << arr[index[0]][index[1] + 2] << endl;
    cout << arr[index[0] + 1][index[1]] << ' ' << arr[index[0] + 1][index[1] + 1] << ' ' << arr[index[0] + 1][index[1] + 2] << endl;
    cout << arr[index[0] + 2][index[1]] << ' ' << arr[index[0] + 2][index[1] + 1] << ' ' << arr[index[0] + 2][index[1] + 2] << endl;
}

int main() {
    vector <vector<int>>arr;
    int rows, cols;
        reading(cin, arr, rows, cols);

        int maxSum = INT_MIN, index[2]{ 0, 0 };
    finder(arr, rows, cols, maxSum, index);
    return 0;
}