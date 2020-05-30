class Solution {
public:
	vector<int> pancakeSort(vector<int>& A) {
		vector<int> ret;

		for (int i = A.size(); i > 0; --i) {
			int j = 0;
			for (j = 0; j < A.size(); ++j) {
				if (A[j] == i) {
					break;
				}
			}

			if (i != (j + 1)) {
				int left, right;
				for (left = 0, right = j; left <= right; ++left, --right) {
					int k = A[left];
					A[left] = A[right];
					A[right] = k;
				}

				ret.push_back(j + 1);

				for (left = 0, right = i - 1; left <= right; ++left, --right) {
					int k = A[left];
					A[left] = A[right];
					A[right] = k;                    
				}
				ret.push_back(i);
			}
		}
		return ret;
	}
};
