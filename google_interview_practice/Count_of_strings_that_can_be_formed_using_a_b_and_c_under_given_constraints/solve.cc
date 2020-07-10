#include <iostream>
using namespace std;

inline int only_A(int N) {
    return 1;
}

inline int one_B(int N) {
    return N;
}

inline int one_C(int N) {
    return N;
}

inline int BC(int N) {
    return N * (N - 1) / 2 * 2;
}

inline int CC(int N) {
    return N * (N - 1) / 2;
}

inline int BCC(int N) {
    return N * (N - 1) * (N - 2) / 3 / 2 * 3;
}

int main() {
	int N, T;
	for (cin >> T; T > 0; --T) {
	    cin >> N;
	    cout << (only_A(N) + one_B(N) + one_C(N) + BC(N) + CC(N) + BCC(N)) << endl;
	}
	return 0;
}
