#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

void enterData(vector<int>& a, string t) {
	size_t i, j = 0;
	while (true) {
		i = t.find(' ', j);
		string s = t.substr(j, i - j);
		if (s == " ")break;
		a.push_back(stoi(s));
		if (i == t.npos)break;
		j = i + 1;
	}
}

void calculation(vector<int> a, vector<int> b) {
	for (size_t i = 0; i < a.size(); i++) {
		int times = 0;
		int oneYear = b[i] - a[i];
		int sumYears = oneYear;
		while (sumYears <= b[i]) {
			sumYears += oneYear;
			times++;
		}
		cout << times << ' ';
	}
}

int main() {
	int n;
	cin >> n;
	cin.ignore();

	string use, years;
	getline(cin, use);
	getline(cin, years);

	vector<int>incpection;
	vector<int>usag;
	enterData(incpection, use);
	enterData(usag, years);

	calculation(incpection, usag);
	return 0;
}