#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <locale>

int main() {
    std::locale::global(std::locale("bg_BG.UTF-8"));
    std::string number, line;
    std::ifstream last_number("D:\\Programs\\Quotes generator\\last number V3.txt", std::ios::in);
    if (last_number.is_open()) {
        std::getline(last_number, number);
        last_number.close();
    }
    else {
        std::cerr << "Unsucsesfull opening of last number.txt" << std::endl;
        return 1;
    }

    int random_index;
    do {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(1, 660);

        random_index = distrib(gen);
    } while (random_index == stoi(number));

    std::ofstream new_number("D:\\Programs\\Quotes generator\\last number V3.txt", std::ios::trunc);
    new_number << random_index;
    new_number.close();

    std::ifstream file("D:\\Programs\\Quotes generator\\Quotes 660.txt", std::ios::in);
    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (stoi(line.substr(0, line.find(')'))) == random_index) {
                line = line.substr(line.find(' ') + 1);
                break;
            }
        }
        file.close();
    }
    else {
        std::cerr << "Unsucsesfull opening of quotes.txt" << std::endl;
        return 2;
    }

    std::cout << "Randum number: " << random_index << std::endl;
    std::cout << "Quote: " << line << std::endl;

    return 0;
}
