class Solution {
public:
	void dfs(vector<vector<int> > &result, vector<vector<int> > &graph, vector<int> &vec, int idx) {
		if (idx == (graph.size() - 1)) {
			result.push_back(vec);
		} else {
			for (int i = 0; i < graph[idx].size(); ++i) {
				vec.push_back(graph[idx][i]);
				dfs(result, graph, vec, graph[idx][i]);
				vec.pop_back();
			}
		}
	}

	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<vector<int> > ret;
		vector<int> vec;

		vec.push_back(0);
		dfs(ret, graph, vec, 0);

		return ret;
	}
};
