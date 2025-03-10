#include <iostream>
#include <string>

using namespace std;

string edinici(unsigned a) {
    switch(a) {
        case 1:return "one";             
        case 2:return "two";             
        case 3:return "three";
        case 4:return "four";
        case 5:return "five";
        case 6:return "six";             
        case 7:return "seven";
        case 8:return "eight";
        case 9:return "nine";
        default: return "Error!";
    }
}

string desetici(unsigned a) {
    switch (a) {
    case 10:return "ten";
    case 11:return "eleven";
    case 12:return "twoelve";
    case 13:return "thirteen";
    case 14:return "fourteen";
    case 15:return "fifteen";
    case 16:return "sixteen";
    case 17:return "seventeen";
    case 18:return "eighteen";
    case 19:return "nineteen";
    case 2:return "twenty";
    case 3:return "thirty";
    case 4:return "forty";
    case 5:return "fifty";
    case 6:return "sixty";
    case 7:return "seventy";
    case 8:return "eighty";
    case 9:return "ninety";
    default: return "Error!";
    }
}
int main()
{
    int a;
    cin >> a;
    if (a == 0)cout << "zero";

    unsigned a1 = a % 10;
    unsigned a2 = (a / 10) % 10;
    if (a2 == 1) {
        a2 = a % 100;
        a1 = 0;
    }
    unsigned a3 = (a / 100) % 10;
    unsigned a4 = (a / 1000);

    string duma;
    if (a4) {
        duma += edinici(a4);
        duma += " thousand";
    }
    if (a3) {
        if (duma.size() > 0)duma += " ";
        duma += edinici(a3);
        duma += " hundred";
    }
    if (a2) {
        if (duma.size() > 0)duma += " ";
        duma += desetici(a2);
    }
    if (a1) {
        if (duma.size() > 0)duma += " ";
        duma += edinici(a1);
    }
    cout << duma;
    return 0;
}