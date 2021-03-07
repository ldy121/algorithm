class Solution {
private :
    void qsort(unordered_map<char, long long> &hash, vector<char> &key, int left, int right) {
        if (left < right) {
            int i, j;
            char k;
            for (i = left + 1, j = left; i <= right; ++i) {
                if ((hash[key[i]] > hash[key[left]]) ||
                   ((hash[key[i]] == hash[key[left]]) && (key[i] < key[left]))) {
                    ++j;
                    k = key[j];
                    key[j] = key[i];
                    key[i] = k;
                }
            }
            
            k = key[j];
            key[j] = key[left];
            key[left] = k;

            qsort(hash, key, left, j - 1);
            qsort(hash, key, j + 1, right);
        }        
    }

public:
    string rankTeams(vector<string>& votes) {
        unordered_map<char, long long> hash;
        vector<char> key;
        string ret;
        
        for (int j = 0; ret.length() < votes[0].length() && j < votes[0].length(); ++j) {
            for (int i = 0; i < votes.size(); ++i) {
                char ch = votes[i][j];
                if (hash.find(ch) == hash.end()) {
                    key.push_back(ch);
                    hash[ch] = 0;
                }
                
                if (hash[ch] >= 0) {
                    ++hash[ch];
                }
            }
            vector<char> vec;

            for (int i = 0; i < key.size(); ++i) {
                if (hash[key[i]] > 0) {
                    vec.push_back(key[i]);
                }
            }

            qsort(hash, vec, 0, vec.size() - 1);
            
            int k;
            for (k = 0; k + 1 < vec.size(); ++k) {
                if (hash[vec[k]] == hash[vec[k + 1]]) {
                    break;
                }
                ret += vec[k];
                hash[vec[k]] = -1;
            }

            if (k + 1 == vec.size()) {
                ret += vec[k];
                hash[vec[k]] = -1;
            } else {
                while (k < vec.size()) {
                    hash[vec[k]] *= votes.size();
                    ++k;
                }
            }
        }

        vector<char> v;

        for (int i = 0; i < key.size(); ++i) {
            if (hash[key[i]] > 0) {
                    v.push_back(key[i]);
            }
        }
        qsort(hash, v, 0, v.size() - 1);
        
        for (int i = 0; i < v.size(); ++i) {
            ret += v[i];
        }

        return ret;
    }
};
