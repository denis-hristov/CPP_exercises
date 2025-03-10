#include <iostream>
#include <string>
using namespace std;

int main() {
	string text, noNumber;
	getline(cin, text);
	int sum = 0, i = 0;
	while (true) {
		int y = text.find(" ", i);
		if (y == text.npos)y = text.size();
		string number = text.substr(i, y-i);
		bool correct = true;
		for (int j = 0; j < number.size(); j++) {
			if (j == 0 && number[j] == '-') continue;
			if (!isdigit(number[j])) correct = false;
		}
		if (correct)sum += stoi(number);
		else noNumber += (number + ' ');
		if (y == text.size()) break;
		i = y+1;
	}
	cout << sum <<endl << noNumber;
	return 0;
}