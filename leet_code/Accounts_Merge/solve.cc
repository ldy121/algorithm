class Solution {
private :
    const int invalid = -1;
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> buffer;
        vector<vector<string>> answer;
        vector<int> sets(accounts.size(), invalid);
        map<string, int> table;

        for (int i = 0; i < accounts.size(); ++i) {
            vector<string> vec;

            vec.push_back(accounts[i][0]);
            buffer.push_back(vec);

            for (int j = 1; j < accounts[i].size(); ++j) {
                if (table.find(accounts[i][j]) != table.end()) {
                    for (int k = table[accounts[i][j]]; k != invalid;) {
                        if (k == i) {
                            break;
                        }

                        int next = sets[k];
                        sets[k] = i;
                        k = next;
                    }
                }
                table[accounts[i][j]] = i;
            }
        }
        
        for (map<string, int>::iterator iter = table.begin(); iter != table.end(); ++iter) {
            int idx = iter->second;
            while (sets[idx] != invalid) {
                idx = sets[idx];
            }
            buffer[idx].push_back(iter->first);
        }

        for (int i = 0; i < buffer.size(); ++i) {
            if (buffer[i].size() > 1) {
                answer.push_back(buffer[i]);
            }
        }
        
        return answer;
    }
};
