#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double pMaznini, pProtein, pVuglehidrati, pVoda;
    int kalorii;
    cin >> pMaznini >> pProtein >> pVuglehidrati >> kalorii >> pVoda;
    double maznini = (kalorii * pMaznini * 0.01) / 9;
    double protein = (kalorii * pProtein * 0.01) / 4;
    double vuglehidrati = (kalorii * pVuglehidrati * 0.01) / 4;
    double grHrana = maznini + proteivugle + vuglehidrati;
    double kaloriiGrHrana = kalorii / grHrana;
    cout << fixed << setprecision(4);
    cout << (kaloriiGrHrana * (100 - pVoda) * 0.01);

    return 0;
}