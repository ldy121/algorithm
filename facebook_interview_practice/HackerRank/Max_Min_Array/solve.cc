#include <bits/stdc++.h>

using namespace std;


// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
    int ret = 999999999;
    sort(arr.begin(), arr.end());
    for (int i = 0, j = k - 1; j < arr.size(); ++j, ++i) {
        if ((arr[j] - arr[i]) < ret) {
            ret = arr[j] - arr[i];
        }
    }
    return ret;
}
