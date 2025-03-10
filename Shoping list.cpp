#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();

	vector<string>products;
	while (n>0) {
		string product;
		getline(cin, product);
		products.push_back(product);
		n--;
	}

	sort(products.begin(), products.end());
	cout << endl;

	size_t t = 1;
	for (vector<string>::iterator i = products.begin();
		i != products.end(); i++) {
		cout << t++ << '.' << *i << endl;
	}
	return 0;
}