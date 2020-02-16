// Complete the minimumSwaps function below.
void minimumSwaps(vector<int> q) {
    unordered_map<int, int> hash;
    int swap_count = 0;
    bool chaotic = false;

    for (int j = q.size() - 1; (j > 0) && (chaotic == false); --j) {
        if ((j + 1) == q[j]) continue;
        for (int i = 0; (i < j) && (chaotic == false); ++i) {
            if (q[i + 1] < q[i]) {
                ++swap_count;

                if (hash.find(q[i]) == hash.end()) {
                    hash[q[i]] = 1;
                } else if (++hash[q[i]] > 2) {
                    chaotic = true;
                }

                int tmp = q[i + 1];
                q[i + 1] = q[i];
                q[i] = tmp;
            }
        }
    }

    if (chaotic) {
        cout << "Too chaotic" << endl;
    } else {
        cout << swap_count << endl;
    }
}
