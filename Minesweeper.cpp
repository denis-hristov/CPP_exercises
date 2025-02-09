#include <iostream>
#include <sstream>

using namespace std;

char** allocatedMatrix(int rows, int cols) {
    char** matrix = new char* [rows];
    for (int row = 0; row < rows; row++)
        matrix[row] = new char[cols];
    return matrix;
}

void deallocateMatrix(char** matrix, int rows) {
    for (int row = 0; row < rows; row++)
        delete[]matrix[row];
    delete[]matrix;
}

char** readMatrix(istream& in, int& rows, int& cols) {
    in >> rows >> cols;
    char** matrix = allocatedMatrix(rows, cols);

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++)
            in >> matrix[r][c];
    }

    return matrix;
}

char** fill(char** matrix, int rows, int cols, char filler) {
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            matrix[r][c] = filler;
    return matrix;
}

void mFixed(char** result, int row, int col, int maxRow, int maxCol) {
    if (row > 0) {
        if (col > 0) result[row-1][col-1]++;
        result[row - 1][col]++;
        if (col < maxCol - 1) result[row - 1][col + 1]++;
    }

    if (col > 0) result[row ][col - 1]++;
    result[row ][col]++;
    if (col < maxCol - 1) result[row][col + 1]++;

    if (row < maxRow - 1) {
        if (col > 0) result[row + 1][col - 1]++;
        result[row + 1][col]++;
        if (col < maxCol - 1) result[row + 1][col + 1]++;
    }
}

char ** process(char** matrix, char** result, int rows, int cols) {
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            if (matrix[r][c] == '!')
                mFixed(result, r, c, rows, cols);
    return result;
}

void print(ostream& out, char** matrix, int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++)
            out << matrix[r][c];
        out << endl;
    }
}

int main() {
    int rows, cols;
    char** matrix = readMatrix(cin, rows, cols);
    char** result = allocatedMatrix(rows, cols);
    fill(result, rows, cols, '0');

    process(matrix, result, rows, cols);

    print(cout, result, rows, cols);

    deallocateMatrix(matrix, rows);
    deallocateMatrix(result, rows);
    return 0;
}