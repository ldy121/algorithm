#include <iostream>
#include <vector>

using namespace std;

const int init = -2;
const int invalid = -1;

int getAnswer(vector<vector<int> > &answer, vector<int> &A, int k, int idx) {
	if (A.size() == idx) {
		return 0;
	}
  if (k < 0) {
		return invalid;
	}
  if (answer[k][idx] != init) {
	  return answer[k][idx];
  }

	int val = 0;
	int result = invalid;
	for (int i = idx; i < A.size(); ++i) {
		val += A[i];
		int ret = getAnswer(answer, A, k - 1, i + 1);
		if (ret == invalid) {
			continue;
		}
		if (ret < val) {
			ret = val;
		}
		if (result == invalid || result > ret) {
			result = ret;
		}
	}

	answer[k][idx] = result;
	return answer[k][idx];
}


int main() {
	int T;
	for (cin >> T; T > 0; --T) {
		vector<int> A;
		vector<vector<int> > answer;
		int K, N;

		cin >> K >> N;
		for (int i = 0; i < N; ++i) {
			int val;
			cin >> val;
			A.push_back(val);
		}

		for (int i = 0; i < K; ++i) {
			vector<int> vec(N, init);
			answer.push_back(vec);
		}
		cout << getAnswer(answer, A, K - 1, 0) << endl;
	}
	return 0;
}
