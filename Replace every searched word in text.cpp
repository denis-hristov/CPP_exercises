#include <iostream>
#include <string>
using namespace std;

int main() {
	string text, serch, replace;
	getline(cin, text);
	cin >> serch >> replace;
	int i = 0;
	while (true) {
		int y = text.find(serch, i);
		if (y == text.npos)break;
		text.replace(y, serch.size(), replace);
		i = y+1;
	}
	cout << text;
	return 0;
}