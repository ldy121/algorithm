class Solution {
public:
  bool canReach(vector<int>& arr, int start) {
		vector<bool> visit(arr.size(), false);
		queue<int> q;

		visit[start] = true;
		for (q.push(start); !q.empty();) {
			for (int size = q.size(); size > 0; --size) {
				int idx = q.front();
				q.pop();

				if (arr[idx] == 0) {
					return true;
				}
				if (idx + arr[idx] < arr.size() && visit[idx + arr[idx]] == false) {
					visit[idx + arr[idx]] = true;
					q.push(idx + arr[idx]);
				}
				if (idx - arr[idx] >= 0 && visit[idx - arr[idx]] == false) {
					visit[idx - arr[idx]] = true;
					q.push(idx - arr[idx]);
				}
			}
		}
		return false;
	}
};


