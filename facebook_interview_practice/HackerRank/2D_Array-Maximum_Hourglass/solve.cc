int hourglassSum(vector<vector<int>> arr) {
 	int ret = -99999999;
	for (int i = 2; i < arr.size(); ++i) {
		for (int j = 2; j < arr[i].size(); ++j) {
			int sum = arr[i][j - 1] + arr[i][j] + arr[i][j - 2] + arr[i - 1][j - 1] +
				arr[i - 2][j - 1] + arr[i - 2][j] + arr[i - 2][j - 2];
			if (sum > ret) ret = sum;
		}
	}
	return ret;
}
