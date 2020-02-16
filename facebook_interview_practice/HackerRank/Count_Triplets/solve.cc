// Complete the countTriplets function below.
typedef unordered_map<long, long>::iterator iteration;

long countTriplets(vector<long> arr, long r) {
    unordered_map<long, long> next_hash;
    unordered_map<long, long> prev_hash;
    long ret = 0;

    for (int i = 0; i < arr.size(); ++i) {
        if (next_hash.find(arr[i]) == next_hash.end()) {
            next_hash[arr[i]] = 1;
        } else {
            ++next_hash[arr[i]];
        }
    }

    for (int i = 0; i < arr.size(); ++i) {
        --next_hash[arr[i]];

        if ((arr[i] % r == 0) && (prev_hash.find(arr[i] / r) != prev_hash.end() &&
            next_hash.find(arr[i] * r) != next_hash.end())) {
            ret += (prev_hash[arr[i] / r] * next_hash[arr[i] * r]);
        }

        if (prev_hash.find(arr[i]) == prev_hash.end()) {
            prev_hash[arr[i]] = 1;
        } else {
            ++prev_hash[arr[i]];
        }
    }    

    return ret;
}
