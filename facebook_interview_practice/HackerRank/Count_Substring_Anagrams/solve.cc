/*
 * Complete the 'anagramPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
const int max_hash = 26;

int anagramPairs(string s) {
    int ret = 0;
    for (int i = 0; i < s.length(); ++i) {
        for (int j = i + 1; j < s.length(); ++j) {
            vector<int> s1(max_hash, 0);
            vector<int> s2(max_hash, 0);
            for (int k = 0; i + k < j; ++k) {
                int comp;
                ++s1[s[i + k] - 'a'];
                ++s2[s[j - k] - 'a'];
                for (comp = 0; (comp < max_hash) && (s1[comp] == s2[comp]); ++comp);
                if (comp == max_hash) {
                    ++ret;
                }
            }
        }
    }
    return ret;
}
