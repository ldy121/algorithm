static vector<int> g_taskCount;

struct cmp {
    bool operator()(char a, char b) {
        return g_taskCount[a] < g_taskCount[b];
    }
};

class Solution {
private :
    const int maxSize = 256;
    const int invalid = -1;
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<char, vector<char>, cmp> pq;
        vector<int> lastExecute(maxSize, invalid);
        int answer = 0;

        g_taskCount.assign(maxSize, 0);

        for (int i = 0; i < tasks.size(); ++i) {
            ++g_taskCount[tasks[i]];
        }

        for (int i = 0; i < maxSize; ++i) {
            if (g_taskCount[i] > 0) {
                pq.push(i);
            }
        }

        for (answer = 0; !pq.empty(); ++answer) {
            queue<char> buf;

            for (bool done = false; (!done && !pq.empty()); ) {
                char ch = pq.top();
                pq.pop();

                if (lastExecute[ch] == invalid || lastExecute[ch] + n < answer) {
                    lastExecute[ch] = answer;
                    --g_taskCount[ch];
                    done = true;
                }

                if (g_taskCount[ch] > 0) {
                    buf.push(ch);
                }
            }
            while (!buf.empty()) {
                char ch = buf.front();
                buf.pop();
                pq.push(ch);
            }
        }

        return answer;
    }
};
