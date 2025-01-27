#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>

using namespace std;

void reading(istream & input, vector<vector<char>> & arr, int & rows, int & cols, string & word) {
    input >> rows >> cols >> ws;
    arr.resize(rows, vector<char>(cols));
    getline(input, word);
    int i = word.size(), n = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++, n++) {
            arr[r][c] = word[n];
            if (n >= i-1)n = -1;
        }
        r++;
        if (r >= rows) 
            break;
        for (int c = cols - 1; c >= 0; c--, n++) {
            arr[r][c] = word[n];
            if (n >= i-1)n = -1;
        }
    }
}

void print(ostream& output, vector<vector<char>> arr, int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++)
            output << arr[r][c];
        output << endl;
    }
}

int main() {
    vector <vector<char>>arr;
    int rows, cols;
    string word;

    reading(cin, arr, rows, cols, word);

    print(cout, arr, rows, cols);

    return 0;
}