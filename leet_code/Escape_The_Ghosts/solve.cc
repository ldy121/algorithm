class Solution {
public:
	bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
		int dist = ((target[0] > 0) ? (target[0]) : (-target[0])) + ((target[1] > 0) ? (target[1]) : (-target[1]));
		for (int i = 0; i < ghosts.size(); ++i) {
			int x = (target[0] > ghosts[i][0]) ? (target[0] - ghosts[i][0]) : (ghosts[i][0] - target[0]);
			int y = (target[1] > ghosts[i][1]) ? (target[1] - ghosts[i][1]) : (ghosts[i][1] - target[1]);
			if (x + y <= dist) {
				return false;
			}
		}
		return true;
	}
};
