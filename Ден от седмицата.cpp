#include <iostream>
#include <string>
using namespace std;

int main()
{
    string mas[] = { "Monday","Tuesday","Wednesday",
        "Thursday","Friday","Saturday","Sunday" };
    int den;
    cin >> den;
    if (den > 7 || den < 1)cout << "Invalid day!";
    else cout << mas[den-1];
    return 0;
}