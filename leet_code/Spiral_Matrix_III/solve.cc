class Solution {
private :
	inline void input(vector<vector<int> >& vec, int r, int R, int c, int C) {
		if ((r < R) && (r >= 0) && (c < C) && (c >= 0)) {
			vector<int> v;
			v.push_back(r);
			v.push_back(c);
			vec.push_back(v);
		}
	}

public:
	vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
		vector<vector<int> > ret;
		vector<int> vec;

		vec.push_back(r0);
		vec.push_back(c0);
		ret.push_back(vec);

		for (int len = 1, r = r0, c = c0; ret.size() < (R * C);) {
			for (int i = 0; i < len; ++i) { // right
				input(ret, r, R, ++c, C);
			}

			for (int i = 0; i < len; ++i) { // down
				input(ret, ++r, R, c, C);
			}

			++len;

			for (int i = 0; i < len; ++i) { // left
				input(ret, r, R, --c, C);
			}

			for (int i = 0; i < len; ++i) { // up
				input(ret, --r, R, c, C);
			}

			++len;
		}
		return ret;
	}
};
