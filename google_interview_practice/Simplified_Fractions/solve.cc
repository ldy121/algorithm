class Solution {
private :
	bool isFraction(int up, int down) {
		for (int i = 2; i <= up; ++i) {
			if ((up % i == 0) && (down % i == 0)) {
				return false;
			}
		}
		return true;
	}
    string intToString(int val) {
        stack<char> sp;
        string ret;
        while (val > 0) {
            sp.push((val % 10) + '0');
            val /= 10;
        }
        while (!sp.empty()) {
            ret.append(1, sp.top());
            sp.pop();
        }
        return ret;
    }
	string getFraction(int up, int down) {
		string ret;
        
        ret += intToString(up);
		ret.append(1, '/');
		ret += intToString(down);
		return ret;
	}
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ret;
        for (int i = 2; i <= n; ++i) {
	        ret.push_back(getFraction(1, i));
	        for (int j = 2; j < i; ++j) {
		        if (isFraction(j, i)) {
			        ret.push_back(getFraction(j, i));
		        }
	        }
        }
        return ret;
    }
};

