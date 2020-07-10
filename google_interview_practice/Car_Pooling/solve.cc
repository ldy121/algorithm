class Comp {
public :
	bool operator() (const vector<int>& a, const vector<int>& b) {
		return (a[2] > b[2]) || (a[2] == b[2] && a[1] > b[1]);
	}    
};

class Solution {
private :
	static bool startComp(vector<int> a, vector<int> b) {
		return (a[1] < b[1]) || (a[1] == b[1] && a[2] < b[2]);
	}

public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
	    priority_queue<vector<int>, vector<vector<int> >, Comp> q;
	    int sum = 0;

        sort(trips.begin(), trips.end(), Solution::startComp);

	    for (int i = 0; i < trips.size(); ++i) {
    		while (!q.empty()) {
    			const vector<int> &vec = q.top();
    			if (vec[2] <= trips[i][1]) {
    				sum -= vec[0];
        			q.pop();                    
		    	} else {
			    	break;
			    }
		    }
		    sum += trips[i][0];
		    q.push(trips[i]);

		    if (sum > capacity) {
			    return false;
		    }
	    }
	    return true;
    }
};


