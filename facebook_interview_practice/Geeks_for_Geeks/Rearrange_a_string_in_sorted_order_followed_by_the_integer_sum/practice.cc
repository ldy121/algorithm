#include <string>
#include <iostream>
#include <vector>

using namespace std;

string arrangeString(string&str)
{
	vector<int> count_map(26, 0);
	string ret;
	int sum = 0;

	for (int i = 0; i < str.length(); ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			++count_map[str[i] - 'A'];
		} else {
			sum += (str[i] - '0');
		}
	}

	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < count_map[i]; ++j) {
			ret += ('A' + i);
		}
	}

	ret += to_string(sum);

	return ret;
}

// Driver program 
int main() 
{ 
	string str = "ACCBA10D2EW30"; 
	cout << arrangeString(str) << endl; 
	return 0; 
} 
