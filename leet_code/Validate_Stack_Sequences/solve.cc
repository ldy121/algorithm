class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> sp;
		int i = 0, j = 0;

		for (i = 0; i < pushed.size(); ++i) {
			sp.push(pushed[i]);
			while (j < popped.size() && !sp.empty()) {
				if (sp.top() == popped[j]) {
					sp.pop();                    
					++j;
				} else {
					break;
				}
			}
		}

		return (sp.empty() && i == pushed.size() && j == popped.size());
	}
};
