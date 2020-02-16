// Complete the countingValleys function below.
int countingValleys(int n, string s) {
 	int ret = 0, current = 0;

	for (int i = 0; i < n; ++i) {
		if ((current == 0) && (s[i] == 'D')) {
			++ret;
		}

		if (s[i] == 'D') --current;
		else             ++current;
	}

	return ret;
}
