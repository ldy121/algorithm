class Solution {
private :
	const int invalid = -1;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, int> unionSet;
        vector<int> ret;
        for (int i = 0; i < edges.size(); ++i) {
	        int src = edges[i][0];
	        int dst = edges[i][1];
	        unionSet[src] = invalid;
            unionSet[dst] = invalid;
        }

        for (int i = 0; i < edges.size(); ++i) {
            int src = edges[i][0];
	        int dst = edges[i][1];
	        int j = src;
	        int k = dst;
	        for (; unionSet[j] != invalid; j = unionSet[j]);
	        for (; unionSet[k] != invalid; k = unionSet[k]);
	        if (j == k) {
		        ret.push_back(src);
		        ret.push_back(dst);
		        break;
	        }
	        unionSet[src] = k;
	        unionSet[j] = k;
        }
        return ret;
    }
};


