#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Shop
{
public:
    string name;
    Shop();
    ~Shop();

    //Конструктор за популване
    Shop(string item, double priceItem) {
        name = item;
        price = priceItem;
    }

    //Писане на нов артикул
    void printItem() {
        cout << name << '\t' << price << "lv.\n";
    }

    //Извеждане на цената
    int getPrice() {
        return price;
    }

private:
    double price;
};

Shop::Shop(){
    name = "None";
    price = 0;
}

Shop::~Shop(){}

int main()
{
    //Записване на нови артикули във вектор
    vector <Shop*> list;
    string itemNew;
    double priceNew;
    while (true) {
        cout << "0 for exit!\n";
        cout << "New item name: "; getline(cin, itemNew);
        if (itemNew == "0")break;
        cout << "Price: "; cin >> priceNew;
        cin.ignore('\n', 10);
        list.push_back(new Shop(itemNew, priceNew));
    }

    //Принтиране на новите артикули
    cout << "\n\nList of the new items:\n";
    for (int x = 0; x < list.size(); x++)
        list[x]->printItem();

    

    //Записване в нов файл
    fstream NewItems;
    NewItems.open("D:\\Testing files\\New item list.txt", ios::out);
    for (int i = 0; i < list.size(); i++)
    NewItems << list[i]->name << '\t'
        << list[i]->getPrice() << " lv." << endl;
    NewItems.close();
    return 0;
}