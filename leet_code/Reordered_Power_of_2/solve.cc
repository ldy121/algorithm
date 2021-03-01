static set<int> g_answer;

void fillSet(vector<int>& vec, vector<bool>& visited, int num, int count) {
    if (count == vec.size()) {
        g_answer.insert(num);
        return;
    }

    for (int i = 0; i < vec.size(); ++i) {
        if (visited[i]) {
            continue;
        }

        if (count == 0 && vec[i] == 0) {
            continue;
        }

        visited[i] = true;
        fillSet(vec, visited, num * 10 + vec[i], count + 1);
        visited[i] = false;
    }
}

void generate(void) {
    for (int i = 0; i < 30; ++i) {
        vector<int> vec;
        vector<bool> visited;
        for (int j = 1 << i; j > 0; j /= 10) {
            vec.push_back(j % 10);
            visited.push_back(false);
        }
        fillSet(vec, visited, 0, 0);
    }
}


class Solution {
public:
    bool reorderedPowerOf2(int N) {
        if (g_answer.size() == 0) {
            generate();
        }
        return g_answer.find(N) != g_answer.end();
    }
};
