long repeatedString(string s, long n) {
 	long ret = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'a') ++ret;
	}
	ret = ret * (n / s.length());
	for (int i = 0; i < (n % s.length()); ++i) {
		if (s[i] == 'a') ++ ret;
	}
	return ret;
}
