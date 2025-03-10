#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

void time(vector<int>& a, string t) {
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
	int bestTime = INT_MAX, i1;
	for (size_t i = 0; i < a.size(); i++) {
		int min = b[0] - a[i];
		if (min < 0)min += 2400;
		if (min < bestTime) {
			bestTime = min;
			i1 = i;
		}
	}
	cout << i1+1;
}

int main() {
	int n;
	cin >> n;
	cin.ignore();

	string timeBus, timeTrain;
	getline(cin, timeBus);
	getline(cin, timeTrain);

	vector<int>incpection;
	vector<int>usag;
	time(incpection, timeBus);
	time(usag, timeTrain);

	calculation(incpection, usag);
	return 0;
}