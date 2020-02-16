#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(void)
{
	int T;

	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	for (cin >> T; T > 0; --T) {
		int N, M, X;
		bool exist;
		vector<int> A;
		unordered_map<int, int> B;

		cin >> N >> M >> X;
		for (int i = 0; i < N; ++i) {
			int input;
			cin >> input;
			A.push_back(input);
		}

		for (int i = 0; i < M; ++i) {
			int input;
			cin >> input;
			if (B.find(input) == B.end()) {
				B[input] = 1;
			} else {
				++B[input];
			}
		}

		exist = false;
		for (int i = 0; i < N; ++i) {
			int val = X - A[i];
			if (B.find(val) != B.end()) {
				if (exist) {
					cout << ", ";
				}
				for (int j = B[val]; j > 0; --j) {
					cout << A[i] << " " << val;
				}
				exist = true;
			}
		}

		if (exist == false) {
			cout << -1 << endl;
		} else {
			cout << endl;
		}
	}
		

	return 0;
}
