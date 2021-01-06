class Solution {
public:
    int uniquePaths(int m, int n) {
        int ret = 1;
        int front = 0;
        vector<int> vec[2];

        for (int j = 0; j < m; ++j) {
            vec[0].push_back(1);
            vec[1].push_back(0);
        }

        for (int i = 1; i < n; ++i) {
            vector<int> &frontBuffer = vec[front];
            vector<int> &backBuffer= vec[!front];

            backBuffer[0] = 1;
            for (int j = 1; j < m; ++j) {
                backBuffer[j] = backBuffer[j - 1] + frontBuffer[j];
                if (ret < backBuffer[j]) {
                    ret = backBuffer[j];
                }
            }
            front = !front;
        }

        return ret;
    }
};
