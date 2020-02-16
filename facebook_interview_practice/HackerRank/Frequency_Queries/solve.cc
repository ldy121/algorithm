// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    vector<int> ret;
    unordered_map<int, int> key_hash;
    unordered_multimap<int, int> freq_hash;

    for (int i = 0; i < queries.size(); ++i) {
        int cmd = queries[i][0];
        int val = queries[i][1];

        if (cmd == 1 || cmd == 2) {
            if ((key_hash.find(val) != key_hash.end()) &&
                (freq_hash.find(key_hash[val]) != freq_hash.end())) {
                pair<unordered_multimap<int, int>::iterator, unordered_multimap<int, int>::iterator>
                         equal_pair = freq_hash.equal_range(key_hash[val]);
                for (unordered_multimap<int, int>::iterator iter = equal_pair.first;
                    iter != equal_pair.second; ++iter) {
                    if (iter->second == val) {
                        freq_hash.erase(iter);
                        break;
                    }
                }
            }

            switch(cmd) {
            case 1:
                if (key_hash.find(val) == key_hash.end()) {
                    key_hash[val] = 1;
                } else {
                    ++key_hash[val];
                }

                break;
            case 2:
                if (key_hash.find(val) != key_hash.end()) {
                    if (key_hash[val] > 0) {
                        --key_hash[val];
                    }
                }
                break;
            }

            if (key_hash.find(val) != key_hash.end()) {
                freq_hash.insert(make_pair(key_hash[val], val));
            }
        } else {
            if (freq_hash.find(val) == freq_hash.end()) {
                ret.push_back(0);
            } else {
                ret.push_back(1);
            }
        }
    }

    return ret;
}
