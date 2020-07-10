#include <iostream>

using namespace std;

int main(void) {
	int a = 29;
	int b = 15;
	int answer = 0;

	for (int c = a ^ b; c > 0; c >>= 1) {
		if (c & 1) {
			++answer;
		}
	}

	cout << answer << endl;
	return 0;
}
