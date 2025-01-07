#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main() {
	int n, sum=0;
	cin >> n;
	vector<int>number(n, 0);
	int average=0;
	for (int i = 0; i < n; i++) {
		cin >> number[i];
		average += number[i];
	}
	average /= n;
	for (vector<int>::iterator it = number.begin(); it != number.end();)
		if (*it > average) it = number.erase(it);
		else it++;
	int odd = 0, even = 0;
	for (int i = 0; i < number.size(); i++) {
		if (i % 2 != 0)odd += number[i];
		else even += number[i];
	}
	cout << even * odd;
	return 0;
}