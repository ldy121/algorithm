// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
    long ret = 0;
    stack<int> sp;

    for (int i = 0; i < h.size(); ++i) {
        while ((!sp.empty()) && (h[sp.top()] > h[i])) {
            int idx = sp.top();
            long val;

            sp.pop();

            if (sp.empty()) {
                val = i * h[idx];
            } else {
                val = (i - (sp.top() + 1)) * h[idx];
            }

            if (ret < val) {
                ret = val;
            }
        }
        if (sp.empty() || (h[i] >= h[sp.top()])) {
            sp.push(i);
        }
        if (ret < h[i]) {
            ret = h[i];
        }
    }

    while (sp.size() > 1) {
        int idx = sp.top();
        sp.pop();
        long val = h[idx] * (h.size() - (sp.top() + 1));
        if (ret < val) {
            ret = val;
        }
    }

    long val = h[sp.top()] * h.size();
    if (ret < val) {
        ret = val;
    }

    return ret;
}
