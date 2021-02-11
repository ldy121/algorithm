class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int answer = 0, last = -1;

        for (int i = 0; i < timeSeries.size(); ++i) {
            if (last >= timeSeries[i]) {
                answer -= (last - timeSeries[i] + 1);
            }
            answer += duration;
            last = timeSeries[i] + (duration - 1);
        }

        return answer;
    }
};
