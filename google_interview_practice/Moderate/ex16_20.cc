#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> answer;

void getWord(unordered_map<int, vector<char> > &hash, string &input, string str, int idx) {
	if (idx < input.length()) {
		int num = input[idx] - '0';
		if (hash[num].size() == 0) {
  		getWord(hash, input, str, idx + 1);
		} else {
  		for (int i = 0; i < hash[num].size(); ++i) {
  			getWord(hash, input, str + hash[num][i], idx + 1);
  		}
		}
	} else {
		answer.push_back(str);
	}
}

int main(void) {
	unordered_map<int, vector<char> > hash;
	hash[0] = vector<char> (); 
	hash[1] = vector<char> ();
	hash[2] = vector<char> {'a', 'b', 'c'};
	hash[3] = vector<char> {'d', 'e', 'f'};
	hash[4] = vector<char> {'g', 'h', 'i'};
	hash[5] = vector<char> {'j', 'k', 'l'};
	hash[6] = vector<char> {'m', 'n', 'o'};
	hash[7] = vector<char> {'p', 'q', 'r', 's'};
	hash[8] = vector<char> {'t', 'u', 'v'};
	hash[9] = vector<char> {'w', 'x', 'y', 'z'};
	string input = "8733";

	getWord(hash, input, string(), 0);
	for (int i = 0; i < answer.size(); ++i) {
		cout << answer[i] << ' ';
	}
	cout << endl;

	return 0;
}

