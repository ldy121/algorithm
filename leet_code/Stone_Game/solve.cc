class Solution {
private :
	const int init = -1;
	const int win = 1;
	const int lose = 0;
	const int turn_alex = 0;
	const int turn_lee = 1;

	vector<vector<int> > m_answer[2];

	int get_answer(vector<int>& piles, int left, int right, int turn) {
		if (m_answer[turn][left][right] == init) {
			int take_left = piles[left] + get_answer(piles, left + 1, right, !turn);
			int take_right = piles[right] + get_answer(piles, left, right - 1, !turn);
			int take;

			if (turn == turn_alex)  take = (take_left > take_right) ? take_left : take_right;
			else                    take = (take_left < take_right) ? take_left : take_right;

			m_answer[turn][left][right] = take;
		}

		return m_answer[turn][left][right];
	}

public:
	bool stoneGame(vector<int>& piles) {
		int sum = 0;
		int answer;

		for (int i = 0; i < piles.size(); ++i) {
			vector<int> vec(piles.size(), init);
			m_answer[0].push_back(vec);
			m_answer[1].push_back(vec);
			m_answer[turn_alex][i][i] = piles[i];
			m_answer[turn_lee][i][i] = piles[i];

			sum += piles[i];
		}

		answer = get_answer(piles, 0, piles.size() - 1, turn_alex);
		return (answer > (sum - answer));
	}
};
