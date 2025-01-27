#include <iostream>
#include <vector>
#include <sstream>
#include <string>

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

void finder(int i, vector<vector<int>>arr, int rows, int cols) {
    int colnter = 0;
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            if (arr[r][c] == i) {
                colnter++;
                cout << r << ' ' << c << endl;
            }
    if (colnter == 0)
        cout << "not found";
}

int main() {
    vector <vector<int>>arr;
    int rows, cols;
        reading(cin, arr, rows, cols);

    int number;
    cin >> number;
    finder(number, arr, rows, cols);
    return 0;
}