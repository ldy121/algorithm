// Complete the abbreviation function below.
int isAbbreviation(vector<vector<int> >&dp, string& a, string& b, int idx_a, int idx_b)
{
    if (idx_b == b.length()) {
        int i;
        for (i = idx_a; i < a.length() && 'a' <= a[i] && a[i] <= 'z'; ++i);
        return (i == a.length());
    } else if (idx_a == a.length()) {
        return 0;
    } else if (dp[idx_a][idx_b] == -1) {
        if (a[idx_a] == b[idx_b]) {
            dp[idx_a][idx_b] = isAbbreviation(dp, a, b, idx_a + 1, idx_b + 1);
        } else if ('a' <= a[idx_a] && a[idx_a] <= 'z') {
            int val = 0;
            if ((a[idx_a] - 'a') == (b[idx_b] - 'A')) {
                val = isAbbreviation(dp, a, b, idx_a + 1, idx_b + 1);
            }
            if (val == 0) {
                dp[idx_a][idx_b] = isAbbreviation(dp, a, b, idx_a + 1, idx_b);
            } else {
                dp[idx_a][idx_b] = 1;
            }
        } else {
            dp[idx_a][idx_b] = 0;
        }
    }

    return dp[idx_a][idx_b];
}

string abbreviation(string a, string b) {
    vector <vector<int> > dp;

    for (int i = 0; i < a.length(); ++i) {
        vector<int> vec(b.length(), -1);
        dp.push_back(vec);
    }

    return (isAbbreviation(dp, a, b, 0, 0) > 0) ? string("YES") : string("NO");
}
