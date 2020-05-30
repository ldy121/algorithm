class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		vector<bool> visit(rooms.size(), false);
		queue<int> q;

		for (q.push(0); !q.empty();) {
			int room = q.front();
			q.pop();

			if (visit[room] == false) {
				visit[room] = true;
				for (int i = 0; i < rooms[room].size(); ++i) {
					q.push(rooms[room][i]);
				}
			}
		}

		for (int i = 0; i < visit.size(); ++i) {
			if (visit[i] == false) {
				return false;
			}
		}
		return true;
	}
};
