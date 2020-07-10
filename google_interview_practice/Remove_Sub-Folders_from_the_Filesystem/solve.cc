class Solution {
private:
	bool isSubDirectory(string &parent, string &child) {
		int i;
		for (i = 0; i < parent.length() && i < child.length(); ++i) {
			if (parent[i] != child[i]) {
				return false;
			}
		}
		if (i == parent.length() && i == child.length()) {
			return true;
		}
		if (i == child.length()) {
			return false;
		}
		return child[i] == '/';
	}
public:
    vector<string> removeSubfolders(vector<string>& folder) {
	    vector<string> ret;
	    sort(folder.begin(), folder.end());

        for (int i = 0; i < folder.size();) {
            int j = i + 1;
            while (j < folder.size()) {
		        if (isSubDirectory(folder[i], folder[j])) {
	    		    ++j;
    		    } else {
        			break;
	    	    }
	        }
	        ret.push_back(folder[i]);
	        i = j;
        }
        return ret;
    }
};

