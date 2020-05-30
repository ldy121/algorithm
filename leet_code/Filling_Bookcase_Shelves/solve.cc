class Solution {
private :
	const int c_init = 100000000;
	vector<int> m_height;
	int calcHeight(vector<vector<int>> &books, int shelfWidth, int idx) {
		if (idx >= books.size()) {
			return 0;
		}

		if (m_height[idx] == c_init) {
			int width = 0;
			int height = 0;

			for (int i = idx; i < books.size(); ++i) {
				width += books[i][0];
				if (books[i][1] > height) {
					height = books[i][1];
				}

				if (width <= shelfWidth) {
					int sum = height + calcHeight(books, shelfWidth, i + 1);
					if (sum < m_height[idx]) {
						m_height[idx] = sum;
					}
				} else {
					break;
				}
			}
		}
		return m_height[idx];
	}

public:
	int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
		for (int i = 0; i < books.size(); ++i) {
			m_height.push_back(c_init);
		}
		return calcHeight(books, shelf_width, 0);
	}
};
