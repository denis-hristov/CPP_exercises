#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    int mesta;
    string film;
    bool stop = true;
    int kid = 0, student = 0, standart = 0;
    int broiVsichko = 0;
    while (stop) {
        int broiBileti = 0;
        getline(cin, film);
        if (film == "Finish") {
            stop = false;
            break;
        }
        cin >> mesta;
        for (int i = 0; i < mesta; i++) {
            string bilet;
            cin >> bilet;
            if (bilet == "End") {
                break;
            } else if (bilet == "kid") {
                kid++;
            } else if (bilet == "student") {
                student++;
            } else if (bilet == "standard") {
                standart++;
            }
            broiBileti++;
            broiVsichko++;
            cin.ignore();
        }
        double procenti=static_cast<double>(broiBileti)
        cout << fixed << setprecision(2);
        cout << film << " - "
            << mesta / broiBileti * 100
            << "% full.\n";
    }
    cout << "Total tickets: " << broiVsichko << endl;
    cout << broiVsichko / student * 100 
        << "% student tickets.\n";
    cout << broiVsichko / standart * 100 
        << "% standard tickets.\n";
    cout << broiVsichko / kid * 100 
        << "% kids tickets.\n";
    return 0;
}