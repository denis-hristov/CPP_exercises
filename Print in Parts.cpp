#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;
    int** matrix = new int* [rows];

    for (int curRow = 0; curRow < rows; curRow++) {
        matrix[curRow] = new int[cols];
        for (int curCol = 0; curCol < cols; curCol++)
            cin >> matrix[curRow][curCol];
    }

    int resRow, resCol;
    cin >> resRow >> resCol;

    for (int curRow = 0; curRow < resRow; curRow++) {
        for (int curCol = 0; curCol < resCol; curCol++)
            cout << matrix[curRow][curCol] << ' ';
        cout << endl;
    }

    for (int curRow = 0; curRow < rows; curRow++)
        delete[]matrix[curRow];
    delete[]matrix;
    return 0;
}