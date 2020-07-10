#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int T;
	for (cin >> T; T > 0; --T) {
		vector<int> vec;
		int N;
		int answer = 0;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			int val;
			cin >> val;
			vec.push_back(val);
		}

		for (int i = 0; i < vec.size(); ++i) {
			int left = 0, right = 0;
			for (int j = 0; j < i; ++j) {
				if (vec[j] < vec[i]) {
					++left;
				}
			}
			for (int j = i + 1; j < vec.size(); ++j) {
				if (vec[j] > vec[i]) {
					++right;
				}
			}
			answer += (left * right);
		}
		cout << answer << endl;
	}
	return 0;
}
