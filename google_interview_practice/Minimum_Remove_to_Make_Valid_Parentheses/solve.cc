class Solution {
private :
	const char invalid = '^';
public:
    string minRemoveToMakeValid(string s) {
	    string ret;
	    stack<int> sp;
	    for (int i = 0; i < s.length(); ++i) {
		    if (s[i] == '(') {
	    		sp.push(i);
    		} else if (s[i] == ')') {
		    	if (sp.empty()) {
	    			s[i] = invalid;
    			} else {
			    	sp.pop();
		    	}
	    	}
    	}
    	while (!sp.empty()) {
    		s[sp.top()] = invalid;
	    	sp.pop();
    	}
    	for (int i = 0; i < s.length(); ++i) {
    		if (s[i] != invalid) {
    		    ret.append(1, s[i]);
	        }
    	}
    	return ret;
    }
};

