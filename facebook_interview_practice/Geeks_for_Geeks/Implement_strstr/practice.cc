#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int get_strstr(string s, string n)
{
	int ret = -1;

	for (int idx = n.length() - 1; idx < s.length();) {
		int i, j;
		for (i = idx, j = n.length() - 1; (j >= 0) && (s[i] == n[j]); --i, --j);
		if (j >= 0) {
			while ((j >= 0) && (s[i] != n[j])) --j;
			idx += (n.length() - (j + 1));
		} else {
			ret = idx - n.length() + 1;
			break;
		}
	}

	return ret;
}

int main(void)
{
	int T;
	freopen("sample_input.txt", "r", stdin);
	setbuf(stdout, NULL);

	for (cin >> T; T > 0; --T) {
		string s, n;
		cin >> s >> n;
		cout << get_strstr(s, n) << endl;
	}

	return 0;
}
