class Solution {
private :
	const int invalid = -1;
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
	vector<int> answer;
	stack<int> sp;

	for (int j = 0; j < nums.size() * 2; ++j) {
		int i = j % nums.size();
		while (!sp.empty()) {
			if (nums[sp.top()] < nums[i]) {
				answer[sp.top()] = nums[i];
				sp.pop();
			} else {
				break;
			}
		}
		if (j < nums.size()) {
			answer.push_back(-1);
			sp.push(i);
		}
	}
	return answer;
    }
};

