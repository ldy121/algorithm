// Complete the riddle function below.
void sort(vector<long>& arr, vector<int>& vec, int left, int right)
{
    if (left < right) {
        int i, j, k;

        for (i = left + 1, j = left; i <= right; ++i) {
            if (arr[vec[i]] < arr[vec[left]]) {
                ++j;
                k = vec[i];
                vec[i] = vec[j];
                vec[j] = k;
            }
        }

        k = vec[left];
        vec[left] = vec[j];
        vec[j] = k;

        sort(arr, vec, left, j - 1);
        sort(arr, vec, j + 1, right);
    }
}

vector<long> riddle(vector<long> arr) {
    // complete this function
    vector<int> vec;
    vector<long> ret;
    stack<int> sp;

    for (int i = 0; i < arr.size(); ++i) {
        vec.push_back(i);
    }

    sort(arr, vec, 0, vec.size() - 1);

    for (int i = 0; i < arr.size(); ++i) {
        sp.push(vec[i]);
    }

    for (int size = 1, width = 1; size <= arr.size(); ++size) {
        while (width < size) {
            sp.pop();
            width = 1;
            for (int i = sp.top() - 1; i >= 0 && arr[i] >= arr[sp.top()]; --i) ++width;
            for (int i = sp.top() + 1; i < arr.size() && arr[i] >= arr[sp.top()]; ++i) ++width;
        }

        ret.push_back(arr[sp.top()]);
    }

    return ret;
}
