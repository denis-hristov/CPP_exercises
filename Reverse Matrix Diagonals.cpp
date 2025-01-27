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

int main() {
    vector <vector<int>>arr;
    int rows, cols;
        reading(cin, arr, rows, cols);

    for (int i = cols - 1; i >= 0; i--) {
        for (int r = rows - 1, c = i;
            r >= 0 &&  c < cols;
            r--, c++) {
            cout << arr[r][c] << ' ';
        }
        cout << endl;
    }

    for (int i = rows - 2; i >= 0; i--) {
        for (int r = i, c = 0; r >= 0 && c < cols; r--, c++) {
            cout << arr[r][c] << ' ';
        }
        cout << endl;
    }
    return 0;
}