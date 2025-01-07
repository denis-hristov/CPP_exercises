#include <iostream>
#include <string>
using namespace std;

string obratno(string a,string n) {
	while(true){
		int b = a.find(n);
		if (b == -1)break;
		a.erase(b,n.size());
	}	
	return a;
}

int main() {
	string duma, delite;
	getline(cin, delite);
	getline(cin, duma);	
	cout << obratno(duma, delite);
	return 0;
}