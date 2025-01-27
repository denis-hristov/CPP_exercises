#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void reading(istream & input, vector<vector<char>> & arr, int & rows, int & cols) {
    input >> rows >> cols >> ws;
    arr.resize(rows, vector<char>(cols));

    for (int r = 0; r < rows; r++) {
        string colsinput;
        getline(input, colsinput);
        istringstream colsStream(colsinput);

        for (int c = 0; c < cols && colsStream; c++)
            colsStream >> arr[r][c];
    }
}

void finder(vector<vector<char>>arr, int rows, int cols) {
    int colnter = 0;
    for (int r = 0; r < rows-1; r++)
        for (int c = 0; c < cols-1; c++)
            if (arr[r][c] == arr[r][c+1] &&
                arr[r][c] == arr[r+1][c] &&
                arr[r][c] == arr[r+1][c+1])
                colnter++;
    cout << colnter;
}

int main() {
    vector <vector<char>>arr;
    int rows, cols;
        reading(cin, arr, rows, cols);

    finder(arr, rows, cols);
    return 0;
}