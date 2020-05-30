unordered_map<int, int> g_count;

class Solution {
private :
	vector<int> m_number;

	class comp {
		public :
			bool operator () (const int & a, const int & b) {
				return (g_count[a] > g_count[b]);
			}
	};

public:
	int minSetSize(vector<int>& arr) {
		int ret = 0;

		g_count.clear();

		for (int i = 0; i < arr.size(); ++i) {
			if (g_count.find(arr[i]) == g_count.end()) {
				g_count[arr[i]] = 0;
				m_number.push_back(arr[i]);
			}
			++g_count[arr[i]];
		}

		sort(m_number.begin(), m_number.end(), comp());

		for (int cnt = 0, i = 0; i < m_number.size(); ++i) {
			cnt += g_count[m_number[i]];
			++ret;
			if (cnt >= (arr.size() / 2)) {
				break;
			}
		}

		return ret;
	}
};
