#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void SumSwap(vector<int> a, vector<int> b) {
	int sumA = 0;
	int sumB = 0;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < a.size(); ++i) {
		sumA += a[i];
	}

	for (int i = 0; i < b.size(); ++i) {
		sumB += b[i];
	}

  int i, j;
	for (i = 0, j = 0; i < a.size() && j < b.size();) {
		int newSumA = sumA - a[i] + b[j];
		int newSumB = sumB + a[i] - b[j];
		if (newSumA < newSumB) {
			++j;
		} else if (newSumA > newSumB) {
			++i;
		} else {
			break;
		}
	}

	if (i < a.size() && j < b.size()) {
		cout << a[i]  << ", " << b[j] << endl;
	}
}


int main(void) {
	vector<int> A({4, 1, 2, 1, 1, 2});
	vector<int> B({3, 6, 3, 3});
	SumSwap(A, B);
	return 0;
}

