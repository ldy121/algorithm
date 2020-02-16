// Complete the getMinimumCost function below.
int getMinimumCost(int k, vector<int> c) {
    int ret = 0;
    int i = 0, j = 1;

    sort(c.begin(), c.end());
    for (vector<int>::reverse_iterator iter = c.rbegin(); iter != c.rend(); ++iter){
        ret += (j * *iter);
        if ((++i % k) == 0) {
            ++j;
        }
    }

    return ret;
}
