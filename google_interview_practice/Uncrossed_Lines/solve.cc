class Solution {
private :
    const int invalid = -1;
    int getAnswer(vector<vector<int> > &answer, vector<int> &A, vector<int> &B, int idx, int left){
    	if (idx >= A.size() || left >= B.size()) {
    		return invalid;
    	}
    	if (answer[idx][left] != invalid) {
    		return answer[idx][left];
    	}
        int ret = 0;

        for (int i = left; i < B.size(); ++i) {
	        if (A[idx] == B[i]) {
		        int tmp = getAnswer(answer, A, B, idx + 1, i + 1);
		        ret = (tmp != invalid) ? (1 + tmp) : 1;
		        break;
	        }
        }

        int tmp = getAnswer(answer, A, B, idx + 1, left);
        if (ret < tmp) {
	        ret = tmp;
        }

        answer[idx][left] = ret;
        return ret;
    }
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int> > answer;
        for (int i = 0; i < A.size(); ++i) {
	        vector<int> vec(B.size(), invalid);
	        answer.push_back(vec);
        }
        return getAnswer(answer, A, B, 0, 0);
    }
};

