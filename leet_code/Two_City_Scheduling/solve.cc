class Solution {
private :
    void qsort(vector<vector<int>> &costs, vector<int> &vec, int left, int right) {
        if (left < right) {
            int i, j, k;
            int comp = (costs[vec[left]][0] > costs[vec[left]][1]) ?
                (costs[vec[left]][0] - costs[vec[left]][1]) : (costs[vec[left]][1] - costs[vec[left]][0]);

            for (i = left + 1, j = left; i <= right; ++i) {
                int tmp = (costs[vec[i]][0] > costs[vec[i]][1]) ?
                    (costs[vec[i]][0] - costs[vec[i]][1]) : (costs[vec[i]][1] - costs[vec[i]][0]);
                if (comp < tmp) {
                    ++j;
                    k = vec[i];
                    vec[i] = vec[j];
                    vec[j] = k;
                }
            }
            
            k = vec[left];
            vec[left] = vec[j];
            vec[j] = k;
            
            qsort(costs, vec, left, j - 1);
            qsort(costs, vec, j + 1, right);
        }
    }

public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> vec;
        int a = 0, b = 0, answer = 0;
        for (int i = 0; i < costs.size(); ++i) {
            vec.push_back(i);
        }

        qsort(costs, vec, 0, costs.size() - 1);
        
        for (int i = 0; i < costs.size(); ++i) {
            int idx = vec[i];
            if (a == costs.size() / 2) {
                ++b;
                answer += costs[idx][1];
                continue;
            }
            if (b == costs.size() / 2) {
                ++a;
                answer += costs[idx][0];
                continue;
            }
            if (costs[idx][0] < costs[idx][1]) {
                ++a;
                answer += costs[idx][0];
            } else {
                ++b;
                answer += costs[idx][1];
            }
        }
        return answer;
    }
};
