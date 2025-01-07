#include <iostream>
using namespace std;
int main()
{
	int n1 ,n2;
	cin >> n1 >> n2;
	for (n1; n1 <= n2; n1++) {
		int copi = n1;
		int necetni = 0, cetni=0;
		for (int i = 0, y=10; i <= 6; i++) {
			if (i % 2 != 0)necetni += (copi%y);
			else cetni += (copi%y);
			copi /= 10;
		}
		if (necetni == cetni) {
			cout << n1<<' ';
		}
	}
	return 0;
}
