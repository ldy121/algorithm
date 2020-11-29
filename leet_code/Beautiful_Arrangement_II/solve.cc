// 규칙
/*
 1 7 2 6 3 5 4 (n = 7 / k = 6)
 1 7 2 6 3 4 5 (n = 7 / k = 5)
 1 7 2 6 5 4 3 (n = 7 / k = 4)
 1 7 2 3 4 5 6 (n = 7 / k = 3)
 1 7 6 5 4 3 2 (n = 7 / k = 2)
 1 2 3 4 5 6 7 (n = 7 / k = 1)
*/

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ret;
        int min = n, max = 0;
        for (int i = 0, j = 1, k = n - 1, sign = 1; i < n; ++i) {
            ret.push_back(j);
            j += (sign * k);
            --k;
            sign *= -1;
        }
        for (int i = k; i < n; ++i) {
            if (ret[i] > max) {
                max = ret[i];
            }
            if (ret[i] < min) {
                min = ret[i];
            }
        }
        if (ret[k - 1] > max) {
            for (int i = k, j = max; i < n; ++i, --j) {
                ret[i] = j;
            }     
        } else {
            for (int i = k, j = min; i < n; ++i, ++j) {
                ret[i] = j;
            }
        }
        return ret;
    }
};
