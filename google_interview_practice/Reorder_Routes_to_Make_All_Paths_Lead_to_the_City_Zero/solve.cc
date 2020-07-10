class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int> > src;
        vector<vector<int> > dst;
        vector<bool> done(n, false);
        queue<int> q;
	    int answer = 0;

        for (int i = 0; i < n; ++i) {
	        src.push_back(vector<int>());
	        dst.push_back(vector<int>());
        }
        for (int i = 0; i < connections.size(); ++i) {
	        int s = connections[i][0];
	        int d = connections[i][1];
	        src[s].push_back(d);
	        dst[d].push_back(s);
        }
        done[0] = true;
        for (q.push(0); !q.empty();) {
	        int size = q.size();
	        for (int i = 0; i < size; ++i) {
		        int pt = q.front();
		        q.pop();
		        for (int j = 0; j < src[pt].size(); ++j) {
                    if (done[src[pt][j]] == false) {
			            q.push(src[pt][j]);
			            ++answer;
                    }
                    done[src[pt][j]] = true;
		        }
		        for (int j = 0; j < dst[pt].size(); ++j) {
                    if (done[dst[pt][j]] == false) {
			            q.push(dst[pt][j]);
                    }
                    done[dst[pt][j]] = true;
		        }
	        }
        }
        return answer;
    }
};
