#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

class Matrix {
    int x, y;
public:
    Matrix(int x1, int y1){
        x = x1;
        y = y1;
    }
  
    double distance(int x2, int y2) {
        double p2 = pow(x - x2, 2) + pow(y - y2, 2);
        return sqrt(p2);
    }

};

int main() {
    int x, y;

    cin >> x >> y;
    Matrix one(x, y);

    cout << fixed << setprecision(3);
    cin >> x >> y;
    cout << one.distance(x, y);
    return 0;
}
