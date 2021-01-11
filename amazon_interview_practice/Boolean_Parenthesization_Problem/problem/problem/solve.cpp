#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int countParenth(char symb[], char oper[], int n)
{
	vector<vector<int> > answer[] = { vector<vector<int > >(n, vector<int>(n, 0)),
									vector<vector<int > >(n, vector<int>(n, 0)) };

	int ans = (symb[0] == 'T');

	for (int i = 0; i < n; ++i) {
		if (symb[i] == 'T') {
			answer[1][i][i] = 1;
			answer[0][i][i] = 0;
		} else {
			answer[1][i][i] = 0;
			answer[0][i][i] = 1;
		}

		if ((i + 1) < n) {
			int operand = (symb[i + 1] == 'T');

			switch (oper[i]) {
			case '|' :
				ans |= operand;
				break;
			case '&' :
				ans &= operand;
				break;
			default :
				ans ^= operand;
			}
		}
	}

	for (int size = 0; size < n; ++size) {
		for (int i = 0; i + size < n; ++i) {
			int j = i + size;
			for (int k = i; k < j; ++k) {
				if (oper[k] == '|') {
					answer[0][i][j] += (answer[0][i][k] * answer[0][k + 1][j]);
					answer[1][i][j] += (answer[0][i][k] * answer[1][k + 1][j]);
					answer[1][i][j] += (answer[1][i][k] * answer[0][k + 1][j]);
					answer[1][i][j] += (answer[1][i][k] * answer[1][k + 1][j]);
				}
				else if (oper[k] == '&') {
					answer[0][i][j] += (answer[0][i][k] * answer[0][k + 1][j]);
					answer[0][i][j] += (answer[0][i][k] * answer[1][k + 1][j]);
					answer[0][i][j] += (answer[1][i][k] * answer[0][k + 1][j]);
					answer[1][i][j] += (answer[1][i][k] * answer[1][k + 1][j]);
				}
				else {
					answer[0][i][j] += (answer[0][i][k] * answer[0][k + 1][j]);
					answer[1][i][j] += (answer[0][i][k] * answer[1][k + 1][j]);
					answer[1][i][j] += (answer[1][i][k] * answer[0][k + 1][j]);
					answer[0][i][j] += (answer[1][i][k] * answer[1][k + 1][j]);
				}
			}
		}
	}

	return answer[ans][0][n - 1];
}

// Driver program to test above function 
int main()
{
	char symbols[][5] = { "TFT", "TFF", "TTFT" };
	char operators[][4] = { "^&", "^|", "|&^" };
	

	// There are 4 ways 
	// ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)) 

	for (int i = 0; i < 3; ++i) {
		int n = strlen(symbols[i]);
		cout << countParenth(symbols[i], operators[i], n) << endl;
	}

	return 0;
}