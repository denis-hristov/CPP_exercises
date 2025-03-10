#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

void separator(vector<int>& a, string t) {
	for (size_t i = 0; i < t.size(); i++)
		a.push_back(t[i]);
}

void arranged(vector<int>a1) {
	int a = 0;//{}
	int b = 0;//[]
	int c = 0;//()
	bool result = true;
	for (int i = 0; i < a1.size();i++) {
		switch (a1[i]) {
			case '{':if (b == 0 && c == 0)a++;
					else result = false;
				break;
			case '}':if (b == 0 && c == 0)a--;
					else result = false;
				break;
			case '[':if(c==0)b++;
					else result = false;
				break;
			case ']':if (c == 0)b--;
					else result = false;
				break;
			case '(':c++;
				break;
			case ')':c--;
				break;
		}
	}
	if (result && a == 0 && b == 0 && c == 0)
		cout << "valid";
	else cout << "invalid";
}

int main() {
	vector<int>vec;
	string A;
	getline(cin, A);
	separator(vec, A);

	arranged(vec);
	return 0;
}