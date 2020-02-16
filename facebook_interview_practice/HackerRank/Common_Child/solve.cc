// Complete the commonChild function below.

int get_answer(vector< vector<int> >&dp, string &s1, string &s2, int idx1, int idx2)
{
    if (dp[idx1][idx2] == -1) {
        if (s1[idx1] == s2[idx2]) {
            dp[idx1][idx2] = ((idx1 + 1) < s1.length() && (idx2 + 1) < s2.length()) ? 
                (get_answer(dp, s1, s2, idx1 + 1, idx2 + 1) + 1) : 1;
        } else {
            int ret1 = 0, ret2 = 0;
            if ((idx1 + 1) < s1.length()) {
                ret1 = get_answer(dp, s1, s2, idx1 + 1, idx2);
            }
            if ((idx2 + 1) < s2.length()) {
                ret2 = get_answer(dp, s1, s2, idx1, idx2 + 1);
            }
            dp[idx1][idx2] = (ret1 > ret2) ? ret1 : ret2;
        }
    }

    return dp[idx1][idx2];
}

int commonChild(string s1, string s2) {
    vector<vector <int> > dp;
    for (int i = 0; i < s1.length(); ++i) {
        vector<int> vec(s2.length(), -1);
        dp.push_back(vec);
    }
    return get_answer(dp, s1, s2, 0, 0);
}
