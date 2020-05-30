class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		vector<int> relationship;
		int answer = 0;

		for (int i = 0; i < M.size(); ++i) {
			relationship.push_back(i);
		}

		for (int i = 0; i < M.size(); ++i) {
			int root = i;
			while (relationship[root] != root) {
				root = relationship[root];
			}

			relationship[i] = root;
			for (int j = i + 1; j < M[i].size(); ++j) {
				int k;
				if (M[i][j] == 0) {
					continue;
				}

				for (k = j; relationship[k] != k; k = relationship[k]);
				relationship[k] = root;
				relationship[j] = root;
			}
		}

		for (int i = 0; i < M.size(); ++i) {
			if (relationship[i] == i) {
				++answer;
			}
		}

		return answer;
	}
};
