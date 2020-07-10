1. You are given a string input that consists of characters from an alphabet = {'A', 'B', 'C', 'D', 'E'}.
	 Write a function that returns the first index i, such that input[i]...input[i+4] forms a permutation of all letters of this alphabet.
	 eg. If input="BACDCBAEDC", i = 3

The function will return -1 if there is no such substring.
 01234
 BACDCECBAED
A01111000111 
B11110001111
C00112222111
D00011110001
E00000111111

int getAnswer(string input) {
	vector<int> table(5, 0);
	int ret = -1;
	for (int i = 0; i < input.length(); ++i) {
		int ch = input[i] - ‘A’;
		int j;
		++table[ch];
		for (j = 0; j < table.size(); ++j) {
			if (table[j] != 1) {
				break;
			}
		}
		if (j == table.size()) {
			ret = i - table.size() + 1;
			break;
		}
		if ((i - (table.size() - 1)) >= 0) {
			char tmp = input[i - (table.size() - 1)];
			--table[tmp];
		}
	}

	return ret;
}

BACDCECBAED
O(N.A)


