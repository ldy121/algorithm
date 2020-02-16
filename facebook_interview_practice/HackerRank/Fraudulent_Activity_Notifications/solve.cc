// Complete the activityNotifications function below.
const int max_expenditure = 200;

int activityNotifications(vector<int> expenditure, int d) {
    vector<int> count_sort(max_expenditure + 1, 0);
    int idx, ret = 0;

    for (idx = 0; idx < d; ++idx) {
        ++count_sort[expenditure[idx]];
    }

    while (idx < expenditure.size()) {
        int count = 0;
        int median = 0;
        int prev_median = 0;
        for (median = 0; (median <= max_expenditure); ++median) {
            count += count_sort[median];
            if (count > (d / 2)) {
                if (((d % 2) == 0) && (prev_median > 0)) {
                    median = (median + prev_median);
                } else {
                    median = (median + median);
                }
                break;
            } else if (count == (d / 2)) {
                prev_median = median;
            }
        }
        if (expenditure[idx] >= (median)) ++ret;

        --count_sort[expenditure[idx - d]];
        ++count_sort[expenditure[idx]];

        ++idx;
    }

    return ret;
}
