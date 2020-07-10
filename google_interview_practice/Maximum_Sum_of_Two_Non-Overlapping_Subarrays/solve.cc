class Solution {
private :
	const int invalid = -1;
	int pushq(queue<int> &q, vector<int> &A, int idx, int length, int sum) {
	    q.push(idx);
	    sum += A[idx];
	    while(q.size() > length) {
    		sum -= A[q.front()];
    		q.pop();
    	}
    		return sum;
	}

	int getMaxM(vector<int>& A, int startIgnore, int endIgnore, int M) {
		queue<int> q;
		int sum = 0, maxSum = 0;
		for (int i = 0; i < A.size(); ++i) {
			if (i >= startIgnore && i <= endIgnore) {
				continue;
			}

			sum = pushq(q, A, i, M, sum);
			if (maxSum < sum) {
				maxSum = sum;
			}
		}
		return maxSum;
	}
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int ret = 0;
        queue<int> q;
        int maxSum = 0, maxIdx = 0, maxM = 0, sum = 0;

        for (int i = 0; i < A.size(); ++i) {
	        sum = pushq(q, A, i, L, sum);
	        int mMax = getMaxM(A, q.front(), q.front() + L - 1, M);
	        if (mMax + sum > ret) {
		        ret = mMax + sum;
	        }
        }
        return ret;
    }
};



