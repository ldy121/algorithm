class Solution {
private :    
	int m_king_row;
	int m_king_col;

	enum position {
		leftup,
		up,
		rightup,        
		left,
		right,
		leftdown,        
		down,
		rightdown
	};

	const int c_init = -1;

	inline int comp_replace(vector<vector<int>> &queens, int src, int dst) {
		if (src == c_init) {
			return dst;
		} else {
			int a_row = queens[src][0], a_col = queens[src][1];
			int b_row = queens[dst][0], b_col = queens[dst][1];
			return (((a_row - m_king_row) * (a_row - m_king_row) + (a_col - m_king_col) * (a_col - m_king_col)) < 
				((b_row - m_king_row) * (b_row - m_king_row) + (b_col - m_king_col) * (b_col - m_king_col))) ? src : dst;
		}
	}

public:
	vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
		vector<int> attack;
		vector<vector<int> > ret;

		m_king_row = king[0];
		m_king_col = king[1];

		for (int i = leftup; i <= rightdown; ++i) {
			attack.push_back(c_init);
		}

		for (int i = 0; i < queens.size(); ++i) {
			int row = queens[i][0];
			int col = queens[i][1];
			int diff_row = m_king_row - row;
			int diff_col = m_king_col - col;

			if (diff_row < 0) diff_row *= -1;
			if (diff_col < 0) diff_col *= -1;

			if (m_king_row == row) {
				if (col < m_king_col) // left
					attack[left] = comp_replace(queens, attack[left], i);
				else                  // right
					attack[right] = comp_replace(queens, attack[right], i);
			} else if (m_king_col == col) {   
				if (row < m_king_row) // up
					attack[up] = comp_replace(queens, attack[up], i);
				else                  // down 
					attack[down] = comp_replace(queens, attack[down], i);
			} else if (diff_row == diff_col) {                  // diagonal
				if (row < m_king_row && col < m_king_col) {         // leftup
					attack[leftup] = comp_replace(queens, attack[leftup], i);
				} else if (row < m_king_row && col > m_king_col) {  // rightup
					attack[rightup] = comp_replace(queens, attack[rightup], i);
				} else if (row > m_king_row && col < m_king_col) {  // leftdown
					attack[leftdown] = comp_replace(queens, attack[leftdown], i);
				} else {                                        // rightdown
					attack[rightdown] = comp_replace(queens, attack[rightdown], i);
				}
			}
		}

		for (int i = leftup; i <= rightdown; ++i) {
			if (attack[i] != c_init) {
				vector<int> vec;

				vec.push_back(queens[attack[i]][0]);
				vec.push_back(queens[attack[i]][1]);

				ret.push_back(vec);
			}
		}
		return ret;
	}
};
