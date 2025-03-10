#include <iostream>
#include <string>
#include <vector>
using namespace std;

void math(vector<int>& a) {
	vector<int> b;
	for (size_t i = 0; i < a.size() - 1; ++i) {
		b.push_back(a[i] + a[i + 1]);
	}
	a = b;
}

int main() {
	int n;
	cin >> n;
	vector<int>numbers(n, 0);
	for (size_t i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	while (numbers.size()>1) {
		math(numbers);
	}
	cout << numbers[0];
	return 0;
}