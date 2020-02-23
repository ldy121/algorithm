class Solution {
public:
	void qsort(vector<int>& groups, vector<int>& ids, int left, int right)
	{
		if (left < right) {
			int i, j, k;
			for (i = left + 1, j = left; i <= right; ++i) {
				if (groups[ids[i]] < groups[ids[left]]) {
					++j;
					k = ids[i];
					ids[i] = ids[j];
					ids[j] = k;
				}
			}
            
			k = ids[left];
			ids[left] = ids[j];
			ids[j] = k;
            
			qsort(groups, ids, left, j - 1);
			qsort(groups, ids, j + 1, right);
		}
	}

	vector<vector<int> > groupThePeople(vector<int>& groupSizes) {
		vector<int> ids;
		vector<vector<int> > ret;

		for (int i = 0; i < groupSizes.size(); ++i) {
			ids.push_back(i);
		}

		qsort(groupSizes, ids, 0, groupSizes.size() - 1);

		vector<int> vec;

		for (int i = 0; i < ids.size(); ++i) {
			vec.push_back(ids[i]);
			if (vec.size() == groupSizes[ids[i]]) {
				ret.push_back(vec);
				vec.clear();
			}
		}
		return ret;
	}
};
