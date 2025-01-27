#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void reading(istream & input, int arr[10][10], int & rows, int & cols) {
    input >> rows >> ws;
    for (int r = 0; r < rows; r++) {
        string colsinput;
        getline(input, colsinput);
        istringstream colsStream(colsinput);

        cols = 0;
        int n;
        while (colsStream >> n)
            arr[r][cols++] = n;
    }
}

bool result(int arr1[10][10], int arr2[10][10],
            int rows1, int cols1, int rows2, int cols2) {
    if (rows1 != rows2 || cols1 != cols2)
        return false;

    for(int r=0;r<rows1;r++)
        for(int c=0;c<cols1;c++)
            if (arr1[r][c] != arr2[r][c])
                return false;
    return true;
}

int main() {
    int arr1[10][10], arr2[10][10];
    int rows1, cols1, rows2, cols2;

    reading(cin, arr1, rows1, cols1);
    reading(cin, arr2, rows2, cols2);

    if(result(arr1, arr2,
    rows1, cols1, rows2, cols2))
        cout << "equal\n";
    else cout << "not equal\n";
    return 0;
}