// Complete the pairs function below.
int pairs(int k, vector<int> arr) {
    unordered_set<int> hash;
    int ret = 0;

    for (int i = 0; i < arr.size(); ++i) {
        hash.insert(arr[i]);
    }

    for (int i = 0; i < arr.size(); ++i) {
        if (hash.find(k + arr[i]) != hash.end()) {
            ++ret;
        }
    }

    return ret;
}
