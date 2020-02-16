// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    vector<bool> hash(26, 0);
    for (int i = 0; i < s1.size(); ++i) {
        hash[s1[i] - 'a'] = true;
    }

    for (int i = 0; i < s2.size(); ++i) {
        if (hash[s2[i] - 'a']) {
            return string("YES");
        }
    }
    return string("NO");
}
