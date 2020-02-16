#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> answer;

string get_answer(int n)
{
	if (answer.size() < n) {
		for (int i = answer.size() - 1; i < n; ++i) {
			string str = answer[i];
			string val;
			for (int j = 0; j < str.length();) {
				int k = j + 1;
				while (str[j] == str[k]) ++k;
				val += to_string(k - j);
				val += str[j];
				j = k;
			}
			answer.push_back(val);
		}
	}
	return answer[n - 1];
}

int main(void)
{
	answer.push_back(string("1"));
	for (int i = 1; i < 10; ++i) {
		cout << get_answer(i) << endl;
	}
}
