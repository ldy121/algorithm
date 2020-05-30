class Solution {
private :
	unordered_map<char, string> m_hash;
	vector<char> m_vec;
	void qsort(int left, int right) {
		if (left < right) {
			int i, j;
			char k;

			for (i = left + 1, j = left; i <= right; ++i) {
				if (m_hash[m_vec[left]].length() < m_hash[m_vec[i]].length()) {
					++j;
					k = m_vec[j];
					m_vec[j] = m_vec[i];
					m_vec[i] = k;;
				}
			}

			k = m_vec[j];
			m_vec[j] = m_vec[left];
			m_vec[left] = k;

			qsort(left, j - 1);
			qsort(j + 1, right);
		}
	}

public:
	string frequencySort(string s) {
		string ret;

		for (int i = 0; i < s.length(); ++i) {
			if (m_hash.find(s[i]) == m_hash.end()) {
				m_vec.push_back(s[i]);
				m_hash[s[i]] = s[i];
			} else {
				m_hash[s[i]] += s[i];
			}
		}

		qsort(0, m_vec.size() - 1);

		for (int i = 0; i < m_vec.size(); ++i) {
			ret += m_hash[m_vec[i]];
		}
		return ret;
	}
};
