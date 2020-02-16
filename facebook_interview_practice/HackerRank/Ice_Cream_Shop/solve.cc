// Complete the whatFlavors function below.
void whatFlavors(vector<int> cost, int money) {
    unordered_multimap<int, int> hash;
    int i, j;
    for (i = 0; i < cost.size(); ++i) {
        hash.insert(make_pair(cost[i], i));
    }

    for (i = 0, j = -1; (i < cost.size()) && (j == -1); ++i) {
        if (hash.find(money - cost[i]) != hash.end()) {
            pair<unordered_multimap<int, int>::iterator,  unordered_multimap<int, int>::iterator >
                equal_pair = hash.equal_range(money - cost[i]);
            for (unordered_multimap<int, int>::iterator iter = equal_pair.first;
                iter != equal_pair.second; ++iter) {
                if (iter->second != i) {
                    j = iter->second;
                    break;
                }
            }
        }
    }

    cout << (i) << " " << (j + 1) << endl;
}
