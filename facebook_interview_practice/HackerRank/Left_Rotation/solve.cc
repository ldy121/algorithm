vector<int> rotLeft(vector<int> a, int d) {
 	vector<int> ret;
	for (int i = d % a.size(), j = 0; j < a.size(); ++j, i = (i + 1) % a.size()) {
		ret.push_back(a[i]);
	}
	return ret;
}
