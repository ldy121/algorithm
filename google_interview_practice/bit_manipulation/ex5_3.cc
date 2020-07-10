#include <iostream>

using namespace std;

void solution1(int input) {
	int lsb = 0;
	int max = 1;
	for (int i = 0; i + max < sizeof(int) * 8; ++i) {
		int msb = (1 << i);
		if ((msb & input) == 0) {
			int j = input | msb;
			for (int k = max; (j & (((1 << k) - 1) << lsb)) == (((1 << k) - 1) << lsb); ++k) {
				max = k;
			}

			lsb = i + 1;
		}
	}
	cout << max << endl;
}

void solution2(int n) {
	int left = 0;
	int right = 0;
	int maxLength = 0;
	int zero = 0;
	while (n > 0) {
		if (n & 1) {
			++right;
		} else {
			left = ((n & 0x2) > 0) ? (right) : 0;
			right = 0;
			zero = 1;
		}

		if (maxLength < (left + right + zero)) {
			maxLength = left + right + zero;
		}

		n >>= 1;
	}
	cout << maxLength << endl;
}

int main(void) {
	solution1(1775);
	solution2(1775);
	return 0;
}
