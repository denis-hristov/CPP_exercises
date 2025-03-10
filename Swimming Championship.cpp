#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <list>
#include <iomanip>
using namespace std;


int main() {
	int daysChampionship, pointsNeeded, numberSwimmers;
	double hotelPrice, swimmerFee;

	cin >> daysChampionship >> pointsNeeded >> numberSwimmers
		>> hotelPrice >> swimmerFee;

	double points, pointsSum = 0, bonusPoints = 0;;
	for (int i = 0; i < daysChampionship; i++) {
		cin >> points;
		pointsSum += points;
		if(i<daysChampionship-1)
			bonusPoints += (points * 0.05);
	}

	if (daysChampionship > 2)pointsSum += bonusPoints;

	double moneyExpenses = (numberSwimmers*daysChampionship)
		*hotelPrice+(numberSwimmers*swimmerFee);

	cout << fixed << setprecision(2);
	if (pointsSum >= double(pointsNeeded)){
		moneyExpenses -= (moneyExpenses * 0.25);
		cout << "Money left to pay: "
		<< moneyExpenses
		<< " BGN." << endl
		<< "The championship was successful!";
	}
	else {
		moneyExpenses -= (moneyExpenses * 0.1);
		cout << "Money left to pay: "
			<< moneyExpenses
			<< " BGN." << endl
			<< "The championship was not successful.";
	}
	return 0;
}