#include <iostream>
#include <unordered_map>

using namespace std;

int getBleakNumbers(int x) {
	int cnt = 0;
	for (int i = x; i > 0; i >>= 1) {
		if (i & 0x1) {
			++cnt;
		}
	}
	return cnt + x;
}

int main() {
	unordered_map<int, int> hash;
	int T;

	for (int i = 0; i <= 1000000; ++i) {
		hash[getBleakNumbers(i)] = i;
	}

	for (cin >> T; T > 0; --T) {
		int N;
		cin >> N;
		cout << (hash.find(N) == hash.end()) << endl;
	}

	return 0;
}
