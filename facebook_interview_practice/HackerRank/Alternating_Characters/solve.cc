int alternatingCharacters(string s) {
 	int ret = 0;
	for (int i = 1, j = 0; i < s.length(); ++i) {
		if (s[i] == s[j]) {
			++ret;
		} else {
			j = i;
		}
	}
	return ret;
}
