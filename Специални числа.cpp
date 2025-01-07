#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1111; i <= 9999; i++) {
		bool stop = true;
		int stoinost = i;
		int broi = 0;
		int loops = 0;
		while (stop){
			if (stoinost % 10 == 0)break;
			int iftrue = (n * 10) / (stoinost % 10);
			if (iftrue % 10 == 0) {
				broi++;
				stoinost /= 10;
			}
			if (broi == 4) {
				cout << i << ' ';
				stop = false;
			}
			loops++;
			if (loops>4)break;
		}
	}
	return 0;
}
