#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double a, b, c;
	cin >> a >> b >> c;
	
	cout << fixed << setprecision(2);
	int d = b / 15;
	double vreme = b * c + d * 12.5 ;
	
	if (vreme < a) {
		cout << "Yes, he succeeded! The new world record is "
			<< vreme << " seconds.";
	}
	else {
		cout << "No, he failed! He was "
			<< vreme - a
			<< " seconds slower.";
	}
	return 0;
}
