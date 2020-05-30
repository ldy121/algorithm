class Solution {
public:
	int findMinFibonacciNumbers(int k) {
		vector<int> fab;
		int answer = 0;

		fab.push_back(1);
		fab.push_back(1);
		for (int i = fab.size(); (fab[i - 1] + fab[i - 2]) <= k; ++i) {
			fab.push_back(fab[i - 1] + fab[i - 2]);
		}

		for (int i = fab.size() - 1; i >= 0; --i) {
			if (k >= fab[i]) {
				k -= fab[i];
				++answer;
			}
		}

		return answer;
	}
};
