inline long long get_produce(vector<long>& machines, long goal, long days)
{
    long long ret = 0;
    for (int i = 0; i < machines.size(); ++i) {
        ret += (days / machines[i]);
    }
    return ret;
}

long minTime(vector<long> machines, long goal) {
    long ret = 0;
    for (long long high = 100000000000000, low = 1; (ret == 0);) {
        long mid = (low + high) / 2;
        long long product = get_produce(machines, goal, mid);

        if (product == goal) {
            long prev_mid = mid;
            for (long long prev_product = product; prev_product == goal;) {
                mid = prev_mid--;
                prev_product = get_produce(machines, goal, prev_mid);
            }
            ret = mid;
        } else if (goal < product) {
            long long prev_product = get_produce(machines, goal, mid - 1);
            if (prev_product < goal) {
                ret = mid;
            } else {
                high = mid;
            }
        } else {
            low = mid + 1;
        }
    }

    return ret;
}
