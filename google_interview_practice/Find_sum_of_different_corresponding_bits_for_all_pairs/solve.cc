#include <iostream>
#include <vector>
using namespace std;

const int module = 1000000007;

int main() {
	int T, N;
	for (cin >> T; T > 0; --T) {
	    vector<int> A;
	    int answer = 0;
	    cin >> N;
	    for (int i = 0; i < N; ++i) {
	        int val;
	        cin >> val;
	        A.push_back(val);
	    }
	    
        for (int j = 0; j < 32; ++j) {
            int one = 0;
            int zero = 0;
            for (int i = 0; i < N; ++i) {
                if ((A[i] >> j) & 1) {
                    ++one;
                } else {
                    ++zero;
                }
            }
            answer += (one * zero * 2);
            answer %= module;
        }

	    cout << answer << endl;
	}
	return 0;
}
