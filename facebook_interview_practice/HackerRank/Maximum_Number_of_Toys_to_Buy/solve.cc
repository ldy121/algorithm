// Complete the maximumToys function below.
int maximumToys(vector<int> prices, int k) {
 	int i = 0, sum = 0;
	sort(prices.begin(), prices.end());
	for (i = 0, sum = 0; i < prices.size(); ++i) {
		if (sum + prices[i] <= k) {
			sum += prices[i];
		} else {
			break;
		}
	}
	return i;
}
