unordered_map<int, int> g_answer;

class Solution {
private :
	int get_answer(int val) {
		if (g_answer.find(val) == g_answer.end()) {
			int ret = ((val % 2) == 0) ? 
				get_answer(val / 2) : get_answer(3 * val + 1);
			g_answer[val] = ret + 1;
		}
		return g_answer[val];
	}

	struct comp {
		bool operator() (int a, int b) {
			return ((g_answer[a] < g_answer[b]) ||
				((g_answer[a] == g_answer[b]) && (a < b)));
		}
	};    

public:    
	int getKth(int lo, int hi, int k) {
		priority_queue<int, vector<int>, comp> q;
		g_answer.clear();
		g_answer[1] = 1;

		for (int i = lo; i <= hi; ++i) {
			get_answer(i);
			if (q.size() < k) {
				q.push(i);
			} else {
				int val = q.top();
				if (g_answer[i] < g_answer[val]) {
					q.pop();
					q.push(i);
				}
			}
		}
		return q.top();
	}
};


