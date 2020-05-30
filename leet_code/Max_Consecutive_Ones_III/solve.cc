class Solution {
public:
	int longestOnes(vector<int>& A, int K) {
		int longest = 0;
		queue<int> zeros;

		for (int i = 0, j = 0; i < A.size(); ++i) {
			if (A[i] == 0) {
				if (K > 0) {
					if (zeros.size() == K) {
						if (j <= zeros.front()) {
							j = zeros.front() + 1;
						}
						zeros.pop();                        
					}
					zeros.push(i);
				} else {
					j = i + 1;
					continue;
				}
			}

			if (((i - j) + 1) > longest) {
				longest = i - j + 1;
			}
		}
		return longest;
	}

};
