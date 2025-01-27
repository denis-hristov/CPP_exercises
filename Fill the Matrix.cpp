#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>

using namespace std;

void readingB(istream & input, vector<vector<int>> & arr, int size) {
    arr.resize(size, vector<int>(size));
    int n = 1;

    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            arr[c][r] = n++;
        }
        r++;
        if (r >= size) 
            break;
        for (int c = size - 1; c >= 0; c--) {
            arr[c][r] = n++;
        }
    }
}

void readingA(istream& input, vector<vector<int>>& arr, int size) {
    arr.resize(size, vector<int>(size));
    int n = 1;
    for (int r = 0; r < size; r++)
        for (int c = 0; c < size; c++)
            arr[c][r] = n++;
}


void print(ostream& output, vector<vector<int>> arr, int size) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++)
            output << arr[r][c] << ' ';
        output << endl;
    }
}

int main() {
    vector <vector<int>>arr;
    string sizeInput;
    cin >> sizeInput;

    int size = stoi(sizeInput);

    char metod;
    cin >> metod;
    if(metod == 'A') readingA(cin, arr, size);
    else if(metod == 'B') readingB(cin, arr, size);

    print(cout, arr, size);

    return 0;
}