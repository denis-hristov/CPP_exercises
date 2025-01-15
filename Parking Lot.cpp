#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    set<string>carsIn;
    while (true) {
        string InOrOut, car;
        cin >> InOrOut;
        if (InOrOut == "END")
            break;

        cin >> car;
        if(InOrOut=="IN,")
            carsIn.insert(car);
        else
            carsIn.erase(car);
    }
    if (carsIn.size() == 0)
        cout << "Parking Lot is Empty";
    else
        for (string i: carsIn)
        cout << i << endl;
    return 0;
}