#include <iostream>
#include <sstream>

using namespace std;

int** allocatedMatrix(int rows, int cols) {
    int** matrix = new int* [rows];
    for (int row = 0; row < rows; row++)
        matrix[row] = new int[cols];
    return matrix;
}

void deallocateMatrix(int** matrix, int rows) {
    for (int row = 0; row < rows; row++)
        delete[]matrix[row];
    delete[]matrix;
}

int** readMatrix(istream& in, int& rows, int& cols) {
    in >> rows >> ws;
    string buffer;
    getline(in, buffer);
    {
        cols = 0;
        int t;
        istringstream colsCounter(buffer);
        while (colsCounter >> t)
            cols++;
    }

    int** matrix = allocatedMatrix(rows, cols);

    for (int curRow = 0;;) {
        istringstream stream(buffer);
        for (int curCol = 0; curCol < cols; curCol++)
            stream >> matrix[curRow][curCol];
        curRow++;
        if (curRow >= rows)
            break;
        getline(in, buffer);
    }
    return matrix;

}

bool compere(int** m1, int m1rows, int m1cols,
    int**m2, int m2rows, int m2cols)
{
    if (m1cols != m2cols || m1rows != m2rows)
        return false;
    for (int curRows = 0; curRows < m1rows; curRows++) {
        for (int curCols = 0; curCols < m1cols; curCols++)
            if (m1[curRows][curCols] != m2[curRows][curCols])
                return false;
    }
    return true;
}

int main() {
    int m1rows, m1cols;
    int** matrix1 = readMatrix(cin, m1rows, m1cols);

    int m2rows, m2cols;
    int** matrix2 = readMatrix(cin, m2rows, m2cols);

    cout << (compere(matrix1, m1rows,m1cols,matrix2,m2rows,m2cols) ? "equal" : "not equal") << endl;

    deallocateMatrix(matrix1, m1rows);
    deallocateMatrix(matrix2, m2rows);
    return 0;
}