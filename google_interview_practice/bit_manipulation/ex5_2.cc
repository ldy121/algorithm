#include <iostream>

using namespace std;

int main(void) {
	double input = 0.72f;
	char* pt = (char*)&input;
	for (int i = 0; i < sizeof(input); ++i) {
		char ch = pt[i];
		for (int j = 7; j >= 0; --j) {
			bool bit = (ch & (1 << j)) > 0;
			cout << bit;
		}
		cout << '_'; 
	}
	cout << endl;
	return 0;
}
