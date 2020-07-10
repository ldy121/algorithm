#include <iostream>

using namespace std;

int getNumberMax(int a, int b) {
	int sign = (((a - b) >> (8 * sizeof(a) - 1)) & 0x1);
  return b * sign + a * (sign ^ 0x1);
}

int main(void) {
	cout << getNumberMax(10, 8) << endl;
	cout << getNumberMax(8, 11) << endl;
}
