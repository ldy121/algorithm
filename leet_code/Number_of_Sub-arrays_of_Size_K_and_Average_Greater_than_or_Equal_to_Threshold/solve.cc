class Solution {
public:
	int numOfSubarrays(vector<int>& arr, int k, int threshold) {
		queue<int> q;
		int sum = 0;
		int ret = 0;

		for (int i = 0; i < arr.size(); ++i) {
			q.push(i);
			sum += arr[i];
			if (q.size() > k) {
				sum -= arr[q.front()];
				q.pop();
			}

			if ((q.size() == k) && ((sum / k) >= threshold)) {
				++ret;
			}
		}

		return ret;
	}
};
