#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<vector<int> > &A, int row, int col, int N) {
	int n = N - 1;
	for (int i = 0; i < n; ++i) {
		int tmp = A[row][col + i];
		A[row][col + i] = A[row + n - i][col];	// row+N-1, col => row, col + i
		A[row + n -i][col] = A[row + n][col + n - i];	// row+n,col+n-i => row+n-i,col
		A[row + n][col + n - i] = A[row + i][col + n];	// row+i,col+n => row+n, col+n-i
		A[row + i][col + n] = tmp;			// row, col+i => row+i, col+n
	}
}
int main() {
	int T;
	for (cin >> T; T > 0; --T) {
		int N;
		vector<vector<int> > A;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			vector<int> vec;
			for (int j = 0; j < N; ++j) {
				int val;
				cin >> val;
				vec.push_back(val);
			}
			A.push_back(vec);
		}
		
		int n = N;
		for (int i = 0; i < N / 2; ++i) {
			rotate(A, i, i, n);
			n -= 2;
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout << A[i][j] << ‘ ‘;
			}
		}
		cout << endl;
	}
	return 0;
}


