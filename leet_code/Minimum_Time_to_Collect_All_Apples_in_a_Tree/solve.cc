class Solution {
private :
	vector<bool> m_visit;

	int getAnswer(int idx, unordered_map<int, vector<int> >& graph, vector<bool>& hasApple) {
		int ret = 0;

		if (m_visit[idx]) {
			return 0;
		} else {
			m_visit[idx] = true;
		}

		for (int i = 0; i < graph[idx].size(); ++i) {
			ret += getAnswer(graph[idx][i], graph, hasApple);
		}

		if (ret > 0 || hasApple[idx]) {
			ret += 2;
		}

		return ret;
	}

public:
	int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
		unordered_map<int, vector<int> > graph;
		int answer = 0;

		for (int i = 0; i < n; ++i) {
			graph[i] = vector<int>();
			m_visit.push_back(false);            
		}

		for (int i = 0; i < edges.size(); ++i) {
			graph[edges[i][0]].push_back(edges[i][1]);
			graph[edges[i][1]].push_back(edges[i][0]);
		}

		answer = getAnswer(0, graph, hasApple);
		return (answer > 0) ? (answer - 2) : 0;
	}
};
