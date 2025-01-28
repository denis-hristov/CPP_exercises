#include <iostream>
#include <string>

using namespace std;

bool cikle(const string& numberID, int & number) {
    for (char index : numberID) {
        if (!isdigit(index))
            return false;
    }
    number = stoi(numberID);
    return true;
}

bool valid(const string& numberID1, int& number1, const string& numberID2, int& number2) {
    bool checker1 = cikle(numberID1, number1);
    bool checker2 = cikle(numberID2, number2);

    if (!checker1 && !checker2) {
        cout << "[error] " << numberID1 << endl;
        cout << "[error] " << numberID2 << endl;
        return false;
    }
    else if (!checker1) {
        cout << "[error] " << numberID1 << endl;
        if (checker2) {
            cout << number2 << endl;
            return false;
        }
    }
    else if (!checker2) {
        cout << number1 << endl;
        cout << "[error] " << numberID2 << endl;
        return false;
    }
    return true;
}

    int main() {
    string numberID1, numberID2;
    cin >> numberID1 >> numberID2;

    int number1;
    int number2;
    
    if(valid(numberID1, number1, numberID2, number2)){
        int sum = number1 + number2;
        cout << sum;
    }
    return 0;
}