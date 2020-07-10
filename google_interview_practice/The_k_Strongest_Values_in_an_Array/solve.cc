class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int> ret;
        int m;

        sort(arr.begin(), arr.end());

        m = arr[(arr.size() - 1) / 2];
        for (int left = 0, right = arr.size() - 1; (left <= right) && ret.size() < k;) {
	        int l = m - arr[left];
	        int r = arr[right] - m;

	        if (r < 0) r *= -1;
	        if (l < 0) l *= -1;

	        if (l > r) ret.push_back(arr[left++]);
	        else ret.push_back(arr[right--]);
        }
        return ret;
    }
};


