#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void) {
	int T;
	for (cin >> T; T > 0; --T) {
		int K, k = 0, answer = -1, start = 0;
		string str;
		unordered_map<char, int> hash;

		cin >> str >> K;

		for (int i = 0; i < str.length(); ++i) {
      if (hash.find(str[i]) == hash.end()) {
				hash[str[i]] = -1;
			}

      if (hash[str[i]] == -1) {
				++k;
				for (int j = start; k > K; ++j) {
					if (hash[str[j]] == j) {
						--k;
						hash[str[j]] = -1;
						start = j + 1;
					}
				}
			}
		  hash[str[i]] = i;

			if (k == K && answer < (i - start + 1)) {
        answer = (i - start + 1);
			}
		}
    cout << answer << endl;
	}
	return 0;
}

