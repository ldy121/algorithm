// Complete the numberPairs function below.
int numberPairs(int n, vector<int> ar) {
 	unordered_map<int, int> hash;
	int ret = 0;

	for (int i = 0; i < n; ++i) {
		if (hash.find(ar[i]) == hash.end()) {
			hash[ar[i]] = 1;
		} else {
			if (++hash[ar[i]] == 2) {
				++ret;
				hash[ar[i]] = 0;
			}
		}
	}

	return ret;
}
