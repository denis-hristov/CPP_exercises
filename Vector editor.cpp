#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool separator(const string& s, string& a, int& b, int& c) {
	istringstream stream(s);
	if (!(stream >> a >> b >> c)) {
		return false;
	}
	else if (!(stream >> a >> b)) {
		return false;
	}
	return true;
}

void add(vector<int>&v, int a) {
	v.push_back(a);
}

void remove(vector<int>&v, int a) {
	for (size_t i = 0; i < v.size(); i++)
		if (v[i] == a)v.erase(v.begin() + i);
}

void removeat(vector<int>&v, int a) {
	v.erase(v.begin() + a);
}

void insert(vector<int>&v, int a, int b) {
	v.insert(v.begin() + b, a);
}

int main() {
	vector<int>numbers;
	string input;
	cout << "Enter your vector: ";
	getline(cin, input);

	size_t i = 0;
	while (true) {
		bool stop = false;
		int n = input.find(' ', i);
		if (n == input.npos)stop = true;
		string v = input.substr(i, n - i);
		numbers.push_back(stoi(v));
		i = n + 1;
		if (stop)break;
	}

	string commands, command;
	int position1, position2;
	cout << "Enter functio: ";
	while (getline(cin, commands) && commands != "end") {
		separator(commands, command, position1, position2);

		if (command == "Add")
			add(numbers, position1);

		if (command == "Remove")
			remove(numbers, position1);

		if (command == "RemoveAt")
			removeat(numbers, position1);

		if (command == "Insert")
			insert(numbers, position1, position2);
	}

	for (vector<int>::iterator t = numbers.begin();
		t != numbers.end(); t++) {
		cout << *t << ' ';
	}
	return 0;
}