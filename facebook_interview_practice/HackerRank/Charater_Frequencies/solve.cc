const int max_hash = 26;
// Complete the isValid function below.
string isValid(string s) {
    vector<int> hash(max_hash, 0);
    bool ans;
    int opt;
    for (int i = 0; i < s.length(); ++i) {
        ++hash[s[i] - 'a'];
    }
    sort(hash.begin(), hash.end());

    for (int i = 0; i < max_hash; ++i) {
        cout << hash[i] << " ";
    }
    cout << endl;

    if ((hash[max_hash - 2] == 0) || 
        (hash[max_hash - 1] == hash[max_hash - 2]) || 
        (hash[max_hash - 1] - 1 == hash[max_hash - 2])) {
        ans = true;
        opt = 1 - (hash[max_hash - 1] - hash[max_hash - 2]);
        for (int i = max_hash - 3; ans && i >= 0 && hash[i] > 0; --i) {
            if (hash[max_hash - 2] != hash[i]) {
                if ((hash[i] == 1) && (opt == 1)) {
                    --opt;
                } else {
                    ans = false;
                }
            }
        }
    } else {
        ans = false;
    }

    return (ans) ? string("YES") : string("NO");
}
