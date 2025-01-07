#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int a;
    string b;
    cin >> a;
    if (a > 12 || a < 1) {
        b = "Error!";
    }
    else {
        switch (a) {
        case 1: b = "January"; break;
        case 2: b = "February"; break;
        case 3: b = "March"; break;
        case 4: b = "April"; break;
        case 5: b = "May"; break;
        case 6: b = "June"; break;
        case 7: b = "Juky"; break;
        case 8: b = "August"; break;
        case 9: b = "September"; break;
        case 10: b = "October"; break;
        case 11: b = "November"; break;
        case 12: b = "December"; break;
        }
    }
    cout << b;

    return 0;
}