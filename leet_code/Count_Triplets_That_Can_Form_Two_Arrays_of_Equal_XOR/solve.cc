class Solution {
public:
	int countTriplets(vector<int>& arr) {
		int answer = 0;
		for (int i = 0; i < arr.size(); ++i) {
			int sum = arr[i];
			for (int k = i + 1; k < arr.size(); ++k) {
				sum ^= arr[k];

				for (int j = i + 1, a = arr[i], b = sum ^ arr[i]; j <=k; ++j) {
					if (a == b) {
						++answer;
					}
					a ^= arr[j];
					b ^= arr[j];
				}
			}
		}
		return answer;
	}
};
