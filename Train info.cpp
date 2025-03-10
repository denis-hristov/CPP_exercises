#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	fstream train("D:\\Testing files\\Train schedule.txt", ios::in);
	if (!train.is_open()) {
		cout << "Didn't find it";
		return -1;
	}

	//Reading the train schedule
	vector<pair<string, int>>stations;
	int sumPeople=0;
	while (!train.eof()) {
		string station;
		int peopleIn, peopleOut;
		getline(train, station, ';');
		train >> peopleIn, ';';
		train.ignore();
		train >> peopleOut,'\n';
		sumPeople += peopleIn;
		stations.push_back(make_pair(station, peopleIn - peopleOut));
	}
	train.close();
	
	//Outputing informtion
	cout << "All stations results:\n";
	for (int i = 0; i < stations.size(); i++) {
		cout << stations[i].first;
		if (stations[i].first.size() < 8)cout << "\t";
		if(stations[i].second>=0)cout << "\tPeople more: "
			<< stations[i].second;
		else cout << "\tPeople less: "
			<< abs(stations[i].second);
	}
	cout << "\n\nNumber of people: " << sumPeople << "\n\n";

	//Cities with more people getting out
	vector<pair<string, int>>PopularCities;
	for (int i = 0; i < stations.size(); i++) {
		if (stations[i].second > 0)
			PopularCities.push_back(
				make_pair(stations[i].first, stations[i].second));
	}

	//Outputing informtion
	cout << "Popular cities:\n";
	for (int i = 0; i<PopularCities.size();i++) {
		cout << PopularCities[i].first;
		if (PopularCities[i].first.size() < 8)cout << "\t";
		cout<< "\tPeople: "
			<< PopularCities[i].second;
	}
	cout << endl;

	//Information in the new file
	fstream infoTrain("D:\\Testing files\\Info Train.txt", ios::out);

	//Outputing informtion
	infoTrain << "All stations results:\n";
	for (int i = 0; i < stations.size(); i++) {
		infoTrain << stations[i].first;
		if (stations[i].first.size() < 8)infoTrain << "\t";
		if (stations[i].second >= 0)infoTrain << "\tPeople more: "
			<< stations[i].second;
		else infoTrain << "\tPeople less: "
			<< abs(stations[i].second);
	}
	infoTrain << "\n\nNumber of people: " << sumPeople << "\n\n";

	//Outputing informtion
	infoTrain << "Popular cities:\n";
	for (int i = 0; i < PopularCities.size(); i++) {
		infoTrain << PopularCities[i].first;
		if (PopularCities[i].first.size() < 8)infoTrain << "\t";
		infoTrain << "\tPeople: "
			<< PopularCities[i].second;
	}
	infoTrain.close();
	cout << "All done!";
	return 0;
}