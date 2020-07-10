#include <iostream>
using namespace std;

int64_t getPossibility(int64_t width, int64_t bits) {
	int64_t ret = 1;
	if (width < bits) {
		return 0;
	}
	for (int64_t i = 1; i <= bits; ++i) {
		ret *= width--;
		ret /= i;
	}

	return ret;
}

int main() {
	int T;
	for (cin >> T; T > 0; --T) {
		int64_t N, bit = 0, answer = 0;
		cin >> N;
		for (int64_t i = 0; N > 0; ++i, N >>= 1) {
			if (N & 0x1) {
				++bit;
				answer += getPossibility(i, bit);
			}
		}
		cout << answer << endl;
	}
	return 0;
}
