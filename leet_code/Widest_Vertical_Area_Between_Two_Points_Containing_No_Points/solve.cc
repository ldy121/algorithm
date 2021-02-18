class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> vec;
        int answer = -1;

        for (int i = 0; i < points.size(); ++i) {
            vec.push_back(points[i][0]);
        }
        sort(vec.begin(), vec.end());
        for (int i = 1; i < vec.size(); ++i) {
            int val = vec[i] - vec[i - 1];
            if (answer < val) {
                answer = val;
            }
        }
        
        return answer;
    }
};
