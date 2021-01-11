#include <string>
#include <iostream>

using namespace std;

int get_answer(string str)
{
	int answer = 0;

	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '1') {
			++answer;
		}
	}

	return (answer * (answer - 1)) / 2;
}

int main(void)
{
	cout << get_answer("00100101") << endl;
}