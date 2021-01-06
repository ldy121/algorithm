class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        vector<int> keys;
        unordered_map<int, int> edges;
        int width = 0, answer = 0;

        for (int i = 0; i < wall.size(); ++i) {
            int edge = 0;

            for (int j = 0; j < wall[i].size(); ++j) {
                edge += wall[i][j];
                
                if (edges.find(edge) == edges.end()) {
                    keys.push_back(edge);
                    edges[edge] = 0;
                }
                ++edges[edge];
            }

            width = edge;
        }

        for (int i = 0; i < keys.size(); ++i) {
            if (keys[i] == width) {
                continue;
            }

            if (edges[keys[i]] > answer) {
                answer = edges[keys[i]];
            }
        }
        
        return wall.size() - answer;
    }
};
