// 풀이방법
// 1. histogram을 생성
// 2. 홀수인 histogram에서 한글자씩만 활용해서 Palindrome String을 생성한다고 가정
// 3. 모든 histogram이 짝수로만 구성되거나 또는 k개 만큼 Palidrome String이 만들어 질 수 있음
// 4. 만약 이미 k개의 Palidrome String 의 만들어진 경우라면 홀수의 histogram만 없으면 됨
//    => 왜냐하면 짝수의 histogram은 홀수 histogram에 병합되어 Palidrome String으로 만들어질 수 있기 때문
//    => s = 'aab' k = 1 인 경우 이미 b histogram에 의해 Palidrome String을 만들어지게 된다. 하지만 aa는 
//       b 에 병합되어 aba 로 만들어질 수 있기 때문에 aa histogram이 남아도 Palidrome String을 만들 수 있게 됨
// 5. 만약 홀수개의 histogram이 없고 모두 짝수로 된 histogram이 남은 경우라면 맏늘어야 할
//    Palidrome String의 개수만큼의 문자열만 남으면 어떻게든 필요한 Parlidrome String 생성 가능
//    => aaaa 가 있고 3개를 만들어야 한다면 a, a, aa 이렇게 3개로 나눌 수 있고,
//    => 1개 라면 aaaa, 2개 라면 aa aa, 3개라면 a a aa 4개라면 a a a a 이렇게 만들 수 있게 된다.

class Solution {
private :
	const int c_hashSize = 26;
	const int c_init = 0;

public:
	bool canConstruct(string s, int k) {
		vector<int> hash(c_hashSize, c_init);
		int cnt, sum = 0, odd = 0;

		for (int i = 0; i < s.length(); ++i) {
			++hash[s[i] - 'a'];
		}

		for (cnt = k; cnt > 0; --cnt) {
			int j;

			for (j = 0; j < c_hashSize; ++j) {
				if ((hash[j] % 2) == 1) {
					break;
				}
			}

			if (j < c_hashSize) {
				--hash[j];
			} else {
				break;
			}
		}

		for (int i = 0; i < c_hashSize; ++i) {
			sum += hash[i];
			if ((hash[i] % 2) == 1) {
				++odd;
			}
		}

		return (((cnt == 0) && (odd == 0)) || ((cnt > 0) && (sum >= cnt)));
	}
};
