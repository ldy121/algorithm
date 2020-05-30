class CombinationIterator {
private :
	list<string> m_list;
	list<string>::iterator m_iter;

	void generate(string& characters, string str, int idx, int n) {
		if (n == 0) {
			m_list.push_back(str);
		} else if ((n > 0) && (idx < characters.length())) {
			generate(characters, str + characters[idx], idx + 1, n - 1);
			generate(characters, str, idx + 1, n);
		}
	}

public:
	CombinationIterator(string characters, int combinationLength) {
		string str;
		generate(characters, str, 0, combinationLength);
		m_iter = m_list.begin();
	}

	string next() {
		string ret = *m_iter;
		++m_iter;
		return ret;
	}

	bool hasNext() {
		return (m_iter != m_list.end());
	}
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
