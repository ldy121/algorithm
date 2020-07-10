#include <iostream>
#include <vector>
using namespace std;

const int N = 60;

int main() {
	int T;
	for (cin >> T; T > 0; --T) {
		uint64_t A, B, C;
		uint64_t answer = 1;
		vector<uint64_t> vec;

        cin >> A >> B >> C;
        vec.push_back(A % C);
        for (int i = 1; i < N; ++i) {
	        uint64_t val = vec[i - 1] * vec[i - 1];
	        vec.push_back(val % C);
        }

		int j = 0;
        for (int i = B; i > 0; i >>= 1) {
	        if (i & 1) {
		        answer *= vec[j];
		        answer %= C;
	        }
	        ++j;
        }
        cout << answer << endl;
	}
	return 0;
}

