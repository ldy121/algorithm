// Complete the substrCount function below.
long substrCount(int n, string s) {
    long ret = 0;
    int i, j;

    for (i = 0; i < n; i = j) {
        for (j = i; (j < n) && (s[i] == s[j]); ++j);
        long num = (j - i);
        ret += ((num + 1) * num / 2);
        for (int k = j + 1; (num > 0) && (k < n) && (s[i] == s[k]); ++k, --num) ++ret;
        cout << j << endl;
    }

    return ret;
}
