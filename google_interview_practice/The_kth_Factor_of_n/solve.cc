class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> low, high;
        for (int i = 1; i * i <= n; ++i) {
	        if (n % i == 0) {
		        low.push_back(i);
                if (i != n / i) {
		            high.push_back(n / i);
                }
	        }
	        if (low.size() == k) {
		        break;
	        }
        }
        
        if ((low.size() + high.size()) < k) {
            return -1;
        } else if (low.size() == k) {
            return low[low.size() - 1];
        } else {
            return high[high.size() - (k - low.size())];
        }
    }
};
