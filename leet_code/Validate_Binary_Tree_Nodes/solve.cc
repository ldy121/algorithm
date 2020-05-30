class Solution {
public:
	bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
		vector<bool> visit(n, false);
		queue<int> q;        

		for (q.push(0); !q.empty();) {
			for (int size = q.size(); size > 0; --size) {
				int node = q.front();

				q.pop();
				if (visit[node] == true) {
					return false;
				} else {
					visit[node] = true;
				}

				if (leftChild[node] >= 0)    q.push(leftChild[node]);
				if (rightChild[node] >= 0)   q.push(rightChild[node]);
			}
		}

		for (int i = 0; i < n; ++i) {
			if (visit[i] == false) {
				return false;
			}
		}
		return true;
	}
};
