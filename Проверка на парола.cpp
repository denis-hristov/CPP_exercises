#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void pas(string a) {
    bool broika = false, izlishno = true, bukvi = false;
    int brB = 0;
    broika = (a.size() > 5 && a.size() < 11);
    for (char i : a) {
        if (!isalnum(i))izlishno = false;
        if (isdigit(i))brB++;
    }
    bukvi = brB >= 2;
    if(!broika)
        cout << "Password must be between 6 and 10 characters\n";
    if (!izlishno)
        cout << "Password must consist only of letters and digits\n";
    if (!bukvi)
        cout << "Password must have at least 2 digits\n";
    if (broika && izlishno && bukvi)
        cout << "Password is valid\n";
}

int main()
{
    string a;
    getline(cin, a);
    pas(a);
    return 0;
}