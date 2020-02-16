#include <iostream>
#include <string>

using namespace std;

bool SecondComp(string s1, string s2, int s1_idx, int s2_idx)
{
	while (s1_idx < s1.length() && s2_idx < s2.length() && s1[s1_idx] == s2[s2_idx]) {
		++s1_idx;
		++s2_idx;
	}

	return s1_idx == s1.length() && s2_idx == s2.length();
}

bool OneEditApart(string s1, string s2)
{
	for (int i = 0; i < s1.length(); ++i) {
		if (s1[i] != s2[i]) {
			if (SecondComp(s1, s2, i + 1, i) ||
				SecondComp(s1, s2, i, i + 1)) {
				return true;
			} else {
				s1[i] = s2[i];
				return SecondComp(s1, s2, i, i);
			}
		}
	}
	return true;
}


int main(void) {
	cout << OneEditApart("cat", "dog") << endl;
	cout << OneEditApart("cat", "cats") << endl;
	cout << OneEditApart("cat", "cut") << endl;
	cout << OneEditApart("cat", "cast") << endl;
	cout << OneEditApart("cat", "at") << endl;
	cout << OneEditApart("cat", "act") << endl;
	return 0;
}
