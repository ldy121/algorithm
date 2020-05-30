class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		stack<int> sp;
		vector<int> ret;

		sp.push(0);
		ret.push_back(0);

		for (int i = 1; i < T.size(); ++i) {
			ret.push_back(0);
			while (sp.size() > 0 && T[sp.top()] < T[i]) {
				ret[sp.top()] = i - sp.top();
				sp.pop();
			}
			sp.push(i);
		}

		return ret;
	}
};
