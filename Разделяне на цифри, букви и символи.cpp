#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

int main() {
	string duma;
	getline(cin, duma);	
	ostringstream cifri, bukvi, simvoli;
	for (int i = 0; i < duma.size(); i++) {
		if (isdigit(duma[i]))cifri << duma[i];
		else if (isalpha(duma[i]))bukvi << duma[i];
		else simvoli << duma[i];
	}
	cout << cifri.str() << endl
		<< bukvi.str() << endl
		<< simvoli.str() << endl;
	return 0;
}