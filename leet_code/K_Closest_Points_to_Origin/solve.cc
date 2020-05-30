class Solution {
private :
	class comp {
		public :
			bool operator () (vector<int> a, vector<int> b) {
				return (((a[0] * a[0]) + (a[1] * a[1])) <
					((b[0] * b[0]) + (b[1] * b[1])));
			}
	};

public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		vector<vector<int> > ret;

		priority_queue<vector<int>, vector<vector<int> >, comp> q;

		for (int i = 0; i < points.size(); ++i) {
			if (q.size() < K) {
				q.push(points[i]);
			} else {
				int x = q.top()[0];
				int y = q.top()[1];
				int topDist = (x * x) + (y * y);
				int ptDist = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);

				if (ptDist < topDist) {
					q.pop();
					q.push(points[i]);
				}
			}
		}

		while (!q.empty()) {
			ret.push_back(q.top());
			q.pop();
		}

		return ret;
	}
};
