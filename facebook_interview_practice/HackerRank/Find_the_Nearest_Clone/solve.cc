#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */
class packet {
    public :
        packet(int src, int dst) : m_src(src), m_dst(dst) {};
        int m_src;
        int m_dst;
};

int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    // solve here
    unordered_map<int, vector<int> > graph;
    vector<int> color(graph_nodes + 1, -1);
    vector<int> set(graph_nodes + 1, -1);
    vector<int> dist(graph_nodes + 1, -1);
    queue<int> q;
    int ret = -1;

    for (int i = 0; i < graph_from.size(); ++i) {
        if (graph.find(graph_from[i]) == graph.end()) {
            vector<int> vec;
            vec.push_back(graph_to[i]);
            graph[graph_from[i]] = vec;
        } else {
            graph[graph_from[i]].push_back(graph_to[i]);
        }

        if (graph.find(graph_to[i]) == graph.end()) {
            vector<int> vec;
            vec.push_back(graph_from[i]);
            graph[graph_to[i]] = vec;
        } else {
            graph[graph_to[i]].push_back(graph_from[i]);
        }
    }

    for (int i = 0; i < ids.size(); ++i) {
        int j = i + 1;
        color[j] = ids[i];
        if ((color[j] == val) && (graph.find(j) != graph.end())) {
            q.push(j);
            set[j] = j;
            dist[j] = 0;
        }
    }

    while ((!q.empty()) && (ret == -1)) {
        for (int size = q.size(); (size > 0) && (ret == -1); --size) {
            int i = q.front();
            q.pop();
            for (int j = 0; (j < graph[i].size()) && (ret == -1); ++j) {
                int k = graph[i][j];
                if (set[k] != -1) {
                    if (set[k] != set[i]) {
                        ret = dist[k] + dist[i] + 1;
                        break;
                    }
                } else {
                    q.push(k);
                    set[k] = set[i];
                    dist[k] = dist[i] + 1;
                }
            }
        }
    }
    return ret;
}
