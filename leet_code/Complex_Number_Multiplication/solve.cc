class Solution {
private :
	int get_val(string input, int &idx) {
		int val = 0;
		int sign = 1;

		if (input[idx] == '-') {
			sign = -1;
			++idx;
		} else if (input[idx] == '+') {
			++idx;
		}

		while(input[idx] >= '0' && input[idx] <= '9') {
			val = val * 10 + (input[idx++] - '0');
		}
		return val * sign;
	}

public:
	string complexNumberMultiply(string a, string b) {
		int a_idx = 0, b_idx = 0;
		int aa, ab, ba, bb;
		int ret_a, ret_b;

		ostringstream output;

		aa = get_val(a, a_idx);
		ab = get_val(a, ++a_idx);
		ba = get_val(b, b_idx);
		bb = get_val(b, ++b_idx);

		ret_a = aa * ba - ab * bb;
		ret_b = aa * bb + ab * ba;

		output << ret_a << "+" << ret_b << "i";

		return output.str();
	}
};
