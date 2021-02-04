class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> table;
        unordered_map<int, vector<string> > answer;
        vector<string> tableKey;
        vector<string> ret;
        vector<int> answerKey;

        for (int i = 0; i < words.size(); ++i) {
            if (table.find(words[i]) == table.end()) {
                table[words[i]] = 0;
                tableKey.push_back(words[i]);
            }
            ++table[words[i]];
        }

        for (int i = 0; i < tableKey.size(); ++i) {
            int count = table[tableKey[i]];
            if (answer.find(count) == answer.end()) {
                answer[count] = vector<string>();
                answerKey.push_back(count);
            }
            answer[count].push_back(tableKey[i]);
        }
        
        sort(answerKey.begin(), answerKey.end());

        for (int i = answerKey.size() - 1, j = 0; j < k; --i) {
            int key = answerKey[i];
            sort(answer[key].begin(), answer[key].end());
            for (int t = 0; t < answer[key].size() && j < k; ++t) {
                ret.push_back(answer[key][t]);
                ++j;
            }
        }

        return ret;
    }
};
