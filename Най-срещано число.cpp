#include <iostream>
using namespace std;

int main() {
	int mas[100], broqch[9] = { 0 };
	int n, max = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> mas[i];
		broqch[mas[i]]++;
		if (broqch[mas[i]] > max) {
			max = broqch[mas[i]];
		}
	}
	for (int i = 0; i < 10; i++) {
		if (broqch[i] == max)cout << i << ' ';
	}
	return 0;
}