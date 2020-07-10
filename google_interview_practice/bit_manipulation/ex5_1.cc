#include <iostream>

using namespace std;

int main(void) {
	int N = 0b10000000000;
	int M = 0b10011;
	int i = 2, j = 6;
	int output = (N & ~((1 << (j - i + 1) - 1) << i)) | (M << i);
	for (int i = 10; i >= 0; --i) {
		bool bit = (output & (1 << i)) > 0;
		cout << bit;
	}
	cout << endl;
	return 0;
}
