#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

void* readCompany(istream& in) {
    string id, name;
    cin >> id;
    if (id == "end")
        return nullptr;
    cin >> name;

    char* company = new char[sizeof(int) + name.length() + 1];

    int* idPtr = reinterpret_cast<int *> (company);
    *idPtr = stoi(id);

    strcpy(company + sizeof(int), name.c_str());
    return company;
}

bool isValid(void* company) {
    int* id = static_cast<int*>(company);
    return *id >= 0;
}

void print(void* company) {
    int* id = static_cast<int*>(company);
    const char* name = reinterpret_cast<const char*>(id + 1);
    cout << *id << ' ' << name << endl;
}

int main() {
    vector <void*>companies;
    while (true) {
        void* newCompany = readCompany(cin);
        if (newCompany == nullptr)
            break;

        companies.push_back(newCompany);
    }

    for (void* i : companies) {
        if (isValid(i))
            print(i);
    }

    for (void* i : companies)
        delete[]static_cast<char*>(i);
    companies.clear();
    return 0;
}