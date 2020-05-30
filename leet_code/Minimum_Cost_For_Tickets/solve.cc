class Solution {
private :
	const int c_init = -1;
	vector<int> m_answer;
	int getAnswer(vector<int>& days, vector<int>& costs, int idx) {
		if (m_answer.size() <= idx) {
			return 0;
		}

		if (m_answer[idx] != c_init) {
			return m_answer[idx];
		}

		m_answer[idx] = costs[0] + getAnswer(days, costs, idx + 1);

		int day;
		for (day = idx + 1; day < days.size(); ++day) {
			if (days[day] >= (days[idx] + 7)) {
				break;
			}
		}

		int ret = costs[1] + getAnswer(days, costs, day);
		if (m_answer[idx] > ret) {
			m_answer[idx] = ret;
		}

		while (day < days.size()) {
			if (days[day] >= (days[idx] + 30)) {
				break;
			} else {
				++day;
			}
		}

		ret = costs[2] + getAnswer(days, costs, day);
		if (m_answer[idx] > ret) {
			m_answer[idx] = ret;
		}

		return m_answer[idx];
	}

public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		for (int i = 0; i < days.size(); ++i) {
			m_answer.push_back(c_init);
		}
		return getAnswer(days, costs, 0);
	}
};
