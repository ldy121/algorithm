// Complete the minimumSwaps function below.

int minimumSwaps(vector<int> arr) {
    int answer = 0;

    for (int i = 0; i < arr.size(); ++i) {
        int val = i + 1;
        if (arr[i] != (val)) {
            for (int j = i + 1; j < arr.size(); ++j) {
                if (val == arr[j]) {
                    int k = arr[j];
                    arr[j] = arr[i];
                    arr[i] = k;
                    ++answer;
                    break;
                }
            }
        }
    }
    
    return answer;
}
