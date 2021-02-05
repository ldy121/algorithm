class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        queue<int> q;
        vector<int> answer(manager.size(), 0);
        
        if (n == 1) {
            return 0;
        }
        
        for (int i = 0; i < informTime.size(); ++i) {
            if (informTime[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            for (int size = q.size(); size > 0; --size) {
                int id = q.front();
                int parent = manager[id];
                int sum = answer[id] + informTime[parent];
                q.pop();

                if (sum > answer[parent]) {
                    answer[parent] = sum;
                } else {
                    continue;
                }
                
                if (parent != headID) {
                    q.push(parent);
                }
            }
        }
        
        return answer[headID];
    }
};
