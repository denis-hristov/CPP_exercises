#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double a, b, c, D, x1, x2;
    cin >> a >> b>>c;
    D = b * b - 4 * a * c;
    if (D < 0)cout << "no roots";
    else if (D == 0) {
        x1 = -b / (2*a);
        cout << x1;
    }
    else {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        cout << x1 << ' ' << x2;
    }
    return 0;
}
