#include <iostream>
#include <string>

using namespace std;

int main() {
    string words;
    getline(cin, words);
    const char* buff = words.c_str();
    size_t buffLen = words.length();

    char* allUpper = new char[buffLen];
    char* allLower = new char[buffLen];
    int i = 0;
    for (; i < buffLen; i++) {
        allLower[i] = ::tolower(buff[i]);
        allUpper[i] = ::toupper(buff[i]);
    }
    allLower[i] = 0;
    allUpper[i] = 0;

    cout << allLower << endl;
    cout << allUpper << endl;

    delete[]allUpper;
    delete[]allLower;
    return 0;
}