/*
   Solution
   	A : 0 / B : 0 => XOR(A,B) = 0
   	A : 0 / B : 1 => XOR(A,B) = 1
   	A : 1 / B : 0 => XOR(A,B) = 1
   	A : 1 / B : 1 => XOR(A,B) = 0

	XOR(A,B) : 0 / A : 0 => XOR(XOR(A,B),A) - B : 0
	XOR(A,B) : 1 / A : 0 => XOR(XOR(A,B),A) - B : 1
	XOR(A,B) : 1 / A : 1 => XOR(XOR(A,B),A) - B : 0
	XOR(A,B) : 0 / A : 1 => XOR(XOR(A,B),A) - B : 1

	XOR(XOR(A,B),B) => A
	XOR(XOR(A,B),A) => B
*/
class Solution {
public:
	vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
		vector<int> ret;
		vector<int> xor_list;

		xor_list.push_back(arr[0]);

		for (int val = arr[0], i = 1; i < arr.size(); ++i) {
			val ^= arr[i];
			xor_list.push_back(val);
		}

		for (int i = 0; i < queries.size(); ++i) {
			int src = queries[i][0];
			int dst = queries[i][1];

			if (src == 0) {
				ret.push_back(xor_list[dst]);
			} else {
				ret.push_back(xor_list[src - 1] ^ xor_list[dst]);
			}
		}
		return ret;
	}
};
