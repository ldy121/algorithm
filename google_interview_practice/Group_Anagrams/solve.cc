class Solution {
private :
	const int tableSize = 26;
	const int done = -1;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int> > table;
        vector<vector<string> > ret;
        for (int i = 0; i < strs.size(); ++i) {
            vector<int> vec(tableSize, 0);
            for (int j = 0; j < strs[i].length(); ++j) {
                ++vec[strs[i][j] - 'a'];
            }
            table.push_back(vec);
        }

	    for (int i = 0; i < strs.size(); ++i) {
		    if (table[i][0] == done) {
    			continue;
	    	}
		    vector<string> vec;
		    for (int j = i + 1; j < strs.size(); ++j) {
			    int k = 0;
			    if (table[j][0] == done) {
    				continue;
	    		}
    			for (k = 0; k < tableSize; ++k) {
	    			if (table[i][k] != table[j][k]) {
		    			break;
			    	}
			    }
			    if (k == tableSize) {
				    vec.push_back(strs[j]);
				    table[j][0] = done;
			    }
		    }
		    vec.push_back(strs[i]);
		    table[i][0] = done;
		    ret.push_back(vec);
	    }
	    return ret;
    }
};

