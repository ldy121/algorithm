class Solution {
public:
    vector<int> closestDivisors(int num) {
        int min = num + 3, a, b;
        vector<int> ret;
        for (int i = 1; i <= 2; ++i) {
            int n = num + i;
            for (int j = 1; j * j <= n; ++j) {
                if ((n % j) > 0) {
                    continue;
                }
                if (((n / j) - j) < min) {
                    min = (n / j) - j;
                    a = n / j;
                    b = j;
                }
            }
        }
        ret.push_back(a);
        ret.push_back(b);
        return ret;
    }
};
