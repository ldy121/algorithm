class Solution {
public:
    string removeDuplicates(string s, int k) {
	    string ret = s;
	    for (bool isDuplicate = true; isDuplicate;) {
    		string str = ret;
    		ret = "";
		    isDuplicate = false;
		    for (int i = 0; i < str.length();) {
			    string partial;
                int j;
			    for (j = i; j < str.length(); ++j) {
				    if (str[i] == str[j]) {
    					partial += str[i];
	    			} else {
		    			break;
			    	}
    				if (partial.length() == k) {
	    				partial = "";
                        isDuplicate = true;
		    			++j;
			    		break;
				    }
			    }
			    ret += partial;
			    i = j;
		    }
	    }
	    return ret;
    }
};


