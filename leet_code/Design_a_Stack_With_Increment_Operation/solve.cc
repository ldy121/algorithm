class CustomStack {
private :
	vector<int> m_vec;
	int m_iSize;
	int m_idx;
public:
	CustomStack(int maxSize) {
		for (int i = 0; i < maxSize; ++i) {
			m_vec.push_back(0);
		}
		m_iSize = maxSize;
		m_idx = 0;
	}

	void push(int x) {
		if (m_idx < m_iSize) {
			m_vec[m_idx++] = x;
		}
	}

	int pop() {
		int ret = -1;
		if (m_idx > 0) {
			ret = m_vec[--m_idx];
		}
		return ret;
	}

	void increment(int k, int val) {
		int size = (m_idx < k) ? (m_idx) : (k);
		for (int i = 0; i < size; ++i) {
			m_vec[i] += val;
		}
	}
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
