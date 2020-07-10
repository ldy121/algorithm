#include <iostream>

using namespace std;

int main(void) {
	int input = 1775;
	int lsb = 0;
	int msb = lsb;
	for (int i = 0; i < sizeof(int) * 8; ++i) {
		if ((input & 1 << i) > 0) {
			lsb = i;
			break;
		}
	}
	for (int i = lsb; i < sizeof(int) * 8; ++i) {
		if ((input & (1 << i))  == 0) {
			msb = i;
			cout << i << endl;
			break;
		}
	}

  int smallest = (lsb > 0) ? (input & ~(1 << lsb)) | (1 << (lsb - 1)) : input;
	int longest = (input | (1 << msb)) & ~(1 << lsb);
	cout << smallest << endl;
	cout << longest << endl;
}
