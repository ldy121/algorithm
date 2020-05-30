class Solution {
private :
	void quick_sort(vector<vector<int> > &people, vector<int>& vec, int left, int right) {
		if (left < right) {
			int i, k, j = left;
			int left_idx = vec[left];

			for (i = left + 1; i <= right; ++i) {
				int idx = vec[i];
				if ((people[idx][1] <  people[left_idx][1]) ||
					((people[idx][1] == people[left_idx][1]) &&
					 (people[idx][0] <  people[left_idx][0]))) {
					++j;
					k = vec[i];
					vec[i] = vec[j];
					vec[j] = k;
				}
			}

			k = vec[left];
			vec[left] = vec[j];
			vec[j] = k;

			quick_sort(people, vec, left, j - 1);
			quick_sort(people, vec, j + 1, right);
		}
	}

public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		queue<int> q;
		list<int> buf;
		vector<int> vec;
		vector<vector<int> > ret;

		for (int i = 0; i < people.size(); ++i) {
			vec.push_back(i);
		}

		quick_sort(people, vec, 0, people.size() - 1);

		for (int i = 0; i < vec.size(); ++i) {
			if (people[vec[i]][1] == 0) {
				buf.push_back(vec[i]);
			} else {
				q.push(vec[i]);
			}
		}

		while (!q.empty()) {
			int idx = q.front();
			int cnt = 0;
			list<int>::iterator iter;
			q.pop();

			for (iter = buf.begin(); iter != buf.end(); ++iter) {
				if (people[*iter][0] >= people[idx][0]) {
					++cnt;
				}
				if (cnt > people[idx][1]) {
					break;
				}
			}

			buf.insert(iter, idx);
		}

		for (list<int>::iterator iter = buf.begin(); iter != buf.end(); ++iter) {
			ret.push_back(people[*iter]);
		}

		return ret;
	}
};
