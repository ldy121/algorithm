// Driver program to test above function 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int get_answer(vector<int>&answer, char digits[], int idx, int n)
{
	if (answer[idx] == -1) {
		if ((idx + 1) < n) {
			int digit = (digits[idx] - '0') * 10 + (digits[idx + 1] - '0');
			answer[idx] = get_answer(answer, digits, idx + 1, n);
			if (digit <= 26) {
				if ((idx + 2) < n) {
					answer[idx] += get_answer(answer, digits, idx + 2, n);
				} else {
					++answer[idx];
				}
			}
		} else {
			answer[idx] = 1;
		}
	}
	return answer[idx];
}

int countDecoding(char digits[], int n)
{
	vector<int> answer(n, - 1);
	return get_answer(answer, digits, 0, n);
}

int main()
{
	char digits[] = "121";
	int n = strlen(digits);
	cout << "Count is " << countDecoding(digits, n);
	return 0;
}
// Modified by Atanu Sen 