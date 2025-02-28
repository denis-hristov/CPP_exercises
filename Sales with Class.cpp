#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <iomanip>

using namespace std;

class CitySales {
    map<string, double>data;
public:
    CitySales(istream & input){
        int n;
        input >> n;
        for (int i = 0; i < n; i++) {
            string city, product;
            double price, quantity;

            input >> city >> product >> price >> quantity;
            data[city] += price * quantity;
        }
    }
  
    void print() {
        for (const auto & i : data) {
            cout << fixed << setprecision(2);
            cout << i.first << " -> " << i.second << endl;
        }
    }

};

int main() {
    CitySales sales(cin);
    sales.print();
    
    return 0;
}
