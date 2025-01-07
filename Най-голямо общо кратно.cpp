#include <iostream>
using namespace std;
int main() {
    int a, b, i;
    cin >> a >> b;
    if (a > b)i = b;
    else i = a;
    while (a % i != 0 || b % i != 0) {
        i--;
    }
    cout << i;
    return 0;
}
