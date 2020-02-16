#include <bits/stdc++.h>

using namespace std;


// Complete the stepPerms function below.
const long long answer_module = 10000000007;

long long get_answer(vector<long long>&answer, int idx)
{
    long long ret;

    if (idx < answer.size()) {
        if (answer[idx] == 0 ) {
            if ((idx + 1) <= answer.size()) {
                answer[idx] += get_answer(answer, idx + 1);
            }
            if ((idx + 2) <= answer.size()) {
                answer[idx] += get_answer(answer, idx + 2);
            }
            if ((idx + 3) <= answer.size()) {
                answer[idx] += get_answer(answer, idx + 3);
            }
            answer[idx] %= answer_module;
        }
        ret = answer[idx];
    } else {
        ret = 1;
    }

    return ret;
}

int stepPerms(int n) {
    vector<long long> answer(n, 0);
    get_answer(answer, 0);

    return answer[0] % answer_module;
}
