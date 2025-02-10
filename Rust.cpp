#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

const char normal = '.';
const char spoil = '!';
const char untouchable = '#';
const char newSpoil = '*';

void spoiling(vector<vector<char>>&square) {
    vector<vector<char>> temp = square;
    for (int r = 0; r < 10; r++)
        for (int c = 0; c < 10; c++)
            if (square[r][c] == spoil) {
                if (r > 0 && temp[r - 1][c] == normal)
                    temp[r - 1][c] = newSpoil;
                if (r < 9 && temp[r + 1][c] == normal)
                    temp[r + 1][c] = newSpoil;
                if (c > 0 && temp[r][c - 1] == normal)
                    temp[r][c - 1] = newSpoil;
                if (c < 9 && temp[r][c + 1] == normal)
                    temp[r][c + 1] = newSpoil;
            }
    for (int r = 0; r < 10; r++)
        for (int c = 0; c < 10; c++)
            if (temp[r][c] == newSpoil)
                temp[r][c] = spoil;
    square = temp;

}

int main() {
    vector<vector<char>>square(10, vector<char>(10));
    for (int r = 0; r < 10; r++)
        for (int c = 0; c < 10; c++)
            cin >> square[r][c] >> ws;
    
    int tick;
    cin >> tick;
    for (int i = 0; i < tick; i++)
        spoiling(square);
    
    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++)
            cout << square[r][c];
        cout << endl;
    }

    return 0;
}