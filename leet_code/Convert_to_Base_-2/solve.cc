// 풀이방법
// 각 bit에 대해서 upper bound와 lower bound를 정하고 그 범위에 속하면 1 아니면 0
// upper bound는 현재 값 + low bit의 postive 값의 합
// lower bound는 현재 값 + low bit의 negative 값의 합

// 해당 비트의 값이 설정되고 나머지 low bit들을 활용해서 최소 값/최대 값을 더해서
// 그 값을 표현할 수 있다는 전재가 되기 때문에 upper bound/lower bound로 해결 가능하다.

// 예를 들면
//            4bit 3bit  2bit 1bit 0bit
// val :       16   -8    4    -2    1
// upper :     21   -3    5    -1    1
// lower :      6   -9    2    -2    0

// N = 7 이라고 가정하면
// 4bit : 21 >=  7 >=  6   이기 때문에 [4] : 1 이 됨 4bit가 1이 되므로 7 - 16 => -9
// 3bit : -3 >= -9 >= -9   이기 때문에 [3] : 1 이 됨 3bit가 1이 되므로 -9 - -8 => -1
// 2bit :  4 >=    >=  2   이기 때문에 [2] : 0 이 됨 (-1 값은 다음 low bit로 전파)
// 1bit : -1 >= -1 >= -2   이기 때문에 [1] : 1 이 됨 1bit가 1이 되므로 -1 - -2 => 1
// 0bit :  1 >=  1 >=  0   이기 때문에 [0] : 1 이 됨 1bit가 1이 되므로 1 - 1 => 0
// 즉 성립하게 된다.
// 16 + -8 + -2 + 1 => 7


class Solution {
public:
	string baseNeg2(int N) {
		const int c_max = 40;
		vector<long long> upperBound;
		vector<long long> lowerBound;
		vector<long long> value;
		long long positiveSum = 0, negativeSum = 0, val = 1;
		int bit;
		string answer;

		if (N == 0) {
			return "0";
		}

		for (int i = 0; i < c_max; ++i) {
			upperBound.push_back(val + positiveSum);
			lowerBound.push_back(val + negativeSum);
			value.push_back(val);
			if (val > 0) {
				positiveSum += val;
			} else {
				negativeSum += val;
			}
			val *= -2;
		}

		for (bit = c_max - 1; bit >= 0; --bit) {
			if (upperBound[bit] >= N && N >= lowerBound[bit]) {
				break;
			}
		}

		while (bit >= 0) {
			if (upperBound[bit] >= N && N >= lowerBound[bit]) {
				N -= value[bit];
				answer += '1';
			} else {
				answer += '0';
			}
			--bit;
		}

		return answer;
	}
};
