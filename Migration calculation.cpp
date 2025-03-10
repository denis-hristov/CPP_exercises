#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	fstream cities("D:\\Testing files\\City population.txt", ios::in);
	if (!cities.is_open()) {
		cout << "Erorr!";
		return -1;
	}
	vector<pair<string, int>>population;
	while (!cities.eof()) {
		string city;
		int people, extraPeople;
		getline(cities, city, ' ');
		cities >> people, ' ';
		cities >> extraPeople;
		cities.ignore();
		population.push_back(make_pair(city, people + extraPeople));
	}

	for (int i = 0; i < population.size(); i++)
		cout << population[i].first << "\t\t" << population[i].second << endl;
	cout << endl;

	vector<pair<string, int>>sorted;
	for (int i = 0; i < population.size(); i++) {
		size_t t = 0;
		while ((t < sorted.size()) && (population[i].second < sorted[t].second))
			t++;
		if (t == population.size())
			sorted.push_back(make_pair(population[i].first, population[i].second));
		else sorted.insert(sorted.begin() + t, population[i]);
	}

	for (int i = 0; i < sorted.size(); i++)
		cout << sorted[i].first << "\t\t" << sorted[i].second << endl;
	cout << endl;
	return 0;
}