#include <iostream>

using namespace std;

int main(void) {
	unsigned int left_mask = 0xaaaaaaaa;
  unsigned int right_mask = 0x55555555;
	unsigned int val = 0x12345678;
  unsigned int output = ((val << 1) & left_mask) | ((val >> 1) & right_mask);
	cout << output << endl;
	return 0;
}
