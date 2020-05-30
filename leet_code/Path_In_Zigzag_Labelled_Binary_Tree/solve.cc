class Solution {
public:
	vector<int> pathInZigZagTree(int label) {
		vector<int> parent(label * 2);
		vector<int> ret;
		stack<int> sp;
		queue<int> q;

		bool loop = true;

		parent[1] = 0;

		q.push(1);

		for (int level = 1; (label >= (1 << level)) && (!q.empty()); ++level) {
			int idx;

			if ((level % 2) == 1) {
				idx = (1 << (level + 1)) - 1;
			} else {
				idx = (1 << (level));
			}

			for (int size = q.size(); size > 0; --size) {
				int node = q.front();
				q.pop();

				if ((level % 2) == 1) {
					parent[idx] = node;
					q.push(idx--);
					parent[idx] = node;
					q.push(idx--);
				} else {
					parent[idx] = node;
					q.push(idx++);
					parent[idx] = node;
					q.push(idx++);
				}
			}

			if (((1 << level) <= label) && (label < (1 << (level + 1)))) {
				break;
			}
		}

		for (int i = label; i > 0; i = parent[i]) {
			sp.push(i);
		}

		while (!sp.empty()) {
			ret.push_back(sp.top());
			sp.pop();
		}

		return ret;
	}
};
