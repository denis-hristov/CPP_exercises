#include <iostream>
#include <string>
using namespace std;

int main() {
	string duma;
	getline(cin, duma);
	duma[0] = toupper(duma[0]);
	int i = 0;
	while (true) {
		int y = duma.find_first_of(" ,.!?-;:", i);
		if (y == duma.npos)break;
		duma[y + 1] = toupper(duma[y + 1]);
		i = y+1;
	}
	cout << duma;
	return 0;
}