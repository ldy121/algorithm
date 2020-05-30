/*
   풀이방법

   이 문제는 특정한 규칙이 있다.
   아래 패턴을 한번 보도록 하자.
   N
   1 -> 1
   2 -> 1, 2
   3 -> 1, 3, 2
   4 -> 1, 3, 2, 4
   5 -> 1, 5, 3, 2, 4
   6 -> 1, 5, 3, 2, 6, 4
   7 -> 1, 7, 3, 5, 2, 6, 4
   8 -> 1, 7, 3, 5, 2, 8, 4, 6

   다음과 같은 규칙을 보면
   [5] => [3], [2] 로 구성되는 패턴이
   [6] => [3], [3]으로 구성되는 패턴
   [7] => [4], [3]으로 구성되고
   [8] => [4], [4]로 구성된다.

   [5]를 예를 들면 정답은 1,5,3,2,4 이다.
   이때 [3]은 왼쪽에 해당되는 1,5,3 이고, [2]는 2,4이다.
   그리고 [3]은 정답 N이 3일 때 1,3,2에 매핑되는데, 그 부분은
   홀수를 우선순위대로 배치하는 거다.
   즉 1,3,2 배치를 홀수의 크기 순서로 생각하면 1,5,3이 된다.
   [2]도 마찬가지로 N이 2일때 1,2로 매핑되는데 그 부분을
   짝수 우선순위대로 배치하는거다. 그러면 1,2 가 2,4로 매핑된다.
   즉 왼쪽은 홀수로 오른쪽은 짝수로 치환시키는 방식으로
   이전 N에 적용된 값을 각 수의 크기에 딸 배치로 생각하면
   일정한 패턴이 나오고 그런 식으로 문제를 해결하면 된다.
*/

class Solution {
private :
	unordered_map<int, vector<int> > m_hash;
	vector<int> getAnswer(int n) {
		if (m_hash.find(n) != m_hash.end()) {
			return m_hash[n];
		}

		m_hash[n] = vector<int>();
		vector<int> left = getAnswer((n + 1) / 2);
		for (int i = 0; i < left.size(); ++i) {
			m_hash[n].push_back(2 * left[i] - 1);
		}
		vector<int> right = getAnswer(n / 2);
		for (int i = 0; i < right.size(); ++i) {
			m_hash[n].push_back(2 * right[i]);
		}
		return m_hash[n];
	}

public:
	vector<int> beautifulArray(int N) {
		m_hash[1] = vector<int>(1, 1);
		return getAnswer(N);
	}
};
