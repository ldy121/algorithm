#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


// Complete the minTime function below.
inline void swap(vector<vector<int> >& roads, int src, int dst)
{
    for (int i = 0; i < roads[src].size(); ++i) {
        int j = roads[src][i];
        roads[src][i] = roads[dst][i];
        roads[dst][i] = j;
    }
}

void qsort(vector<vector <int> >& roads, int left, int right)
{
    if (left < right) {
        int i, j;
        for (i = left + 1, j = left; i <= right; ++i) {
            if (roads[i][2] > roads[left][2]) {
                swap(roads, i, ++j);
            }
        }
        swap(roads, left, j);
        qsort(roads, left, j - 1);
        qsort(roads, j + 1, right);
    }
}

int minTime(vector<vector<int>> roads, vector<int> machines) {
    vector<int> machine_set_number(roads.size() + 1, 0);
    vector<int> set(roads.size() + 1, -1);
    int sum = 0, taken = 0;

    qsort(roads, 0, roads.size() - 1);

    for (int i = 0; i < machines.size(); ++i) {
        machine_set_number[machines[i]] = 1;
    }

    for (int i = 0; i < roads.size(); ++i) {
        int j, k;
        sum += roads[i][2];
        for (j = roads[i][0]; set[j] != -1; j = set[j]);
        for (k = roads[i][1]; set[k] != -1; k = set[k]);

        if ((machine_set_number[j] + machine_set_number[k]) < 2) {
            int t;
            for (j = roads[i][0]; set[j] != -1; j = t) {
                t = set[j];
                set[j] = k;
            }
            set[j] = k;
            machine_set_number[k] += machine_set_number[j];
            taken += roads[i][2];
        }
    }

    return (sum - taken);
}
