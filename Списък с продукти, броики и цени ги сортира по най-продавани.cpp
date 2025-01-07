#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    //Пизане на Български език
    setlocale(LC_ALL, "bg_BG.UTF-8");

    //Отваряне на файла и проверка даки е отворен
    fstream sale("D:\\Testing files\\Sales.txt", ios::in);
    if (!sale.is_open()) {
        cout << "Error!";
        return -1;
    }

    //Записване на данните във вектор
    vector <pair<string, double>> sum;
    while (!sale.eof()) {
        string name;
        int count;
        double cost;
        getline(sale, name, '\t');
        sale >> count, '\t';
        sale >> cost, '\t';
        sale.ignore();
        sum.push_back(make_pair(name,count*cost));
    }
    sale.close();

    //Премахване на повторените продукти и събиране на сумите им
    for (int i = 0; i < sum.size(); i++) {
        int t = i+1;
        while (t < sum.size()) {
            if (sum[i].first == sum[t].first) {
                sum[i].second += sum[t].second;
                sum[t].first.clear();
                sum.erase(sum.begin() + t);
            }
            else t++;
        }
    }

    //Подреждане в низходящ ред
    vector<pair<string, double>>sorted;
    for (int a = 0; a < sum.size(); a++) {
        size_t pos = 0;
        while ((pos < sorted.size()) && (sum[a].second < sorted[pos].second))
            pos++;
        if (pos == sum.size())
            sorted.push_back(make_pair(sum[a].first, sum[a].second));
        else sorted.insert(sorted.begin() + pos, sum[a]);
    }

    //Записване в нов файл
    fstream ranking;
    ranking.open("D:\\Testing files\\Ranking.txt", ios::out);
    for (int i = 0; i < sorted.size(); i++)
    ranking << sorted[i].first << "\t" << sorted[i].second << endl;
    ranking.close();
    return 0;
}